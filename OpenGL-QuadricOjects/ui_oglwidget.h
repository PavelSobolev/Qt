/********************************************************************************
** Form generated from reading UI file 'oglwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OGLWIDGET_H
#define UI_OGLWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OglWidget
{
public:

    void setupUi(QWidget *OglWidget)
    {
        if (OglWidget->objectName().isEmpty())
            OglWidget->setObjectName(QString::fromUtf8("OglWidget"));
        OglWidget->resize(691, 614);

        retranslateUi(OglWidget);

        QMetaObject::connectSlotsByName(OglWidget);
    } // setupUi

    void retranslateUi(QWidget *OglWidget)
    {
        OglWidget->setWindowTitle(QApplication::translate("OglWidget", "Form", nullptr));
#ifndef QT_NO_TOOLTIP
        OglWidget->setToolTip(QApplication::translate("OglWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Change the scene parameters using the mouse (left button - rotation, right button and wheel - move)</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        OglWidget->setStatusTip(QApplication::translate("OglWidget", "Change the scene parameters using the mouse (left button - rotation, right button and wheel - move)", nullptr));
#endif // QT_NO_STATUSTIP
    } // retranslateUi

};

namespace Ui {
    class OglWidget: public Ui_OglWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OGLWIDGET_H
