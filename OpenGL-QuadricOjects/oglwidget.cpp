#include "oglwidget.h"
#include "ui_oglwidget.h"

// P. Sobolev - Code for learning course Programming of computer graphics

OglWidget::OglWidget(QWidget *parent) :
    QGLWidget(parent),
    ui(new Ui::OglWidget)
{
    ui->setupUi(this);

    // initial parameters of the scene
    rx = 0;	// rotation angle around oX
    ry = 0;	// rotation angle around oY
    tx = 0;	// shift along oX
    ty = 0;	// shift oY
    tz = -25;	// shift along oZ
    // mouse pointer coord.
    mx = 0;
    my = 0;

    // for handling of mouse events
    ldown=false; // left button is down
    rdown=false; // left btn. si down

    // figures parameters

    sphere_radius = 5.5;
    sphere_count1 = 10;
    sphere_count2 = 10;

    disk_radius1 = 4.5;
    disk_radius2 = 10.5;
    disk_count1 = 10;
    disk_count2 = 10;

    part_disk_radius1 = 4.5;
    part_disk_radius2 = 6.5;
    part_disk_angle1 = 90.0;
    part_disk_angle2 = 270.0;
    part_disk_count1 = 10;
    part_disk_count2 = 10;

    cylinder_radius1 = 10.5;
    cylinder_radius2 = 10.5;
    cylinder_height = 5.5;
    cylinder_count1 = 10;
    cylinder_count2 = 10;

    drawStyle[0] = GLU_POINT;
    drawStyle[1] =  GLU_LINE;
    drawStyle[2] =  GLU_FILL;

    s_drawStyle[0] = "GLU_POINT";
    s_drawStyle[1] =  "GLU_LINE";
    s_drawStyle[2] =  "GLU_FILL";

    drawNum = 1;
    activeFigure = 0;

    setMouseTracking(true);
    qobj = gluNewQuadric();
    //gluQuadricDrawStyle(qobj, GLU_FILL);
}

OglWidget::~OglWidget()
{
    gluDeleteQuadric(qobj);
    delete ui;
}

void OglWidget::initializeGL()
{       
    glClearColor(1.0, 1.0 , 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LINE_SMOOTH);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_NORMALIZE);

    glPointSize(3.0);

    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
}

void OglWidget::resizeGL(int w, int h)
{
    // change parameters of view port
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45, (float)w/h, 0.1, 1000.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void OglWidget::paintGL() //draw the scene using to current values of characteristics
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glPushMatrix();

        //сдвиг по оси OZ для удаления точки обзора
        glTranslatef(tx,ty,tz);		//Переместить и повернуть сцену
        glRotatef(rx, 1, 0, 0);
        glRotatef(ry, 0, 1, 0);

        float l1color[] = {1.0, 1.0, 1.0, 1.0};
        float l1pos[] = {0.0, 100.0, 0.0};
        glLightfv(GL_LIGHT1, GL_POSITION, l1pos);
        glLightfv(GL_LIGHT1, GL_COLOR, l1color);

        glColor3f(0.0, 0.0, 0.9);
        gluQuadricDrawStyle(qobj, drawStyle[drawNum]);

        codeCPP = "GLUquadricObj *qobj;\n\nqobj = gluNewQuadric();\n\ngluQuadricDrawStyle(qobj,\n" +
                  s_drawStyle[drawNum] + ");\n\n";

        switch(activeFigure)
        {
        case 0: gluSphere(qobj, sphere_radius, sphere_count1, sphere_count2);
            codeCPP += QString("gluSphere(qobj, %1,\n   %2, %3);").
                      arg(sphere_radius).arg(sphere_count1).arg(sphere_count2);
            break;
        case 1: gluDisk(qobj,disk_radius1, disk_radius2, disk_count1, disk_count2);
            codeCPP += QString("gluDisk(qobj, %1, %2, %3, %4);").
                      arg(disk_radius1).arg(disk_radius2).arg(disk_count1).arg(disk_count2);
            break;
        case 2: gluPartialDisk(qobj, part_disk_radius1, part_disk_radius2,
                               part_disk_count1, part_disk_count2,part_disk_angle1, part_disk_angle2);
            codeCPP += QString("gluPartialDisk(qobj, %1, %2,\n    %3, %4,\n    %5, %6);").
                    arg(part_disk_radius1).arg(part_disk_radius2).
                    arg(part_disk_count1).arg(part_disk_count2).
                    arg(part_disk_angle1).arg(part_disk_angle2);
            break;
        case 3: gluCylinder(qobj, cylinder_radius1, cylinder_radius2, cylinder_height,
                            cylinder_count1, cylinder_count2);
            codeCPP += QString("gluCylinder(qobj, %1, %2,\n    %3, %4,\n    %5);").
                       arg(cylinder_radius1).arg(cylinder_radius2).
                       arg(cylinder_height).arg(cylinder_count1).arg(cylinder_count2);
            break;
        }

    glPopMatrix();
}

// controlling of the scene by mouse
void OglWidget::mousePressEvent(QMouseEvent *pe)
{
    mx=pe->x();//remeber current coords.
    my=pe->y();

    if (pe->button()==Qt::LeftButton) //rotation
        ldown=true;

    if (pe->button()==Qt::RightButton)	//moving
        rdown=true;
}

void OglWidget::mouseReleaseEvent(QMouseEvent *re)
{
    if (re->button()==Qt::LeftButton) ldown=false;
    if (re->button()==Qt::RightButton) rdown=false;
}

void OglWidget::mouseMoveEvent(QMouseEvent *me)
{
    if (ldown)	// if left btn. is down then calculate rotation parameters
    {
        //changing of scene angle
        rx+=0.1*(me->y()-my);
        ry+=0.1*(me->x()-mx);

        mx=me->x(); //remember current coords.
        my=me->y();
    }

    if (rdown)	// if rght. btn. then calculate movement parameters
    {
        tx+=0.009*(me->x()-mx);
        ty+=0.009*(my-me->y());

        mx=me->x();
        my=me->y();
    }

    updateGL(); // redraw the scene
}

void OglWidget::wheelEvent(QWheelEvent *we) // making origin closer or farther
{
    if (we->delta()>0)
    {
        tz+=0.5;
    }
    else
    {
        tz-=0.5;
    }

    updateGL();
}


