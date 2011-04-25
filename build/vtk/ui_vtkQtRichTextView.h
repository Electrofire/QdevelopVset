/********************************************************************************
** Form generated from reading UI file 'vtkQtRichTextView.ui'
**
** Created: Sun Apr 24 16:05:17 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VTKQTRICHTEXTVIEW_H
#define UI_VTKQTRICHTEXTVIEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_vtkQtRichTextView
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *Title;
    QSpacerItem *horizontalSpacer;
    QToolButton *BackButton;
    QToolButton *ForwardButton;
    QToolButton *ZoomIn;
    QToolButton *ZoomReset;
    QToolButton *ZoomOut;
    QWebView *WebView;

    void setupUi(QWidget *vtkQtRichTextView)
    {
        if (vtkQtRichTextView->objectName().isEmpty())
            vtkQtRichTextView->setObjectName(QString::fromUtf8("vtkQtRichTextView"));
        vtkQtRichTextView->resize(400, 300);
        verticalLayout = new QVBoxLayout(vtkQtRichTextView);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Title = new QLabel(vtkQtRichTextView);
        Title->setObjectName(QString::fromUtf8("Title"));

        horizontalLayout->addWidget(Title);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        BackButton = new QToolButton(vtkQtRichTextView);
        BackButton->setObjectName(QString::fromUtf8("BackButton"));
        BackButton->setArrowType(Qt::LeftArrow);

        horizontalLayout->addWidget(BackButton);

        ForwardButton = new QToolButton(vtkQtRichTextView);
        ForwardButton->setObjectName(QString::fromUtf8("ForwardButton"));
        ForwardButton->setArrowType(Qt::RightArrow);

        horizontalLayout->addWidget(ForwardButton);

        ZoomIn = new QToolButton(vtkQtRichTextView);
        ZoomIn->setObjectName(QString::fromUtf8("ZoomIn"));

        horizontalLayout->addWidget(ZoomIn);

        ZoomReset = new QToolButton(vtkQtRichTextView);
        ZoomReset->setObjectName(QString::fromUtf8("ZoomReset"));

        horizontalLayout->addWidget(ZoomReset);

        ZoomOut = new QToolButton(vtkQtRichTextView);
        ZoomOut->setObjectName(QString::fromUtf8("ZoomOut"));

        horizontalLayout->addWidget(ZoomOut);


        verticalLayout->addLayout(horizontalLayout);

        WebView = new QWebView(vtkQtRichTextView);
        WebView->setObjectName(QString::fromUtf8("WebView"));
        WebView->setUrl(QUrl("about:blank"));

        verticalLayout->addWidget(WebView);


        retranslateUi(vtkQtRichTextView);

        QMetaObject::connectSlotsByName(vtkQtRichTextView);
    } // setupUi

    void retranslateUi(QWidget *vtkQtRichTextView)
    {
        vtkQtRichTextView->setWindowTitle(QApplication::translate("vtkQtRichTextView", "Form", 0, QApplication::UnicodeUTF8));
        Title->setText(QString());
#ifndef QT_NO_TOOLTIP
        BackButton->setToolTip(QApplication::translate("vtkQtRichTextView", "Go back one page", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        BackButton->setText(QApplication::translate("vtkQtRichTextView", "Back", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        ForwardButton->setToolTip(QApplication::translate("vtkQtRichTextView", " Go forward one page", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        ForwardButton->setText(QApplication::translate("vtkQtRichTextView", "Forward", 0, QApplication::UnicodeUTF8));
        ZoomIn->setText(QApplication::translate("vtkQtRichTextView", "+", 0, QApplication::UnicodeUTF8));
        ZoomReset->setText(QApplication::translate("vtkQtRichTextView", "100%", 0, QApplication::UnicodeUTF8));
        ZoomOut->setText(QApplication::translate("vtkQtRichTextView", "-", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class vtkQtRichTextView: public Ui_vtkQtRichTextView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VTKQTRICHTEXTVIEW_H
