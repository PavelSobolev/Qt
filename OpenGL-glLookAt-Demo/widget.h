#ifndef WIDGET_H
#define WIDGET_H

#include <QGLWidget>
#include <QTextCodec>
#include <QWheelEvent>
#include <QKeyEvent>
#include <QMessageBox>
#include <cmath>

#include <GL/glaux.h>
#include <GL/glu.h>

namespace Ui {
    class Widget;
}

class Widget : public QGLWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    virtual void initializeGL();
    virtual void paintGL();
    virtual void resizeGL(int w, int h);
    virtual void wheelEvent(QWheelEvent *we);
    virtual void keyReleaseEvent(QKeyEvent *kre);
    virtual void timerEvent(QTimerEvent *te);
    virtual void mousePressEvent(QMouseEvent *e);
    virtual void mouseReleaseEvent(QMouseEvent *);
    virtual void mouseDoubleClickEvent(QMouseEvent *dblclk);
    virtual void mouseMoveEvent(QMouseEvent *e);

    GLUquadricObj *qobj, *qobj1;
    float radius;
    float zmove;
    float xangle, yangle, zangle;
    float yheight;
    float sphere1_xpos,sphere1_ypos,sphere1_zpos;
    int sphere1_angle;
    float sphere2_xpos,sphere2_ypos,sphere2_zpos;
    float shpereangle;

    float viewangle;
    bool full_screen;

    int mx,my;  // mouse coordinates
    bool ldown;
    bool rdown;

    int tmid;
    bool motion;
    bool slide;
    int slideTimer;

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
