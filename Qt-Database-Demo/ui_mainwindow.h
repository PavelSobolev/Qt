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
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_3;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QListWidget *grList;
    QListWidget *predmList;
    QListWidget *vidZanList;
    QListWidget *kabList;
    QComboBox *week_list;
    QTableWidget *rasp;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1210, 692);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/files/main.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        action = new QAction(MainWindow);
        action->setObjectName(QString::fromUtf8("action"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/files/update.png"), QSize(), QIcon::Normal, QIcon::Off);
        action->setIcon(icon1);
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_2->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/files/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_2->setIcon(icon2);
        action_3 = new QAction(MainWindow);
        action_3->setObjectName(QString::fromUtf8("action_3"));
        action_3->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/files/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_3->setIcon(icon3);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        grList = new QListWidget(centralWidget);
        grList->setObjectName(QString::fromUtf8("grList"));
        QFont font;
        font.setPointSize(10);
        grList->setFont(font);

        horizontalLayout->addWidget(grList);

        predmList = new QListWidget(centralWidget);
        predmList->setObjectName(QString::fromUtf8("predmList"));
        predmList->setFont(font);

        horizontalLayout->addWidget(predmList);

        vidZanList = new QListWidget(centralWidget);
        vidZanList->setObjectName(QString::fromUtf8("vidZanList"));
        vidZanList->setFont(font);

        horizontalLayout->addWidget(vidZanList);

        kabList = new QListWidget(centralWidget);
        kabList->setObjectName(QString::fromUtf8("kabList"));
        kabList->setFont(font);

        horizontalLayout->addWidget(kabList);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 6);
        horizontalLayout->setStretch(2, 2);
        horizontalLayout->setStretch(3, 1);

        verticalLayout->addLayout(horizontalLayout);

        week_list = new QComboBox(centralWidget);
        week_list->setObjectName(QString::fromUtf8("week_list"));
        week_list->setFont(font);

        verticalLayout->addWidget(week_list);


        verticalLayout_2->addLayout(verticalLayout);

        rasp = new QTableWidget(centralWidget);
        if (rasp->columnCount() < 7)
            rasp->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        rasp->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        rasp->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        rasp->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        rasp->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        rasp->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        rasp->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        rasp->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        if (rasp->rowCount() < 7)
            rasp->setRowCount(7);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        rasp->setVerticalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        rasp->setVerticalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        rasp->setVerticalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        rasp->setVerticalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        rasp->setVerticalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        rasp->setVerticalHeaderItem(5, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        rasp->setVerticalHeaderItem(6, __qtablewidgetitem13);
        rasp->setObjectName(QString::fromUtf8("rasp"));
        rasp->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        rasp->setEditTriggers(QAbstractItemView::NoEditTriggers);
        rasp->setAlternatingRowColors(true);
        rasp->setWordWrap(true);

        verticalLayout_2->addWidget(rasp);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 3);

        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1210, 18));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(action);
        toolBar->addAction(action_2);
        toolBar->addAction(action_3);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\240\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\267\320\260\320\275\321\217\321\202\320\270\320\271 \320\241\320\260\321\205\320\223\320\242\320\230", nullptr));
        action->setText(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214", nullptr));
#ifndef QT_NO_TOOLTIP
        action->setToolTip(QApplication::translate("MainWindow", "\320\236\320\261\320\275\320\276\320\262\320\270\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203 \321\200\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\321\217", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        action->setShortcut(QApplication::translate("MainWindow", "F5", nullptr));
#endif // QT_NO_SHORTCUT
        action_2->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\266\320\270\320\274 \321\200\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
#ifndef QT_NO_TOOLTIP
        action_2->setToolTip(QApplication::translate("MainWindow", "\320\222\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265 \320\270\320\273\320\270 \320\276\321\202\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265 \321\200\320\265\320\266\320\270\320\274\320\260 \321\200\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217 \321\200\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\321\217", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        action_2->setShortcut(QApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_NO_SHORTCUT
        action_3->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\320\275\321\217\321\202\320\270\320\265", nullptr));
#ifndef QT_NO_TOOLTIP
        action_3->setToolTip(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\267\320\260\320\275\321\217\321\202\320\270\320\265", nullptr));
#endif // QT_NO_TOOLTIP
        QTableWidgetItem *___qtablewidgetitem = rasp->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = rasp->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = rasp->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = rasp->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = rasp->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = rasp->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = rasp->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = rasp->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "1 \320\277\320\260\321\200\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = rasp->verticalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "2 \320\277\320\260\321\200\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = rasp->verticalHeaderItem(2);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "3 \320\277\320\260\321\200\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = rasp->verticalHeaderItem(3);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "4 \320\277\320\260\321\200\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = rasp->verticalHeaderItem(4);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "5 \320\277\320\260\321\200\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = rasp->verticalHeaderItem(5);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "6 \320\277\320\260\321\200\320\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = rasp->verticalHeaderItem(6);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "7 \320\277\320\260\321\200\320\260", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
