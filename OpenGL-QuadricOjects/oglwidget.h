#ifndef OGLWIDGET_H
#define OGLWIDGET_H

#include <QGLWidget>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QKeyEvent>

#include <GL/glaux.h>

namespace Ui {
    class OglWidget;
}

class OglWidget : public QGLWidget
{
    Q_OBJECT

public:
    explicit OglWidget(QWidget *parent = nullptr);
    ~OglWidget();

    virtual void mousePressEvent(QMouseEvent *pe);
    virtual void mouseReleaseEvent(QMouseEvent *re);
    virtual void wheelEvent(QWheelEvent *we);
    virtual void mouseMoveEvent(QMouseEvent *me);

    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();   

    float sphere_radius;
    int sphere_count1, sphere_count2;

    float disk_radius1, disk_radius2;
    int disk_count1, disk_count2;

    float part_disk_radius1, part_disk_radius2;
    float part_disk_angle1, part_disk_angle2;
    int part_disk_count1, part_disk_count2;

    float cylinder_radius1, cylinder_radius2, cylinder_height;
    int cylinder_count1, cylinder_count2;

    int activeFigure;

    float  rx; // rotation angle around oX
    float  ry; // rotation angle around oY

    float  tx; // value of shift of the origin along oX
    float  ty; // value of shift of the origin along oY
    float  tz;  // value of shift of the origin along oZ

    int mx,my;  // mouse coords

    bool ldown;  // left mouse button is down
    bool rdown; // right mouse button is down

    GLUquadricObj *qobj; // pointer to quadric object (glaux library graphical primitive)

    int drawStyle[4];
    QString s_drawStyle[4];
    int drawNum;

    QString codeCPP; // source code of quadric rendering for showing in the window


private:
    Ui::OglWidget *ui;
};

#endif // OGLWIDGET_H
