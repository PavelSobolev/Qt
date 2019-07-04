#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextCodec>
#include "oglwidget.h"

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
    Ui::MainWindow *ui;
    OglWidget *w;

private slots:
    //void on_verticalSlider_valueChanged(int value);


private slots:
    void on_spinBox_5_valueChanged(int );
    void on_spinBox_6_valueChanged(int );
    void on_doubleSpinBox_10_valueChanged(double );
    void on_doubleSpinBox_5_valueChanged(double );
    void on_doubleSpinBox_4_valueChanged(double );
    void on_doubleSpinBox_8_valueChanged(double );
    void on_doubleSpinBox_9_valueChanged(double );
    void on_spinBox_7_valueChanged(int );
    void on_spinBox_8_valueChanged(int );
    void on_doubleSpinBox_7_valueChanged(double );
    void on_doubleSpinBox_6_valueChanged(double );
    void on_toolBox_currentChanged(int index);
    void on_spinBox_4_valueChanged(int );
    void on_spinBox_3_valueChanged(int );
    void on_doubleSpinBox_3_valueChanged(double );
    void on_doubleSpinBox_2_valueChanged(double );
    void on_spinBox_2_valueChanged(int );
    void on_spinBox_valueChanged(int );
    void on_doubleSpinBox_valueChanged(double );
    void on_listWidget_currentRowChanged(int currentRow);
};

#endif // MAINWINDOW_H
