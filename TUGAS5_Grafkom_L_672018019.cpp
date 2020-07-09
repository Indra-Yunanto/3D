#include <windows.h>
#include <gl/glut.h>

void init(void);
void tampil(void);
void keyboard(unsigned,char,int,int);
void ukuran(int,int);

void mouse(int button, int state, int x, int y); //fungsi mouse
void ukuran(int, int);
void mouseMotion(int x, int y); //fungsi mouse

float xrot = 0.0f; //fungsi mouse
float yrot = 0.0f; //fungsi mouse
float xdiff = 0.0f; //fungsi mouse
float ydiff = 0.0f; //fungsi mouse

bool mouseDown = false; //fungsi mouse

int is_depth;


void init(void)
{
    glClearColor(0.0,0.0,0.0,0.0);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(8.0);
    glLineWidth(1.0f);
}

void tampil(void)
{
    glPushMatrix();
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    gluLookAt(0.0f,0.0f,3.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);//mengatur penglihatan mata/penglihatan objek
    glRotatef(xrot,1.0f,0.0f,0.0f);
    glRotatef(yrot,0.0f,1.0f,0.0f);

    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);

    //base
    glBegin(GL_QUADS);
    glColor3f(34/255.0f,139/255.0f,34/255.0f);
    glVertex3f(-50,-20.1,50);
    glVertex3f(50,-20.1,50);
    glVertex3f(50,-20.1,-50);
    glVertex3f(-50,-20.1,-50);
    glEnd();

    //rumah depan 1 a
    glBegin(GL_QUADS);
    glColor3f(0.8,1,0.2);
    glVertex3f(-30,-20,30);
    glVertex3f(-30,20,30);
    glVertex3f(-15,20,30);
    glVertex3f(-15,-20,30);
    glEnd();

    //rumah depan 1 b
    glBegin(GL_QUADS);
    glColor3f(0.8,1,0.2);
    glVertex3f(-4,-20,30);
    glVertex3f(-4,20,30);
    glVertex3f(-0,20,30);
    glVertex3f(-0,-20,30);
    glEnd();

    //rumah depan 1 c
    glBegin(GL_QUADS);
    glColor3f(0.8,1,0.2);
    glVertex3f(-15,10,30);
    glVertex3f(-15,20,30);
    glVertex3f(-4,20,30);
    glVertex3f(-4,10,30);
    glEnd();

    //rumah depan 1 d
    glBegin(GL_QUADS);
    glColor3f(0.8,1,0.2);
    glVertex3f(-15,-20,30);
    glVertex3f(-15,0,30);
    glVertex3f(-4,0,30);
    glVertex3f(-4,-20,30);
    glEnd();

    //jendela depan
    glBegin(GL_QUADS);
    glColor4f(1.0f, 1.0f, 1.0f, 1);
    glVertex3f(-15,0,30);
    glVertex3f(-15,10,30);
    glVertex3f(-4,10,30);
    glVertex3f(-4,0,30);
    glEnd();

    //bingkai
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glLineWidth(9.0f);
    glVertex3f(-15,0,30.1);
    glVertex3f(-15,10,30.1);
    glVertex3f(-4,10,30.1);
    glVertex3f(-4,0,30.1);
    glEnd();

    //bingkai
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glLineWidth(9.0f);
    glVertex3f(-15,0,29.9);
    glVertex3f(-15,10,29.9);
    glVertex3f(-4,10,29.9);
    glVertex3f(-4,0,29.9);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
    glLineWidth(9.0f);
    glVertex3f(-9.5,0,30.1);
    glVertex3f(-9.5,10,30.1);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
    glLineWidth(9.0f);
    glVertex3f(-9.5,0,29.9);
    glVertex3f(-9.5,10,29.9);
    glEnd();

    //rumah depan 2
    glBegin(GL_QUADS);
    glColor3f(0.8,0.9,0.4);
    glVertex3f(0,-20,30);
    glVertex3f(0,20,30);
    glVertex3f(0,20,10);
    glVertex3f(0,-20,10);
    glEnd();

    //rumah depan 3 a
    glBegin(GL_QUADS);
    glColor3f(0.8,1,0.7);
    glVertex3f(0,-20,10);
    glVertex3f(0,20,10);
    glVertex3f(10,20,10);
    glVertex3f(10,-20,10);
    glEnd();

    //rumah depan 3 b
    glBegin(GL_QUADS);
    glColor3f(0.8,1,0.7);
    glVertex3f(20,-20,10);
    glVertex3f(20,20,10);
    glVertex3f(30,20,10);
    glVertex3f(30,-20,10);
    glEnd();

    //rumah depan 3 a
    glBegin(GL_QUADS);
    glColor3f(0.8,1,0.7);
    glVertex3f(10,10,10);
    glVertex3f(10,20,10);
    glVertex3f(20,20,10);
    glVertex3f(20,10,10);
    glEnd();

    //pintu
    glBegin(GL_QUADS);
    glColor3f(0.6,0.3,0);
    glVertex3f(10,-20,10);
    glVertex3f(10,10,10);
    glVertex3f(20,10,10);
    glVertex3f(20,-20,10);
    glEnd();

    //gagang 1
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(11,-5,10.5);
    glVertex3f(11,-1,10.5);
    glVertex3f(12,-1,10.5);
    glVertex3f(12,-5,10.5);
    glEnd();

    //gagang 2
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(11,-5,10.5);
    glVertex3f(11,-1,10.5);
    glVertex3f(11,-1,10);
    glVertex3f(11,-5,10);
    glEnd();

    //gagang 3
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(12,-5,10.5);
    glVertex3f(12,-1,10.5);
    glVertex3f(12,-1,10);
    glVertex3f(12,-5,10);
    glEnd();

    //gagang 4
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(11,-1,10.5);
    glVertex3f(12,-1,10.5);
    glVertex3f(12,-1,10);
    glVertex3f(11,-1,10);
    glEnd();

    //gagang 4
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(11,-5,10.5);
    glVertex3f(12,-5,10.5);
    glVertex3f(12,-5,10);
    glVertex3f(11,-5,10);
    glEnd();




    //rumah belakang 1
    glBegin(GL_QUADS);
    glColor3f(0.8,1,0.2);
    glVertex3f(-30,-20,-30);
    glVertex3f(-30,20,-30);
    glVertex3f(-25,20,-30);
    glVertex3f(-25,-20,-30);
    glEnd();

    //rumah belakang 2
    glBegin(GL_QUADS);
    glColor3f(0.8,1,0.2);
    glVertex3f(-10,-20,-30);
    glVertex3f(-10,20,-30);
    glVertex3f(30,20,-30);
    glVertex3f(30,-20,-30);
    glEnd();

    //rumah belakang 3
    glBegin(GL_QUADS);
    glColor3f(0.8,1,0.2);
    glVertex3f(-25,10,-30);
    glVertex3f(-25,20,-30);
    glVertex3f(-10,20,-30);
    glVertex3f(-10,10,-30);
    glEnd();

    //rumah belakang 4
    glBegin(GL_QUADS);
    glColor3f(0.8,1,0.2);
    glVertex3f(-25,-20,-30);
    glVertex3f(-25,0,-30);
    glVertex3f(-10,0,-30);
    glVertex3f(-10,-20,-30);
    glEnd();

    //jendela belakang
    glBegin(GL_QUADS);
    glColor3f(0.7,0.7,0.7);
    glVertex3f(-25,0,-30);
    glVertex3f(-25,10,-30);
    glVertex3f(-10,10,-30);
    glVertex3f(-10,0,-30);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
    glLineWidth(9.0f);
    glVertex3f(-17.5,0,-30.1);
    glVertex3f(-17.5,10,-30.1);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
    glLineWidth(9.0f);
    glVertex3f(-17.5,0,-29.9);
    glVertex3f(-17.5,10,-29.9);
    glEnd();

    //bingkai
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glLineWidth(9.0f);
    glVertex3f(-25,0,-30.1);
    glVertex3f(-25,10,-30.1);
    glVertex3f(-10,10,-30.1);
    glVertex3f(-10,0,-30.1);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glLineWidth(9.0f);
    glVertex3f(-25,0,-29.9);
    glVertex3f(-25,10,-29.9);
    glVertex3f(-10,10,-29.9);
    glVertex3f(-10,0,-29.9);
    glEnd();

    //rumah kanan 1
    glBegin(GL_QUADS);
    glColor3f(0.8,1,0.6);
    glVertex3f(30,20,10);
    glVertex3f(30,-20,10);
    glVertex3f(30,-20,-10);
    glVertex3f(30,20,-10);
    glEnd();

    //rumah kanan 2
    glBegin(GL_QUADS);
    glColor3f(0.8,1,0.6);
    glVertex3f(30,20,- 25);
    glVertex3f(30,-20,-25);
    glVertex3f(30,-20,-30);
    glVertex3f(30,20,-30);
    glEnd();

    //rumah kanan 3
    glBegin(GL_QUADS);
    glColor3f(0.8,1,0.6);
    glVertex3f(30,20,-10);
    glVertex3f(30,10,-10);
    glVertex3f(30,10,-25);
    glVertex3f(30,20,-25);
    glEnd();

    //rumah kanan 4
    glBegin(GL_QUADS);
    glColor3f(0.8,1,0.6);
    glVertex3f(30,0,-10);
    glVertex3f(30,-20,-10);
    glVertex3f(30,-20,-25);
    glVertex3f(30,0,-25);
    glEnd();

    //jendela kanan
     glBegin(GL_QUADS);
    glColor3f(0.7,0.7,0.7);
    glVertex3f(30,0,-10);
    glVertex3f(30,10,-10);
    glVertex3f(30,10,-25);
    glVertex3f(30,0,-25);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
    glLineWidth(9.0f);
    glVertex3f(30.1,0,-17.5);
    glVertex3f(30.1,10,-17.5);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
    glLineWidth(9.0f);
    glVertex3f(29.9,0,-17.5);
    glVertex3f(29.9,10,-17.5);
    glEnd();

    //bingkai
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glLineWidth(9.0f);
    glVertex3f(30.1,0,-10);
    glVertex3f(30.1,10,-10);
    glVertex3f(30.1,10,-25);
    glVertex3f(30.1,0,-25);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glLineWidth(9.0f);
    glVertex3f(29.9,0,-10);
    glVertex3f(29.9,10,-10);
    glVertex3f(29.9,10,-25);
    glVertex3f(29.9,0,-25);
    glEnd();

    //rumah kiri 1
    glBegin(GL_QUADS);
    glColor3f(0.8,1,0.7);
    glVertex3f(-30,20,30);
    glVertex3f(-30,-20,30);
    glVertex3f(-30,-20,-10);
    glVertex3f(-30,20,-10);
    glEnd();

    //rumah kiri 2
    glBegin(GL_QUADS);
    glColor3f(0.8,1,0.7);
    glVertex3f(-30,20,- 25);
    glVertex3f(-30,-20,-25);
    glVertex3f(-30,-20,-30);
    glVertex3f(-30,20,-30);
    glEnd();

    //rumah kiri 3
    glBegin(GL_QUADS);
    glColor3f(0.8,1,0.7);
    glVertex3f(-30,20,-10);
    glVertex3f(-30,10,-10);
    glVertex3f(-30,10,-25);
    glVertex3f(-30,20,-25);
    glEnd();

    //rumah kiri 4
    glBegin(GL_QUADS);
    glColor3f(0.8,1,0.7);
    glVertex3f(-30,0,-10);
    glVertex3f(-30,-20,-10);
    glVertex3f(-30,-20,-25);
    glVertex3f(-30,0,-25);
    glEnd();

    //jendela kiri
     glBegin(GL_QUADS);
    glColor3f(0.7,0.7,0.7);
    glVertex3f(-30,0,-10);
    glVertex3f(-30,10,-10);
    glVertex3f(-30,10,-25);
    glVertex3f(-30,0,-25);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
    glLineWidth(9.0f);
    glVertex3f(-30.1,0,-17.5);
    glVertex3f(-30.1,10,-17.5);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
    glLineWidth(9.0f);
    glVertex3f(-29.9,0,-17.5);
    glVertex3f(-29.9,10,-17.5);
    glEnd();

    //bingkai
    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glLineWidth(9.0f);
    glVertex3f(-30.1,0,-10);
    glVertex3f(-30.1,10,-10);
    glVertex3f(-30.1,10,-25);
    glVertex3f(-30.1,0,-25);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0,0,0);
    glLineWidth(9.0f);
    glVertex3f(-29.9,0,-10);
    glVertex3f(-29.9,10,-10);
    glVertex3f(-29.9,10,-25);
    glVertex3f(-29.9,0,-25);
    glEnd();


    //rumah Atas
    glBegin(GL_QUADS);
    glColor3f(0.6,0.3,0.2);
    glVertex3f(-35,20,35);
    glVertex3f(35,20,35);
    glVertex3f(35,20,-35);
    glVertex3f(-35,20,-35);
    glEnd();

    //rumahbawah
    glBegin(GL_QUADS);
    glColor3f(1,1,0.8);
    glVertex3f(-30,-20,30);
    glVertex3f(30,-20,30);
    glVertex3f(30,-20,-30);
    glVertex3f(-30,-20,-30);
    glEnd();

    //atap depan
    glBegin(GL_POLYGON);
    glColor3f(0.7,0.4,0);
    glVertex3f(-35,20,35);
    glVertex3f(35,20,35);
    glVertex3f(0,40,10);
    glEnd();

    //atap belakang
    glBegin(GL_POLYGON);
    glColor3f(0.7,0.4,0);
    glVertex3f(-35,20,-35);
    glVertex3f(35,20,-35);
    glVertex3f(0,40,-10);
    glEnd();

    //atap kanan
    glBegin(GL_POLYGON);
    glColor3f(0.9,0.5,0);
    glVertex3f(35,20,35);
    glVertex3f(0,40,10);
    glVertex3f(0,40,-10);
    glVertex3f(35,20,-35);
    glEnd();

    //atap kiri
    glBegin(GL_POLYGON);
    glColor3f(0.9,0.5,0);
    glVertex3f(-35,20,35);
    glVertex3f(0,40,10);
    glVertex3f(0,40,-10);
    glVertex3f(-35,20,-35);
    glEnd();

    //pilar depan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(27,-20,30);
    glVertex3f(30,-20,30);
    glVertex3f(30,20,30);
    glVertex3f(27,20,30);
    glEnd();

    //pilar belakang
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(27,-20,27);
    glVertex3f(30,-20,27);
    glVertex3f(30,20,27);
    glVertex3f(27,20,27);
    glEnd();

    //pilar kiri
    glBegin(GL_QUADS);
    glColor3f(0.7,0.7,0.7);
    glVertex3f(27,-20,30);
    glVertex3f(27,-20,27);
    glVertex3f(27,20,27);
    glVertex3f(27,20,30);
    glEnd();

    //pilar kanan
    glBegin(GL_QUADS);
    glColor3f(0.7,0.7,0.7);
    glVertex3f(30,-20,30);
    glVertex3f(30,-20,27);
    glVertex3f(30,20,27);
    glVertex3f(30,20,30);
    glEnd();

    //Furnitur Rumah

    //Kasur
    //base kasur belakang
    glBegin(GL_QUADS);
    glColor3f(0.6,0.3,0);
    glVertex3f(-29,-20,-29);
    glVertex3f(-14,-20,-29);
    glVertex3f(-14,-15,-29);
    glVertex3f(-29,-15,-29);
    glEnd();

    //base kasur depan
    glBegin(GL_QUADS);
    glColor3f(0.6,0.3,0);
    glVertex3f(-29,-20,-7);
    glVertex3f(-14,-20,-7);
    glVertex3f(-14,-15,-7);
    glVertex3f(-29,-15,-7);
    glEnd();

    //base kanan
    glBegin(GL_QUADS);
    glColor3f(0.6,0.3,0);
    glVertex3f(-14,-20,-7);
    glVertex3f(-14,-20,-29);
    glVertex3f(-14,-15,-29);
    glVertex3f(-14,-15,-7);
    glEnd();

    //base kiri
    glBegin(GL_QUADS);
    glColor3f(0.6,0.3,0);
    glVertex3f(-29,-20,-7);
    glVertex3f(-29,-20,-29);
    glVertex3f(-29,-15,-29);
    glVertex3f(-29,-15,-7);
    glEnd();

    //base atas
    glBegin(GL_QUADS);
    glColor3f(0.9,0.5,0);
    glVertex3f(-29,-15,-7);
    glVertex3f(-14,-15,-7);
    glVertex3f(-14,-15,-29);
    glVertex3f(-29,-15,-29);
    glEnd();

    //kasur depan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-28,-15,-9);
    glVertex3f(-15,-15,-9);
    glVertex3f(-15,-12,-9);
    glVertex3f(-28,-12,-9);
    glEnd();

    //kasur belakang
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-28,-15,-27);
    glVertex3f(-15,-15,-27);
    glVertex3f(-15,-12,-27);
    glVertex3f(-28,-12,-27);
    glEnd();

    //kasur kiri
    glBegin(GL_QUADS);
    glColor3f(0.7,0.7,0.7);
    glVertex3f(-28,-15,-9);
    glVertex3f(-28,-12,-9);
    glVertex3f(-28,-12,-27);
    glVertex3f(-28,-15,-27);
    glEnd();

    //kasur kanan
    glBegin(GL_QUADS);
    glColor3f(0.7,0.7,0.7);
    glVertex3f(-15,-15,-9);
    glVertex3f(-15,-12,-9);
    glVertex3f(-15,-12,-27);
    glVertex3f(-15,-15,-27);
    glEnd();

    //kasur atas
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-28,-12,-9);
    glVertex3f(-15,-12,-9);
    glVertex3f(-15,-12,-27);
    glVertex3f(-28,-12,-27);
    glEnd();

    //kasur bawah
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-28,-15,-9);
    glVertex3f(-15,-15,-9);
    glVertex3f(-15,-15,-27);
    glVertex3f(-28,-15,-27);
    glEnd();

    //lemari
    //lemari belakang
    glBegin(GL_QUADS);
    glColor3f(0.6,0.3,0);
    glVertex3f(-29,-20,5);
    glVertex3f(-20,-20,5);
    glVertex3f(-20,10,5);
    glVertex3f(-29,10,5);
    glEnd();

    //lemari depan
    glBegin(GL_QUADS);
    glColor3f(0.6,0.3,0);
    glVertex3f(-29,-20,20);
    glVertex3f(-20,-20,20);
    glVertex3f(-20,10,20);
    glVertex3f(-29,10,20);
    glEnd();

    //lemari kiri
    glBegin(GL_QUADS);
    glColor3f(0.8,0.5,0);
    glVertex3f(-29,-20,20);
    glVertex3f(-29,10,20);
    glVertex3f(-29,10,5);
    glVertex3f(-29,-20,5);
    glEnd();

    //lemari kanan
    glBegin(GL_QUADS);
    glColor3f(0.8,0.5,0);
    glVertex3f(-20,-20,20);
    glVertex3f(-20,10,20);
    glVertex3f(-20,10,5);
    glVertex3f(-20,-20,5);
    glEnd();

    //lemari atas
    glBegin(GL_QUADS);
    glColor3f(0.8,0.5,0.4);
    glVertex3f(-29,10,20);
    glVertex3f(-20,10,20);
    glVertex3f(-20,10,5);
    glVertex3f(-29,10,5);
    glEnd();

    //lemari bawah
    glBegin(GL_QUADS);
    glColor3f(0.6,0.3,0);
    glVertex3f(-29,-20,20);
    glVertex3f(-20,-20,20);
    glVertex3f(-20,-20,5);
    glVertex3f(-29,-20,5);
    glEnd();

    //pintu lemari
    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
    glVertex3f(-19.9,-20,12.5);
    glVertex3f(-19.9,10,12.5);
    glEnd();

    //gagang lemari
    glBegin(GL_POINTS);
    glColor3f(0,0,0);
    glVertex3f(-19.9,-5,14.5);
    glVertex3f(-19.9,-5,10.5);
    glEnd();

    //Meja
    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.6,0.3,0);
    glVertex3f(27,-15,-29);
    glVertex3f(13,-15,-29);
    glVertex3f(13,-13,-29);
    glVertex3f(27,-13,-29);
    glEnd();

    // depan
    glBegin(GL_QUADS);
    glColor3f(0.6,0.3,0);
    glVertex3f(27,-15,-21);
    glVertex3f(13,-15,-21);
    glVertex3f(13,-13,-21);
    glVertex3f(27,-13,-21);
    glEnd();

    // kanan
    glBegin(GL_QUADS);
    glColor3f(0.6,0.3,0);
    glVertex3f(27,-15,-21);
    glVertex3f(27,-13,-21);
    glVertex3f(27,-13,-29);
    glVertex3f(27,-15,-29);
    glEnd();

    // kiri
    glBegin(GL_QUADS);
    glColor3f(0.6,0.3,0);
    glVertex3f(13,-15,-21);
    glVertex3f(13,-13,-21);
    glVertex3f(13,-13,-29);
    glVertex3f(13,-15,-29);
    glEnd();

    // atas
    glBegin(GL_QUADS);
    glColor3f(0.8,0.5,0);
    glVertex3f(13,-13,-21);
    glVertex3f(27,-13,-21);
    glVertex3f(27,-13,-29);
    glVertex3f(13,-13,-29);
    glEnd();

    // bawah
    glBegin(GL_QUADS);
    glColor3f(0.8,0.5,0);
    glVertex3f(13,-15,-21);
    glVertex3f(27,-15,-21);
    glVertex3f(27,-15,-29);
    glVertex3f(13,-15,-29);
    glEnd();

    // kaki kiri 1
    glBegin(GL_QUADS);
    glColor3f(0.6,0.3,0);
    glVertex3f(13,-20,-21);
    glVertex3f(13,-15,-21);
    glVertex3f(13,-15,-29);
    glVertex3f(13,-20,-29);
    glEnd();

    // kaki kiri 2
    glBegin(GL_QUADS);
    glColor3f(0.6,0.3,0);
    glVertex3f(14,-20,-21);
    glVertex3f(14,-15,-21);
    glVertex3f(14,-15,-29);
    glVertex3f(14,-20,-29);
    glEnd();

    // kaki kiri 3
    glBegin(GL_QUADS);
    glColor3f(0.6,0.3,0);
    glVertex3f(13,-20,-21);
    glVertex3f(14,-20,-21);
    glVertex3f(14,-15,-21);
    glVertex3f(13,-15,-21);
    glEnd();

    // kaki kiri 4
    glBegin(GL_QUADS);
    glColor3f(0.6,0.3,0);
    glVertex3f(13,-20,-29);
    glVertex3f(14,-20,-29);
    glVertex3f(14,-15,-29);
    glVertex3f(13,-15,-29);
    glEnd();

    // kaki kanan 1
    glBegin(GL_QUADS);
    glColor3f(0.6,0.3,0);
    glVertex3f(27,-20,-21);
    glVertex3f(27,-15,-21);
    glVertex3f(27,-15,-29);
    glVertex3f(27,-20,-29);
    glEnd();

    // kaki kanan 2
    glBegin(GL_QUADS);
    glColor3f(0.6,0.3,0);
    glVertex3f(26,-20,-21);
    glVertex3f(26,-15,-21);
    glVertex3f(26,-15,-29);
    glVertex3f(26,-20,-29);
    glEnd();

    // kaki kanan 3
    glBegin(GL_QUADS);
    glColor3f(0.6,0.3,0);
    glVertex3f(27,-20,-21);
    glVertex3f(26,-20,-21);
    glVertex3f(26,-15,-21);
    glVertex3f(27,-15,-21);
    glEnd();

    // kaki kanan 4
    glBegin(GL_QUADS);
    glColor3f(0.6,0.3,0);
    glVertex3f(27,-20,-29);
    glVertex3f(26,-20,-29);
    glVertex3f(26,-15,-29);
    glVertex3f(27,-15,-29);
    glEnd();


    //TV
    //alas tv bawah
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(16,-13,-23);
    glVertex3f(24,-13,-23);
    glVertex3f(24,-13,-27);
    glVertex3f(16,-13,-27);
    glEnd();

    //alas tv atas
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(16,-12,-23);
    glVertex3f(24,-12,-23);
    glVertex3f(24,-12,-27);
    glVertex3f(16,-12,-27);
    glEnd();

    //alas tv depan
    glBegin(GL_QUADS);
    glColor3f(0,0.1,0.1);
    glVertex3f(16,-12,-23);
    glVertex3f(24,-12,-23);
    glVertex3f(24,-13,-23);
    glVertex3f(16,-13,-23);
    glEnd();

    //alas tv belakang
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(16,-12,-27);
    glVertex3f(24,-12,-27);
    glVertex3f(24,-13,-27);
    glVertex3f(16,-13,-27);
    glEnd();

    //alas tv kiri
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(16,-12,-23);
    glVertex3f(16,-13,-23);
    glVertex3f(16,-13,-27);
    glVertex3f(16,-12,-27);
    glEnd();

    //alas tv kanan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(24,-12,-23);
    glVertex3f(24,-13,-23);
    glVertex3f(24,-13,-27);
    glVertex3f(24,-12,-27);
    glEnd();

    //stand tv depan
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.1);
    glVertex3f(19.5,-12,-24.5);
    glVertex3f(20.5,-12,-24.5);
    glVertex3f(20.5,-10,-24.5);
    glVertex3f(19.5,-10,-24.5);
    glEnd();

    //stand tv belakang
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.1);
    glVertex3f(19.5,-12,-25);
    glVertex3f(20.5,-12,-25);
    glVertex3f(20.5,-10,-25);
    glVertex3f(19.5,-10,-25);
    glEnd();

    //stand tv kiri
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.1);
    glVertex3f(19.5,-12,-24.5);
    glVertex3f(19.5,-10,-24.5);
    glVertex3f(19.5,-10,-25);
    glVertex3f(19.5,-12,-25);
    glEnd();

    //stand tv kiri
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.1);
    glVertex3f(20.5,-12,-24.5);
    glVertex3f(20.5,-10,-24.5);
    glVertex3f(20.5,-10,-25);
    glVertex3f(20.5,-12,-25);
    glEnd();

    //tv bawah
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(15,-10,-24);
    glVertex3f(25,-10,-24);
    glVertex3f(25,-10,-26);
    glVertex3f(15,-10,-26);
    glEnd();

    //tv atas
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(15,-4,-24);
    glVertex3f(25,-4,-24);
    glVertex3f(25,-4,-26);
    glVertex3f(15,-4,-26);
    glEnd();

    //tv depan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(15,-10,-24);
    glVertex3f(25,-10,-24);
    glVertex3f(25,-4,-24);
    glVertex3f(15,-4,-24);
    glEnd();

    //tv depan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(15,-10,-26);
    glVertex3f(25,-10,-26);
    glVertex3f(25,-4,-26);
    glVertex3f(15,-4,-26);
    glEnd();

    //tv kiri
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(15,-10,-24);
    glVertex3f(15,-4,-24);
    glVertex3f(15,-4,-26);
    glVertex3f(15,-10,-26);
    glEnd();

    //tv kanan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(25,-10,-24);
    glVertex3f(25,-4,-24);
    glVertex3f(25,-4,-26);
    glVertex3f(25,-10,-26);
    glEnd();

    //layar
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(15.5,-9.5,-23.9);
    glVertex3f(24.5,-9.5,-23.9);
    glVertex3f(24.5,-4.5,-23.9);
    glVertex3f(15.5,-4.5,-23.9);
    glEnd();


    //jam
    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.7,0.7,0.7);
    glVertex3f(-3,-2,-29.9);
    glVertex3f(-3,4,-29.9);
    glVertex3f(3,4,-29.9);
    glVertex3f(3,-2,-29.9);
    glEnd();

    //depan
    glBegin(GL_QUADS);
    glColor3f(0.7,0.7,0.7);
    glVertex3f(-3,-2,-29.2);
    glVertex3f(-3,4,-29.2);
    glVertex3f(3,4,-29.2);
    glVertex3f(3,-2,-29.2);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.7,0.7,0.7);
    glVertex3f(-3,-2,-29.2);
    glVertex3f(-3,4,-29.2);
    glVertex3f(-3,4,-29.9);
    glVertex3f(-3,-2,-29.9);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(0.7,0.7,0.7);
    glVertex3f(3,-2,-29.2);
    glVertex3f(3,4,-29.2);
    glVertex3f(3,4,-29.9);
    glVertex3f(3,-2,-29.9);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(0.7,0.7,0.7);
    glVertex3f(-3,-2,-29.2);
    glVertex3f(3,-2,-29.2);
    glVertex3f(3,-2,-29.9);
    glVertex3f(-3,-2,-29.9);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
    glColor3f(0.7,0.7,0.7);
    glVertex3f(-3,4,-29.2);
    glVertex3f(3,4,-29.2);
    glVertex3f(3,4,-29.9);
    glVertex3f(-3,4,-29.9);
    glEnd();

    //layar
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-2.5,-2,-29.1);
    glVertex3f(-2.5,4,-29.1);
    glVertex3f(2.5,4,-29.1);
    glVertex3f(2.5,-2,-29.1);
    glEnd();

    //jarum jam 1
    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
    glVertex3f(-0.03,1,-29);
    glVertex3f(2,1,-29);
    glEnd();

    //jarum jam 2
    glBegin(GL_LINE_STRIP);
    glColor3f(0,0,0);
    glVertex3f(0,1,-29);
    glVertex3f(0,3,-29);
    glEnd();

    //sofa
    // kaki kiri 1
    glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.8);
    glVertex3f(13,-20,4);
    glVertex3f(13,-15,4);
    glVertex3f(13,-15,-4);
    glVertex3f(13,-20,-4);
    glEnd();

    // kaki kiri 2
    glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.8);
    glVertex3f(14,-20,4);
    glVertex3f(14,-15,4);
    glVertex3f(14,-15,-4);
    glVertex3f(14,-20,-4);
    glEnd();

    // kaki kiri 3
    glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.8);
    glVertex3f(13,-20,4);
    glVertex3f(14,-20,4);
    glVertex3f(14,-15,4);
    glVertex3f(13,-15,4);
    glEnd();

    // atas kiri
    glBegin(GL_QUADS);
    glColor3f(0.2,0.5,1);
    glVertex3f(13,-15,4);
    glVertex3f(14,-15,4);
    glVertex3f(14,-15,-4);
    glVertex3f(13,-15,-4);
    glEnd();

    // kaki kiri 4
    glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.8);
    glVertex3f(13,-20,-4);
    glVertex3f(14,-20,-4);
    glVertex3f(14,-15,-4);
    glVertex3f(13,-15,-4);
    glEnd();

    // kaki kanan 1
    glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.8);
    glVertex3f(27,-20,4);
    glVertex3f(27,-15,4);
    glVertex3f(27,-15,-4);
    glVertex3f(27,-20,-4);
    glEnd();

    // kaki kanan 2
    glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.8);
    glVertex3f(26,-20,4);
    glVertex3f(26,-15,4);
    glVertex3f(26,-15,-4);
    glVertex3f(26,-20,-4);
    glEnd();

    // kaki kanan 3
    glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.8);
    glVertex3f(27,-20,4);
    glVertex3f(26,-20,4);
    glVertex3f(26,-15,4);
    glVertex3f(27,-15,4);
    glEnd();

    // atas kiri
    glBegin(GL_QUADS);
    glColor3f(0.2,0.5,1);
    glVertex3f(27,-15,4);
    glVertex3f(26,-15,4);
    glVertex3f(26,-15,-4);
    glVertex3f(27,-15,-4);
    glEnd();

    // kaki kanan 4
    glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.8);
    glVertex3f(27,-20,-4);
    glVertex3f(26,-20,-4);
    glVertex3f(26,-15,-4);
    glVertex3f(27,-15,-4);
    glEnd();

    //depan
    glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.8);
    glVertex3f(27,-20,4);
    glVertex3f(13,-20,4);
    glVertex3f(13,-10,4);
    glVertex3f(27,-10,4);
    glEnd();

    //belakang
    glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.8);
    glVertex3f(27,-20,-4);
    glVertex3f(13,-20,-4);
    glVertex3f(13,-17,-4);
    glVertex3f(27,-17,-4);
    glEnd();

    //atas
    glBegin(GL_QUADS);
    glColor3f(0.2,0.5,1);
    glVertex3f(27,-10,4);
    glVertex3f(13,-10,4);
    glVertex3f(13,-10,2);
    glVertex3f(27,-10,2);
    glEnd();

    //tengah
    glBegin(GL_QUADS);
    glColor3f(0.2,0.5,1);
    glVertex3f(27,-10,2);
    glVertex3f(13,-10,2);
    glVertex3f(13,-17,0);
    glVertex3f(27,-17,0);
    glEnd();

    //atas tengah
    glBegin(GL_QUADS);
    glColor3f(0.2,0.4,0.8);
    glVertex3f(13,-17,0);
    glVertex3f(27,-17,0);
    glVertex3f(27,-17,-4);
    glVertex3f(13,-17,-4);
    glEnd();

    //kanan
    glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.8);
    glVertex3f(27,-10,4);
    glVertex3f(27,-15,4);
    glVertex3f(27,-15,0.5);
    glVertex3f(27,-10,2);
    glEnd();

    //kiri
    glBegin(GL_QUADS);
    glColor3f(0.2,0.2,0.8);
    glVertex3f(13,-10,4);
    glVertex3f(13,-15,4);
    glVertex3f(13,-15,0.5);
    glVertex3f(13,-10,2);
    glEnd();




    glPushMatrix();
    glPopMatrix();

    glutSwapBuffers();
}
void keyboard(unsigned char key,int x,int y)
{
    switch(key)
    {
    case'w'://Geser atas
    case'W':
        glTranslatef(0.0,3.0,0.0);
        break;
    case 'd':
    case 'D'://Geser kanan
        glTranslatef(3.0,0.0,0.0);
        break;
    case 's'://Geser Bawah
    case 'S':
        glTranslatef(0.0,-3.0,0.0);
        break;
    case 'a'://Geser kiri
    case 'A':
        glTranslatef(-3.0,0.0,0.0);
        break;
    case '7'://Zoom in
        glTranslatef(0.0,0.0,3.0);
        break;
    case '9'://Zoom out
        glTranslatef(0.0,0.0,-3.0);
        break;
    case '2'://Rotasi depan
        glRotatef(2.0,1.0,0.0,0.0);
        break;
    case '8'://Rotasi belakang
        glRotatef(-2.0,1.0,0.0,0.0);
        break;
    case '6'://Rotasi kanan
        glRotatef(2.0,0.0,1.0,0.0);
        break;
    case '4'://Rotasi kiri
        glRotatef(-2.0,0.0,1.0,0.0);
        break;
    case '1'://Rotasi bawah kiri
        glRotatef(2.0,0.0,0.0,1.0);
        break;
    case '3'://Rotasi bawah kiri
        glRotatef(-2.0,0.0,0.0,1.0);
        break;
    case '5'://hilangkan objek depan
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();


}

void idle()
{
    if (!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
    {
        mouseDown = false;
    }
}

void mouseMotion(int x, int y)
{
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}



void ukuran (int lebar,int tinggi)
{
    if (tinggi ==0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0,-5.0,-150.0);
    glMatrixMode(GL_MODELVIEW);
}
int main (int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000,700);
    glutInitWindowPosition(250,50);
    glutCreateWindow("Indra Yunanto - 672018019");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(ukuran);

    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutIdleFunc(tampil);

    glutMainLoop();
    return 0;
}
