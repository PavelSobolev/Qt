#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    //QGL::setPreferredPaintEngine(QPaintEngine::OpenGL2);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}