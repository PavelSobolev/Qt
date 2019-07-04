#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // create OpenGL widget and place it in the main window
    w = new OglWidget(ui->widget);
    ui->gridLayout->addWidget(w,0,0,2,1);

    ui->listWidget->setCurrentRow(1);
    ui->textEdit->setText(w->codeCPP);
}

MainWindow::~MainWindow()
{
    delete ui;
}


// set sphere parameters
void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{
    w->drawNum = currentRow;
    w->updateGL();
    ui->textEdit->setText(w->codeCPP);
}

void MainWindow::on_doubleSpinBox_valueChanged(double val)
{
    w->sphere_radius = val;
    w->updateGL();
    ui->textEdit->setText(w->codeCPP);
}

void MainWindow::on_spinBox_valueChanged(int val)
{
    w->sphere_count1 = val;
    w->updateGL();
    ui->textEdit->setText(w->codeCPP);
}

void MainWindow::on_spinBox_2_valueChanged(int val)
{
    w->sphere_count2 = val;
    w->updateGL();
    ui->textEdit->setText(w->codeCPP);
}

// set parameters of circle or disk
void MainWindow::on_doubleSpinBox_2_valueChanged(double val)
{
    w->disk_radius1 = val;
    w->updateGL();
    ui->textEdit->setText(w->codeCPP);
}

void MainWindow::on_doubleSpinBox_3_valueChanged(double val)
{
    w->disk_radius2 = val;
    w->updateGL();
    ui->textEdit->setText(w->codeCPP);
}

void MainWindow::on_spinBox_3_valueChanged(int val)
{
    w->disk_count1 = val;
    w->updateGL();
    ui->textEdit->setText(w->codeCPP);
}

void MainWindow::on_spinBox_4_valueChanged(int val)
{
    w->disk_count2 = val;
    w->updateGL();
    ui->textEdit->setText(w->codeCPP);
}

// choice of active body or figure
void MainWindow::on_toolBox_currentChanged(int index)
{
    w->activeFigure = index;
    w->updateGL();
    ui->textEdit->setText(w->codeCPP);
}


// set parameters of circle or disk sector
void MainWindow::on_doubleSpinBox_6_valueChanged(double val)
{
    w->part_disk_radius1 = val;
    w->updateGL();
    ui->textEdit->setText(w->codeCPP);
}

void MainWindow::on_doubleSpinBox_7_valueChanged(double val)
{
    w->part_disk_radius2 = val;
    w->updateGL();
    ui->textEdit->setText(w->codeCPP);
}

void MainWindow::on_spinBox_8_valueChanged(int val)
{
    w->part_disk_count1 = val;
    w->updateGL();
    ui->textEdit->setText(w->codeCPP);
}

void MainWindow::on_spinBox_7_valueChanged(int val)
{
    w->part_disk_count2 = val;
    w->updateGL();
    ui->textEdit->setText(w->codeCPP);
}

void MainWindow::on_doubleSpinBox_9_valueChanged(double val)
{
    w->part_disk_angle1 = val;
    w->updateGL();
    ui->textEdit->setText(w->codeCPP);
}

void MainWindow::on_doubleSpinBox_8_valueChanged(double val)
{
    w->part_disk_angle2 = val;
    w->updateGL();
    ui->textEdit->setText(w->codeCPP);
}

// set parameters of cone or cylinder
void MainWindow::on_doubleSpinBox_4_valueChanged(double val)
{
    w->cylinder_radius1 = val;
    w->updateGL();
    ui->textEdit->setText(w->codeCPP);
}

void MainWindow::on_doubleSpinBox_5_valueChanged(double val)
{
    w->cylinder_radius2 = val;
    w->updateGL();
    ui->textEdit->setText(w->codeCPP);
}

void MainWindow::on_doubleSpinBox_10_valueChanged(double val)
{
    w->cylinder_height = val;
    w->updateGL();
    ui->textEdit->setText(w->codeCPP);
}

void MainWindow::on_spinBox_6_valueChanged(int val)
{
    w->cylinder_count1 = val;
    w->updateGL();
    ui->textEdit->setText(w->codeCPP);
}

void MainWindow::on_spinBox_5_valueChanged(int val)
{
    w->cylinder_count2 = val;
    w->updateGL();
    ui->textEdit->setText(w->codeCPP);
}
