/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QWidget *widget;
    QGroupBox *infoLabel2;
    QToolBox *toolBox;
    QWidget *page_5;
    QDoubleSpinBox *doubleSpinBox;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QWidget *page_6;
    QSpinBox *spinBox_3;
    QDoubleSpinBox *doubleSpinBox_2;
    QSpinBox *spinBox_4;
    QDoubleSpinBox *doubleSpinBox_3;
    QWidget *page_8;
    QSpinBox *spinBox_7;
    QDoubleSpinBox *doubleSpinBox_6;
    QSpinBox *spinBox_8;
    QDoubleSpinBox *doubleSpinBox_7;
    QDoubleSpinBox *doubleSpinBox_8;
    QDoubleSpinBox *doubleSpinBox_9;
    QWidget *page_7;
    QSpinBox *spinBox_5;
    QDoubleSpinBox *doubleSpinBox_4;
    QSpinBox *spinBox_6;
    QDoubleSpinBox *doubleSpinBox_5;
    QDoubleSpinBox *doubleSpinBox_10;
    QLabel *label;
    QTextEdit *textEdit;
    QListWidget *listWidget;
    QLabel *label_2;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1087, 741);
        MainWindow->setMinimumSize(QSize(1087, 741));
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        action->setCheckable(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/door_close_24.png"), QSize(), QIcon::Normal, QIcon::Off);
        action->setIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));

        gridLayout->addWidget(widget, 0, 0, 1, 1);

        infoLabel2 = new QGroupBox(centralWidget);
        infoLabel2->setObjectName(QString::fromUtf8("infoLabel2"));
        infoLabel2->setMinimumSize(QSize(100, 657));
        infoLabel2->setMaximumSize(QSize(200, 16777215));
        toolBox = new QToolBox(infoLabel2);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(0, 10, 191, 311));
        toolBox->setFrameShape(QFrame::Panel);
        toolBox->setFrameShadow(QFrame::Sunken);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        page_5->setGeometry(QRect(0, 0, 189, 221));
        doubleSpinBox = new QDoubleSpinBox(page_5);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(10, 10, 161, 22));
        doubleSpinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 127);"));
        doubleSpinBox->setDecimals(1);
        doubleSpinBox->setMinimum(0.100000000000000);
        doubleSpinBox->setSingleStep(0.500000000000000);
        doubleSpinBox->setValue(5.500000000000000);
        spinBox = new QSpinBox(page_5);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(10, 40, 161, 22));
        spinBox->setAutoFillBackground(false);
        spinBox->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);"));
        spinBox->setMinimum(2);
        spinBox->setMaximum(150);
        spinBox->setValue(10);
        spinBox_2 = new QSpinBox(page_5);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setGeometry(QRect(10, 70, 161, 22));
        spinBox_2->setAutoFillBackground(false);
        spinBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);"));
        spinBox_2->setMinimum(2);
        spinBox_2->setMaximum(150);
        spinBox_2->setValue(10);
        toolBox->addItem(page_5, QString::fromUtf8("Sphere"));
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        page_6->setGeometry(QRect(0, 0, 189, 221));
        spinBox_3 = new QSpinBox(page_6);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setGeometry(QRect(10, 70, 161, 22));
        spinBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);"));
        spinBox_3->setMinimum(2);
        spinBox_3->setMaximum(100);
        spinBox_3->setValue(10);
        doubleSpinBox_2 = new QDoubleSpinBox(page_6);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setGeometry(QRect(10, 10, 161, 22));
        doubleSpinBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(229, 255, 255);"));
        doubleSpinBox_2->setDecimals(1);
        doubleSpinBox_2->setMinimum(0.000000000000000);
        doubleSpinBox_2->setSingleStep(0.500000000000000);
        doubleSpinBox_2->setValue(4.500000000000000);
        spinBox_4 = new QSpinBox(page_6);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setGeometry(QRect(10, 100, 161, 22));
        spinBox_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);"));
        spinBox_4->setMinimum(2);
        spinBox_4->setMaximum(100);
        spinBox_4->setValue(10);
        doubleSpinBox_3 = new QDoubleSpinBox(page_6);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setGeometry(QRect(10, 40, 161, 22));
        doubleSpinBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(229, 255, 255);"));
        doubleSpinBox_3->setDecimals(1);
        doubleSpinBox_3->setMinimum(0.100000000000000);
        doubleSpinBox_3->setSingleStep(0.500000000000000);
        doubleSpinBox_3->setValue(10.500000000000000);
        toolBox->addItem(page_6, QString::fromUtf8("Disk or circle"));
        page_8 = new QWidget();
        page_8->setObjectName(QString::fromUtf8("page_8"));
        page_8->setGeometry(QRect(0, 0, 189, 221));
        spinBox_7 = new QSpinBox(page_8);
        spinBox_7->setObjectName(QString::fromUtf8("spinBox_7"));
        spinBox_7->setGeometry(QRect(10, 83, 171, 22));
        spinBox_7->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);"));
        spinBox_7->setMinimum(2);
        spinBox_7->setMaximum(100);
        spinBox_7->setValue(10);
        doubleSpinBox_6 = new QDoubleSpinBox(page_8);
        doubleSpinBox_6->setObjectName(QString::fromUtf8("doubleSpinBox_6"));
        doubleSpinBox_6->setGeometry(QRect(10, 0, 171, 22));
        doubleSpinBox_6->setStyleSheet(QString::fromUtf8("background-color: rgb(226, 231, 204);"));
        doubleSpinBox_6->setDecimals(1);
        doubleSpinBox_6->setMinimum(0.000000000000000);
        doubleSpinBox_6->setSingleStep(0.500000000000000);
        doubleSpinBox_6->setValue(4.500000000000000);
        spinBox_8 = new QSpinBox(page_8);
        spinBox_8->setObjectName(QString::fromUtf8("spinBox_8"));
        spinBox_8->setGeometry(QRect(10, 55, 171, 22));
        spinBox_8->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);"));
        spinBox_8->setMinimum(2);
        spinBox_8->setMaximum(100);
        spinBox_8->setValue(10);
        doubleSpinBox_7 = new QDoubleSpinBox(page_8);
        doubleSpinBox_7->setObjectName(QString::fromUtf8("doubleSpinBox_7"));
        doubleSpinBox_7->setGeometry(QRect(10, 27, 171, 22));
        doubleSpinBox_7->setStyleSheet(QString::fromUtf8("background-color: rgb(226, 231, 204);"));
        doubleSpinBox_7->setDecimals(1);
        doubleSpinBox_7->setMinimum(0.100000000000000);
        doubleSpinBox_7->setSingleStep(0.500000000000000);
        doubleSpinBox_7->setValue(6.500000000000000);
        doubleSpinBox_8 = new QDoubleSpinBox(page_8);
        doubleSpinBox_8->setObjectName(QString::fromUtf8("doubleSpinBox_8"));
        doubleSpinBox_8->setGeometry(QRect(10, 133, 171, 22));
        doubleSpinBox_8->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 217, 255);"));
        doubleSpinBox_8->setDecimals(1);
        doubleSpinBox_8->setMinimum(0.000000000000000);
        doubleSpinBox_8->setMaximum(360.000000000000000);
        doubleSpinBox_8->setSingleStep(0.500000000000000);
        doubleSpinBox_8->setValue(270.000000000000000);
        doubleSpinBox_9 = new QDoubleSpinBox(page_8);
        doubleSpinBox_9->setObjectName(QString::fromUtf8("doubleSpinBox_9"));
        doubleSpinBox_9->setGeometry(QRect(10, 108, 171, 22));
        doubleSpinBox_9->setStyleSheet(QString::fromUtf8("background-color: rgb(215, 217, 255);"));
        doubleSpinBox_9->setDecimals(1);
        doubleSpinBox_9->setMinimum(0.000000000000000);
        doubleSpinBox_9->setMaximum(360.000000000000000);
        doubleSpinBox_9->setSingleStep(0.500000000000000);
        doubleSpinBox_9->setValue(90.000000000000000);
        toolBox->addItem(page_8, QString::fromUtf8("Sector of disk or circle"));
        page_7 = new QWidget();
        page_7->setObjectName(QString::fromUtf8("page_7"));
        page_7->setGeometry(QRect(0, 0, 189, 221));
        spinBox_5 = new QSpinBox(page_7);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));
        spinBox_5->setGeometry(QRect(10, 140, 161, 22));
        spinBox_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);"));
        spinBox_5->setMinimum(2);
        spinBox_5->setMaximum(100);
        spinBox_5->setValue(10);
        doubleSpinBox_4 = new QDoubleSpinBox(page_7);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));
        doubleSpinBox_4->setGeometry(QRect(10, 10, 161, 22));
        doubleSpinBox_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 235, 241);"));
        doubleSpinBox_4->setDecimals(1);
        doubleSpinBox_4->setMinimum(0.000000000000000);
        doubleSpinBox_4->setSingleStep(0.500000000000000);
        doubleSpinBox_4->setValue(10.500000000000000);
        spinBox_6 = new QSpinBox(page_7);
        spinBox_6->setObjectName(QString::fromUtf8("spinBox_6"));
        spinBox_6->setGeometry(QRect(10, 110, 161, 22));
        spinBox_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);"));
        spinBox_6->setMinimum(2);
        spinBox_6->setMaximum(100);
        spinBox_6->setValue(10);
        doubleSpinBox_5 = new QDoubleSpinBox(page_7);
        doubleSpinBox_5->setObjectName(QString::fromUtf8("doubleSpinBox_5"));
        doubleSpinBox_5->setGeometry(QRect(10, 40, 161, 22));
        doubleSpinBox_5->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 235, 241);"));
        doubleSpinBox_5->setDecimals(1);
        doubleSpinBox_5->setMinimum(0.000000000000000);
        doubleSpinBox_5->setSingleStep(0.500000000000000);
        doubleSpinBox_5->setValue(10.500000000000000);
        doubleSpinBox_10 = new QDoubleSpinBox(page_7);
        doubleSpinBox_10->setObjectName(QString::fromUtf8("doubleSpinBox_10"));
        doubleSpinBox_10->setGeometry(QRect(10, 70, 161, 22));
        doubleSpinBox_10->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 235, 241);"));
        doubleSpinBox_10->setDecimals(1);
        doubleSpinBox_10->setMinimum(0.100000000000000);
        doubleSpinBox_10->setSingleStep(0.500000000000000);
        doubleSpinBox_10->setValue(5.500000000000000);
        toolBox->addItem(page_7, QString::fromUtf8("Cone or cylinder"));
        label = new QLabel(infoLabel2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 330, 151, 16));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        textEdit = new QTextEdit(infoLabel2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(10, 480, 181, 151));
        QFont font1;
        font1.setPointSize(7);
        textEdit->setFont(font1);
        textEdit->setReadOnly(true);
        listWidget = new QListWidget(infoLabel2);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 350, 181, 101));
        listWidget->setSelectionRectVisible(true);
        label_2 = new QLabel(infoLabel2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 460, 181, 16));
        label_2->setFont(font);

        gridLayout->addWidget(infoLabel2, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1087, 17));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setFocusPolicy(Qt::ClickFocus);
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action);
        menu->addSeparator();
        mainToolBar->addAction(action);

        retranslateUi(MainWindow);
        QObject::connect(action, SIGNAL(triggered()), MainWindow, SLOT(close()));

        listWidget->setCurrentRow(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Quadric objects examples", nullptr));
        action->setText(QApplication::translate("MainWindow", "Quit", nullptr));
#ifndef QT_NO_TOOLTIP
        action->setToolTip(QApplication::translate("MainWindow", "Quit the program", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        action->setStatusTip(QApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\203", nullptr));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_SHORTCUT
        action->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        infoLabel2->setTitle(QString());
        doubleSpinBox->setPrefix(QApplication::translate("MainWindow", "Sphere radius = ", nullptr));
        spinBox->setSuffix(QString());
        spinBox->setPrefix(QApplication::translate("MainWindow", "Slices = ", nullptr));
        spinBox_2->setSuffix(QString());
        spinBox_2->setPrefix(QApplication::translate("MainWindow", "Stacks = ", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_5), QApplication::translate("MainWindow", "Sphere", nullptr));
        spinBox_3->setSuffix(QString());
        spinBox_3->setPrefix(QApplication::translate("MainWindow", "Slices = ", nullptr));
        doubleSpinBox_2->setPrefix(QApplication::translate("MainWindow", "Inner radius = ", nullptr));
        spinBox_4->setSuffix(QString());
        spinBox_4->setPrefix(QApplication::translate("MainWindow", "Stacks = ", nullptr));
        doubleSpinBox_3->setPrefix(QApplication::translate("MainWindow", "Outer radius = ", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_6), QApplication::translate("MainWindow", "Disk or circle", nullptr));
        spinBox_7->setSuffix(QString());
        spinBox_7->setPrefix(QApplication::translate("MainWindow", "Stacks = ", nullptr));
        doubleSpinBox_6->setPrefix(QApplication::translate("MainWindow", "Inner radius = ", nullptr));
        spinBox_8->setSuffix(QString());
        spinBox_8->setPrefix(QApplication::translate("MainWindow", "Slices = ", nullptr));
        doubleSpinBox_7->setPrefix(QApplication::translate("MainWindow", "Outer radius = ", nullptr));
        doubleSpinBox_8->setPrefix(QApplication::translate("MainWindow", "Sweep angle = ", nullptr));
        doubleSpinBox_9->setPrefix(QApplication::translate("MainWindow", "Start angle = ", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_8), QApplication::translate("MainWindow", "Sector of disk or circle", nullptr));
        spinBox_5->setSuffix(QString());
        spinBox_5->setPrefix(QApplication::translate("MainWindow", "Stacks = ", nullptr));
        doubleSpinBox_4->setPrefix(QApplication::translate("MainWindow", "Upper radius = ", nullptr));
        spinBox_6->setSuffix(QString());
        spinBox_6->setPrefix(QApplication::translate("MainWindow", "Slices = ", nullptr));
        doubleSpinBox_5->setPrefix(QApplication::translate("MainWindow", "Lower radius = ", nullptr));
        doubleSpinBox_10->setPrefix(QApplication::translate("MainWindow", "Height = ", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_7), QApplication::translate("MainWindow", "Cone or cylinder", nullptr));
        label->setText(QApplication::translate("MainWindow", "Output", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "Draw points (GLU_POINT)", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "Draw lines    (GLU_LINE)", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MainWindow", "Draw solid    (GLU_FILL)", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        label_2->setText(QApplication::translate("MainWindow", "Source code (C++)", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "Actions", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
