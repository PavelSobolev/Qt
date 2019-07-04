#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QGLWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this); 

    qobj = gluNewQuadric();
    qobj1 = gluNewQuadric();
    gluQuadricDrawStyle(qobj,GLU_LINE);
    gluQuadricDrawStyle(qobj1,GLU_FILL);

    radius = 25;
    zmove = -80.0;
    xangle = 0;
    yangle = zangle = 0.0;
    yheight = 40;

    shpereangle = 0.0;
    sphere1_xpos = radius * sin(shpereangle);
    sphere1_ypos = yheight* sin(2*shpereangle)*cos(2*shpereangle);
    sphere1_zpos = radius * cos(shpereangle);

    sphere2_xpos = radius * sin(-shpereangle + M_PI);
    sphere2_ypos = yheight*sin(-2*shpereangle + M_PI)*cos(-2*shpereangle + M_PI);
    sphere2_zpos = radius * cos(-shpereangle + M_PI);

    tmid = startTimer(10);
    motion = true;

    setWindowState(Qt::WindowMaximized);

    full_screen = false;

    mx = 0; // current mouse coords
    my = 0;

    ldown=false; //  left button is held
    rdown=false; //  right button is held

    slide = false;
}

void Widget::mouseDoubleClickEvent(QMouseEvent *dblclk)
{
    if (!full_screen)
        setWindowState(Qt::WindowFullScreen);
    else
        setWindowState(Qt::WindowMaximized);
    full_screen=!full_screen;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initializeGL()
{
    glClearColor(1.0, 1.0 , 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_DOUBLEBUFFER);
    glShadeModel(GL_SMOOTH);
}

void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();

        // calculation of the camera position (it lies on sinusoid and depends on current angle (viewangle))
        float mx = radius * sin(viewangle) - 0.5;
        float my = yheight* sin(2*viewangle)*cos(2*viewangle);
        float mz = radius * cos(viewangle);

        // rotate the camera
        glRotatef(xangle,1.0,0.0,0.0);
        glRotatef(yangle,0.0,1.0,0.0);

        // move the camera to calculated position
        gluLookAt(mx, my, mz, // position
                  0, my ,0,  // point where the camer is directed to
                  0, 1, 0); // up-derction (standard OY axis)

        float x = 0.0, y = 0.0, z = 0.0;
        float ydelta = -2*M_PI;

        glColor3f(1.0,0.0,0.0);
        glLineWidth(2.0);
        glBegin(GL_LINE_LOOP);
        for(float a=0.0; a<=2*M_PI; a+=0.01, ydelta+=0.01)
        {
            x = radius * sin(a);
            y = yheight*sin(2*a)*cos(2*a);
            z = radius * cos(a);
            glVertex3f(x,y,z);
        }
        glEnd(); //кон: вывод синусоиды
        glLineWidth(1.0);


        glColor3f(0.8,0.8,0.8);
        for(float h=-yheight/2; h<=yheight/2; h+=(yheight/5))
        {
            glBegin(GL_LINE_LOOP);
            for(float a=0.0; a<=2*M_PI; a+=0.01)
            {
                x = radius * sin(a);
                y = h;
                z = radius * cos(a);
                glVertex3f(x,y,z);
            }
            glEnd();
        }

        int color_spin = 1;
        for(float a=0.0; a<=2*M_PI; a+=(M_PI/8))
        {
            if (color_spin==1) glColor3f(0.0,0.0,0.8);
            if (color_spin==2) glColor3f(0.0,0.8,0.8);
            if (color_spin==3) glColor3f(0.8,0.0,0.8);
            x = radius * sin(a);
            z = radius * cos(a);            
            glBegin(GL_LINES);
                glVertex3f(x,-yheight/2,z);
                glVertex3f(x,yheight/2,z);
            glEnd();
            if (color_spin<3) color_spin++; else color_spin = 1;
        }


        glPushMatrix();
            glTranslatef(sphere1_xpos, sphere1_ypos, sphere1_zpos);
            glColor3f(0.0,0.0,0.0);
            gluSphere(qobj1,0.3,35,35);
            glColor3f(0.0,1.0,0.0);
            glPushMatrix();
                glRotatef(sphere1_angle, 1.0,1.0,0.0);
                gluSphere(qobj,4.0,35,35);
            glPopMatrix();
        glPopMatrix();


        glPushMatrix();
            glTranslatef(sphere2_xpos, sphere2_ypos, sphere2_zpos);
            glColor3f(0.0,0.0,0.0);
            gluSphere(qobj1,0.3,35,35);
            glColor3f(0.0,0.0,1.0);
            gluSphere(qobj,4.0,35,35);
        glPopMatrix();

    glPopMatrix();
}

void Widget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(60.0, (float)w/h, 0.1, 1000.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Widget::wheelEvent(QWheelEvent *we)
{
    if (slide) return;

    if (we->delta()>0)
        viewangle +=0.01;
    else
        viewangle -=0.01;
    updateGL();
}

void Widget::keyReleaseEvent(QKeyEvent *kre)
{
    if (!slide)
    {
    if (kre->key()==Qt::Key_Up)
        viewangle +=0.01;

    if (kre->key()==Qt::Key_Down)
        viewangle -=0.01;
    }

    if (kre->key()==Qt::Key_S)
    {
        motion = !motion;
        if (!motion)
            killTimer(tmid);
        else
            tmid = startTimer(10);
    }

    if (kre->key()==Qt::Key_M)
    {
        slide=!slide;
        if (slide)
            slideTimer = startTimer(10);
        else
            killTimer(slideTimer);
    }

    updateGL();

    if (!full_screen && kre->key()==Qt::Key_F1)
    {
        QString info_text = "<p>A wired model of cylinder is drawn in the window. "
                            "A sine wave is drawn on the surface of the cylinder. "
                            "Along the trajectory of the sine wave two spheres are moving "
                            "towards each other. One of the spheres is rotating during its motion "
                            "(around the vector(1,1,0)). The camera is placed on the sinusoid line and "
                            "can be moved along this curve. "
                            "The following commands are used to control the scene:"
                "<ul>"
                "<li><b>arrows up/down, mouse wheel</b> - sliding of camera along sinusoid \"upward\" or \"downward\"</li>"
                "<li><b><u>pressed left mouse button</u></b> - changing of angle of the camera direction (you can look at desrided direction)</li>"
                "<li><b>S key</b> - start or stop of spheres movement,</li>"
                "<li><b>M key</b> - start or stop of camera automatic sliding along the sinusoid,</li>"
                "<li><b>double click</b> - full screen mode entering or exiting</li>"
                "</ul>"
                "</p>";

        QMessageBox::information(this, "Help", info_text);
    }
}

void Widget::timerEvent(QTimerEvent *te)
{
    if (te->timerId()==tmid)
    {
        sphere1_xpos = radius * sin(shpereangle);
        sphere1_ypos = yheight*sin(2*shpereangle)*cos(2*shpereangle);
        sphere1_zpos = radius * cos(shpereangle);

        sphere2_xpos = radius * sin(-shpereangle + M_PI);
        sphere2_ypos = yheight*sin(-2*shpereangle + M_PI)*cos(-2*shpereangle + M_PI);
        sphere2_zpos = radius * cos(-shpereangle + M_PI);

        shpereangle += (M_PI/500);

        if (shpereangle>=2*M_PI) shpereangle = 0.0;
        if (sphere1_angle>=360) sphere1_angle = 0; else sphere1_angle++;
    }

    if (te->timerId()==slideTimer)
    {
        if (slide)
            viewangle+=0.01;
        if (viewangle>1000*M_PI) viewangle = 0.0;
    }

    updateGL();
}

void Widget::mousePressEvent(QMouseEvent *pe)
{
    mx=pe->x();
    my=pe->y();

    if (pe->button()==Qt::LeftButton)
        ldown=true;
}

void Widget::mouseReleaseEvent(QMouseEvent *re)
{
    if (re->button()==Qt::LeftButton) ldown=false;
}

void Widget::mouseMoveEvent(QMouseEvent *me)
{
    if (ldown)
    {
        if (xangle>-90 && xangle<90)
        {
            xangle+=0.1*(me->y()-my);
        }
        else
        {
            xangle = (xangle>0)?89:-89;
        }
        if (yangle>-90 && yangle<90)
        {
            yangle+=0.1*(me->x()-mx);

        }
        else
        {
            yangle = (yangle>0)?89:-89;
        }

        mx=me->x();
        my=me->y();
    }

    updateGL();
}
