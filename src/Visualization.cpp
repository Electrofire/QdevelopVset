/*
 * THIS CLASS IS NOT FINISHED!!!!!!!!!!
 * THIS CLASS IS NOT FINISHED!!!!!!!!!!
 * THIS CLASS IS NOT FINISHED!!!!!!!!!!
 * THIS CLASS IS NOT FINISHED!!!!!!!!!!
 *
 * Visualization.h
 *
 *  Created on: Mar 25, 2011
 *      Author: Joel
 *
 *  	VISUALIZATION
 *  	This class contains the reference to a Model and the information
 *  	required to generate a visualization.
 *  	This class is parallel to a visualization window.
 *  	Since a single model can be opened in different visualizations
 *  	the class should have a reference to the concrete model and
 *  	have their own specification details.
 *  	This may include but is not restricted to:
 *  		- camera(zoom, position, etc)
 *  		- color scale
 *
 *  4/26/2011: Added render_model() to Visualization
 *
 *  Methods in Visualization:
 *     -renderModel(Model model): Takes any model and creates a visualization
 *        -TkCheckAbort(vtkRenderWindow *renWin):
 *
 *
 */

#include "Visualization.h"

const string COV = "icov";
const string TIME = "time";
const string DUSUM = "dusum";
const string VEL1 = "vel";
const string VEL2 = "velaa";
const string VEL3 = "dvaa";

Visualization::Visualization() {
        // TODO Auto-generated constructor stub
}


Visualization::~Visualization() {
        // TODO Auto-generated destructor stub
}

void Visualization::create_snapshot(vtkRenderer *ren1, const char *image_name) {

        vtkRenderLargeImage *renderLarge;
        renderLarge = vtkRenderLargeImage::New();
        renderLarge->SetInput(ren1);
        renderLarge->SetMagnification(1);

        vtkTIFFWriter *writer = vtkTIFFWriter::New();
        writer->SetInputConnection(renderLarge->GetOutputPort());
        writer->SetFileName(image_name);
        writer->Write();
}


void Visualization::TkCheckAbort(vtkRenderWindow *renWin){
    vtkRenderWindow *tempWin = renWin;
    int foo =renWin->GetEventPending();
    if(foo!= 0){
       if(NULL!=renWin){
       renWin->SetAbortRender(1);
       }
    }
}


//Renders the supplied model, assuming it is a coverage, time, dusum,
//or a type of velocity model supplied
//If statements in code are there for the specific details needed for specific models
void Visualization::render_model(Model* model) {

    // Create the standard renderer, render window
    // and interactor
    string model_name= model->getName();
    vtkRenderer *ren1 = vtkRenderer::New();
    vtkRenderWindow *renWin = vtkRenderWindow::New();
    renWin->AddRenderer(ren1);
    vtkRenderWindowInteractor *iren = vtkRenderWindowInteractor::New();
    iren->SetRenderWindow(renWin);

    // Create the reader for the data
    vtkImageReader *reader = vtkImageReader::New();
    reader->SetFileName(model->getPath().c_str());
    reader->SetDataScalarTypeToUnsignedShort();
    reader->SetDataByteOrderToLittleEndian();
    reader->SetFileDimensionality(3);
    reader->SetNumberOfScalarComponents(1);
    reader->FileLowerLeftOn();
    //#reader->SetDataMask(0x7fff);
    //*********************************************************
    if(model_name.compare(COV) == 0 || model_name.compare(TIME)== 0 || model_name.compare(VEL1)== 0 || model_name.compare(VEL2)== 0 || model_name.compare(VEL3)== 0){
       reader->SetDataOrigin(0, 0, 0);
       reader->SetDataSpacing(1, 1, 1);
     }

    if(model_name.compare(TIME) == 0 ||  model_name.compare(VEL1) == 0 || model_name.compare(VEL2) == 0 || model_name.compare(VEL3)==0) {
       reader->SetDataExtent(0, 230, 0, 25, 0, 68);
    }

    if(model_name.compare(DUSUM) == 0 || model_name.compare(COV) == 0) {
       reader->SetDataExtent(0, 229, 0, 24, 0, 67);
    }

    //*********************************************************
    // Create transfer mapping scalar value to opacity
    vtkPiecewiseFunction *opacityTransferFunction = vtkPiecewiseFunction::New();
    opacityTransferFunction->AddPoint(20, 0.0);
    opacityTransferFunction->AddPoint(255, 0.2);

    // Create transfer mapping scalar value to color
    vtkColorTransferFunction *colorTransferFunction = vtkColorTransferFunction::New();
    //*********************************************************

    if(model_name.compare(COV)==0 || model_name.compare(TIME) == 0 || model_name.compare(VEL1) == 0 || model_name.compare(VEL2) == 0 || model_name.compare(VEL3) == 0) {
       colorTransferFunction->AddRGBPoint(0.0, 1.0, 0.0, 0.0);
       colorTransferFunction->AddRGBPoint(30315.0, 0.0, 0.0, 1.0);
    }

    if(model_name.compare(DUSUM) == 0) {
        colorTransferFunction->AddRGBPoint(11950.0, 1.0, 0.0, 0.0);
        colorTransferFunction->AddRGBPoint(12025.0, 0.0, 0.0, 1.0);
    }

    //*********************************************************
    //The property describes how the data will look
    vtkVolumeProperty *volumeProperty = vtkVolumeProperty::New();
    volumeProperty->SetColor(colorTransferFunction);
    volumeProperty->SetScalarOpacity(opacityTransferFunction);
    if(model_name.compare(COV) == 0) {
       colorTransferFunction->AddRGBPoint(0.0, 0.0, 0.0, 0.0);
       colorTransferFunction->AddRGBPoint(64.0, 1.0, 0.0, 0.0);
       colorTransferFunction->AddRGBPoint(128.0, 0.0, 0.0, 0.0);
       colorTransferFunction->AddRGBPoint(192.0, 0.0, 0.0, 0.0);
       colorTransferFunction->AddRGBPoint(255.0, 0.0, 0.0, 0.0);
    }
    volumeProperty->ShadeOn();
    volumeProperty->SetInterpolationTypeToLinear();

    //###########################################################
    //*********************************************************
    // Create five surfaces F(x,y,z) = constant between range specified. The
    // GenerateValues() method creates n isocontour values between the range
    // specified.

    //renderVel, renderTime, renderDusum
    vtkContourFilter *contours = vtkContourFilter::New();
    if(model_name.compare(TIME) == 0 || model_name.compare(DUSUM) == 0 || model_name.compare(VEL1) == 0 || model_name.compare(VEL2) == 0 || model_name.compare(VEL3) == 0) {
        contours->SetInput(reader->GetOutput());
    }

    vtkPolyDataMapper *contMapper = vtkPolyDataMapper::New();
    //renderVel, renderTime
    if(model_name.compare(TIME) == 0 || model_name.compare(VEL1) == 0 || model_name.compare(VEL2) == 0 || model_name.compare(VEL3) == 0) {
       contours->GenerateValues(30, 0.0, 30315.0);

       contMapper->SetInput(contours->GetOutput());
       contMapper->SetScalarRange(0.0, 30315.0);
     }

    //renderDusum
    if(model_name.compare(DUSUM) == 0) {
       contours->GenerateValues(40, 11950.0, 12025.0);

       contMapper->SetInput(contours->GetOutput());
       contMapper->SetScalarRange(11950.0, 12025.0);
    }
    //*********************************************************
    vtkActor *contActor = vtkActor::New();
    contActor->SetMapper(contMapper);

    // We'll put a simple outline around the data.
    vtkOutlineFilter *outline = vtkOutlineFilter::New();
    outline->SetInput(reader->GetOutput());

    vtkPolyDataMapper *outlineMapper = vtkPolyDataMapper::New();
    outlineMapper->SetInput(outline->GetOutput());

    vtkActor *outlineActor = vtkActor::New();
    outlineActor->SetMapper(outlineMapper);
    //*********************************************************

    if(model_name.compare(TIME) == 0) {
       (outlineActor->GetProperty())->SetColor(0, 0, 0);
    }

    //##########################################################
    //The mapper / ray cast function know how to render the data
    //renderCoverage, renderDusum, renderVel
    vtkVolumeRayCastMapper *volumeMapper = vtkVolumeRayCastMapper::New();
    if(model_name.compare(COV) == 0 || model_name.compare(DUSUM) == 0 || model_name.compare(VEL1) == 0 || model_name.compare(VEL2) == 0 || model_name.compare(VEL3) == 0) {
       vtkVolumeRayCastCompositeFunction *compositeFunction = vtkVolumeRayCastCompositeFunction::New();

       volumeMapper->SetVolumeRayCastFunction(compositeFunction);
       volumeMapper->SetInputConnection(reader->GetOutputPort());

    // The volume holds the mapper and the property and
    // can be used to position/orient the volume
    }

    //renderTime

    else{
       vtkSmartPointer<vtkVolumeRayCastMapper> volumeMapper = vtkSmartPointer<vtkVolumeRayCastMapper>::New();
       vtkSmartPointer<vtkVolumeRayCastCompositeFunction> compositeFunction = vtkSmartPointer<vtkVolumeRayCastCompositeFunction>::New();
       volumeMapper->SetVolumeRayCastFunction(compositeFunction);
       volumeMapper->SetInputConnection(reader->GetOutputPort());

    //The volume holds the mapper and the property and
    //can be used to position/orient the volume
    }
    vtkVolume *volume = vtkVolume::New();

    //*********************************************************
    volume->SetMapper(volumeMapper);
    volume->SetProperty(volumeProperty);
    volume->RotateX(90);
    contActor->RotateX(90);
    outlineActor->RotateX(90);
    ren1->AddVolume(volume);

    ren1->SetBackground(1, 1, 1);
    ren1->AddActor(contActor);
    ren1->AddActor(outlineActor);
    renWin->SetSize(600, 600);

    renWin->Render();

    TkCheckAbort(renWin);

    iren->Initialize();
    iren->Start();
    //create_snapshot(ren1, "caca");
    //*********************************************************

}
