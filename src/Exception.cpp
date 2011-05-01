/**
 * Cesar Chacon
 * Exception class abstracting the QMessage Box
 */
#include "Exception.h"

//Default constructor
Exception::Exception()
{
	message = "";
	icon = 0;//no icon as default
}
//Default destructor
Exception::~Exception()
{

}
void Exception::setMessage(string msg){
	message = msg;

}

void Exception::setTitle(string title){
	exceptionTitle = title;

}

void Exception::setIcon (int iconType){
	this->icon = iconType;
	
}

void Exception::show(){
	
	
	switch(icon){
		case QMessageBox::NoIcon:
		mbox.setIcon(QMessageBox::NoIcon);
			break;
		case QMessageBox::Question:
		mbox.setIcon(QMessageBox::Question);
			break;
		case QMessageBox::Information:
		mbox.setIcon(QMessageBox::Information);
			break;	
		case QMessageBox::Warning:
		mbox.setIcon(QMessageBox::Warning);
			break;
		case QMessageBox::Critical:
		mbox.setIcon(QMessageBox::Critical);
			break;
		default:
			mbox.setIcon(QMessageBox::NoIcon);
			break;
	}

 mbox.setText(QString::fromStdString(message));
 mbox.setInformativeText(QString::fromStdString(exceptionTitle));
 mbox.setStandardButtons(QMessageBox::Ok);
 mbox.setDefaultButton(QMessageBox::Ok);
 int ret = mbox.exec();
	
}