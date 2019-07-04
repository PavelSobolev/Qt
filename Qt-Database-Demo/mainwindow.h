#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>

#include <QMainWindow>
#include <QMessageBox>
#include <QDateTime>

#include <QList>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

#include <QMap>
#include <QLabel>

#include <QTableWidgetItem>
#include <QThread>

#include <QKeyEvent>

#include "cell.h"
#include "celllabel.h"

/*class Cell // table's cell
{
public:
    int zanId;
    int grId;
    int facultId;
    int predmId;
    int prepodId;
    int vzId;
    int kabId;
    int day;
    int mon;
    int year;
    int para;
    Cell()
    {
        facultId = 7;
        zanId = 0;
        grId = 0;
        predmId = 0;
        prepodId = 0;
        vzId = 0;
        kabId = 0;
        day = 0;
        mon = 0;
        year = 0;
        para = 0;
    }
};

class CellLabel : public QLabel // model of text in the cell
{
    Q_OBJECT
public:
    Cell RaspData;
    explicit CellLabel(QWidget *parent = nullptr);
};*/

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    const int UchNumberDefault = 13;
    QMap<QTableWidgetItem, Cell> RaspData;

    bool initDB();
    void initUI();
    void fill_date_list();
    void fill_predm_list(int id);
    void fill_kab_list();
    void fill_vidzan_list();
    void fill_rasp_table();

    int getColnumByDate(QDate D);
    int get_current_date_listnumber();
    void selectZanData(Cell C);

    int UchGodId;

    QSqlDatabase connection;
    QString conData;

    QSqlQuery *groups;
    QSqlQuery *predms;
    QSqlQuery *vidzans;
    QSqlQuery *kabins;
    QSqlQuery *rasp;

    QList<QDate> starts, ends;
    void keyReleaseEvent(QKeyEvent *event);

private slots:
    void on_grList_currentRowChanged(int currentRow);

    void on_week_list_currentIndexChanged(int index);

    void on_rasp_cellDoubleClicked(int row, int column);

    void on_rasp_cellPressed(int row, int column);

    void on_rasp_itemClicked(QTableWidgetItem *item);

    void on_action_triggered();

    void on_action_2_triggered();

    void on_action_3_triggered();

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
