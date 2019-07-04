#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    //QGL::setPreferredPaintEngine(QPaintEngine::OpenGL2);
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
