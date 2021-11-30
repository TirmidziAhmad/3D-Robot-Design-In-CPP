#include <GL\freeglut.h>
#include <iostream>
#include <math.h>

using namespace std;
//inisialisasi Pi
const GLfloat Pi = 3.1415926536f;
//Jarak kamera ke objek
float G_fDistance = 4.0f;
//Sudut rotasi robot
float G_fAngle_horizon = 0.0;
float G_fAngle_vertical = 0.0;

void myinit(void);
void myReshape(GLsizei w, GLsizei h);
void display(void);

void processSpecialKeys(int key, int x, int y);
void processNormalKeys(unsigned char key,int x,int y);
void timer(int value);

//Fungsi main
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	//inisialisasi OPENGL tampilan mode
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);

	//mengatur posisi dan size window
	glutInitWindowSize (800, 600);
	glutInitWindowPosition (300, 50);

	//Membuka windows
	glutCreateWindow ("Red fighter Robot wearing black hat");
	cout<<"Pencet arah atas,bawah,kanan,kiri pada keyboard  Untuk mengontrol rotasi robot"<<"\n";
	//Inisialisasi fungsi init
    myinit();

	//memanggil fungsi reshape
	glutReshapeFunc(myReshape);

	//Memanggil fungsi pengendali keyboard
	glutSpecialFunc(processSpecialKeys);

	//Menampilkan opengl dan membuatnya terbuka sampai user close
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}

void myinit(void)//Inisialisasi
{
   glClearColor(0.0,0.0,0.0,0.0); //ganti warna bg
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}


void myReshape(GLsizei w, GLsizei h)//Set the callback function of the window size change
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60,(GLfloat)w/(GLfloat)h,1,30);
}

void display(void)
{
	// buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Ubah perspektif
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0,0.0,-G_fDistance);
	glRotatef(G_fAngle_horizon, 0.0f, 1.0f, 0.0f);
	glRotatef(G_fAngle_vertical, 1.0f, 0.0f, 0.0f);

	//Badan
	glPushMatrix();
		glColor3f(0.862,0.282,0.211);
		glTranslatef(0.0,0.3,0.1);
		glScalef(0.9,1.0,0.65);
		glutSolidCube(1.3);
	glPopMatrix();
	 //Leher
            glPushMatrix();
                glColor3f(0.2,0.2,0.2);
                glTranslatef(0.0,0.5,0.5);
                glRotatef(0.0,0.0,0.0,0.0);
                glScalef(0.15,0.15,0.2);
                glutSolidCylinder(1.0,1.0,100,10);
                glPushMatrix();
                    glColor3f(0.917,0.901,0.843);
                    glScalef(1.1,1.1,0.4);
                    glutSolidCylinder(1.0,1.0,100,10);
                glPopMatrix();
            glPopMatrix();

	 //kepala
                glPushMatrix();
                    glColor3f(0.862,0.282,0.211);
                    glTranslatef(0.0,0.5,0.9);
                    glScalef(0.5,0.5,0.4);
                    glutSolidCube(0.9);
                //jidat
                    glPushMatrix();
                        glColor3f(0.3,0.3,0.3);
                        glScalef(1.97,0.7,1.9);
                        glTranslatef(0.0,0.40,0.0);
                        glutSolidCube(0.5);
                    glPopMatrix();
                        glPushMatrix();
                        glTranslatef(0.0,-0.01,0.0);
                    //mata
                        glPushMatrix();
                        glColor3f(0.039, 0.815, 0.643);
                        glScalef(0.15,0.15,0.1);
                        glTranslatef(1.6,0.35,3.7);
                        glutSolidCylinder(1.0,1.0,100,10);
                        glPopMatrix();
                    //mata2
                    glPushMatrix();
                        glColor3f(0.039, 0.815, 0.643);
                        glScalef(0.15,0.15,0.1);
                        glTranslatef(-1.6,0.35,3.7);
                        glutSolidCylinder(1.0,1.0,100,10);
                    glPopMatrix();
                    glPopMatrix();
                    //mulut
                    glPushMatrix();
                        glColor3f(0.905,0.898,0.839);
                        glScalef(0.4,0.4,0.2);
                        glTranslatef(0.0,-0.45,2.3);
                        glutSolidCube(0.5);
                    glPopMatrix();

                    glPushMatrix();
                        glColor3f(0.905,0.898,0.839);
                        glScalef(0.4,0.4,0.2);
                        glTranslatef(0.8,-0.45,2.3);
                        glutSolidCube(0.5);
                    glPopMatrix();

                    glPushMatrix();
                        glColor3f(0.905,0.898,0.839);
                        glScalef(0.4,0.4,0.2);
                        glTranslatef(-0.8,-0.45,2.3);
                        glutSolidCube(0.5);
                    glPopMatrix();

                    glPushMatrix();
                        glColor3f(0.905,0.898,0.839);
                        glScalef(1.97,0.4,2.0);
                        glTranslatef(0.0,-0.90,0.0);
                        glutSolidCube(0.5);
                    glPopMatrix();
                glPopMatrix();
                //topi
                glPushMatrix();
                glColor3f(0.3,0.3,0.3);
                glTranslatef(0.0,0.6,1.0);
                glScalef(0.45,0.04,0.5);
                glutSolidCube(1.0);
                glPopMatrix();
     //Sendi badan-kaki

    glPushMatrix();
        glRotatef(90.0,1.0,0.0,0.0);
        glTranslatef(0.0,0.0,0.3);
        glScalef(0.25,0.25,0.25);
        glutSolidCylinder(1.0,1.5,100,10);
    glPopMatrix();


//tangan kiri

	//sendi
    glPushMatrix();
        glColor3f(0.3,0.3,0.3);
        glTranslatef(-0.6,0.4,0.2);
        glutSolidSphere(0.1,100,10);
    glPopMatrix();

    //lengan atas
    glPushMatrix();
    glColor3f(0.905,0.898,0.839);
    	glRotatef(65.0,1.0,0.0,0.0);
    	glTranslatef(-0.6,0.35,-0.3);
    	glRotatef(-35.0,0.0,1.0,0.0);
    	glPushMatrix();
    		glScalef(0.07,0.07,1.5);;
    		glutSolidCylinder(1.0,0.5,100,10);
    	glPopMatrix();
    glPopMatrix();

    //tangan
    glPushMatrix();
    	glRotatef(-30.0,1.0,0.0,0.0);
    	glTranslatef(-1.0,-0.3,0.3);
    	glPushMatrix();
    		glColor3f(0.862,0.282,0.211);
    		glScalef(0.2,0.7,0.3);
    		glutSolidCube(1.0);
    	glPopMatrix();
    glPopMatrix();

    //Jari tangan kanan
    //1
    glPushMatrix();
    	glColor3f(0.3,0.3,0.3);;
    	glRotatef(-30.0,1.0,0.0,0.0);
    	glTranslatef(-1.1,-0.7,0.45);
    	glPushMatrix();
    		glScalef(0.025,0.25,0.075);
    		glutSolidCube(1.0);
    	glPopMatrix();
    glPopMatrix();

    //2
    glPushMatrix();
    	glColor3f(0.3,0.3,0.3);
    	glRotatef(-30.0,1.0,0.0,0.0);
    	glTranslatef(-0.9,-0.7,0.3);
    	glPushMatrix();
    		glScalef(0.025,0.25,0.075);
    		glutSolidCube(1.0);
    	glPopMatrix();
    glPopMatrix();

    //3
    glPushMatrix();
    	glColor3f(0.3,0.3,0.3);
    	glRotatef(-30.0,1.0,0.0,0.0);
    	glTranslatef(-1.1,-0.7,0.15);
    	glPushMatrix();
    		glScalef(0.025,0.25,0.075);
    		glutSolidCube(1.0);
    	glPopMatrix();
    glPopMatrix();

//tangan kiri

	//sendi
    glPushMatrix();
        glColor3f(0.3,0.3,0.3);
        glTranslatef(0.6,0.4,0.2);
        glutSolidSphere(0.1,100,10);
    glPopMatrix();

    //lengan atas
    glPushMatrix();
    glColor3f(0.905,0.898,0.839);
    	glRotatef(65.0,1.0,0.0,0.0);
    	glTranslatef(0.6,0.35,-0.3);
    	glRotatef(35.0,0.0,1.0,0.0);
    	glPushMatrix();
    		glScalef(0.07,0.07,1.5);;
    		glutSolidCylinder(1.0,0.5,100,10);
    	glPopMatrix();
    glPopMatrix();

    //tangan
    glPushMatrix();
    	glRotatef(-62.0,1.0,0.0,0.0);
    	glTranslatef(1.0,-0.36,0.21);
    	glPushMatrix();
    		glColor3f(0.905,0.898,0.839);
    		glScalef(0.17,0.5,0.17);
    		glutSolidCube(1.0);
    	glPopMatrix();
    glPopMatrix();

	//Senjata
	 glPushMatrix();
    	glRotatef(20.0,1.0,0.0,0.0);
    	glTranslatef(1.0,0.125,0.35);
    	glPushMatrix();
    		glColor3f(0.862,0.282,0.211);
    		glScalef(0.4,0.4,0.5);
    		glutSolidCone(0.5,1.5,10,10);
    	glPopMatrix();
    glPopMatrix();

    //Penghubung badan-kaki
    glPushMatrix();
		glColor3f(0.862,0.282,0.211);
		glTranslatef(0.0,-0.6,0.0);
		glRotatef(90.0,1.0,0.0,0.0);
		glPushMatrix();
			glScalef(0.4,0.4,0.3);
            glutSolidCylinder(1.0,0.5,100,10);
		glPopMatrix();
	glPopMatrix();

	//Posisi
	glRotatef(500.0,0.0,1.0,0.0);
	glTranslatef(0.0,-0.5,0.0);


//kaki 1

	//paha 1
	glPushMatrix();
		glColor3f(0.905,0.898,0.839);
		glRotatef(30.0,1.0,0.0,0.0);
		glTranslatef(0.0,-0.45,-0.1);
		glPushMatrix();
			glScalef(0.125,0.4,0.125);
			glutSolidCube(1.0);
		glPopMatrix();
	glPopMatrix();

	//betis 1
	glPushMatrix();
		glRotatef(35.0,1.0,0.0,0.0);
		glTranslatef(0.0,-0.7,-0.18);
		glPushMatrix();
			glScalef(0.125,0.125,0.4);
			glutSolidCube(1.0);
		glPopMatrix();
	glPopMatrix();

	 //Octahedron 1
	glPushMatrix();
		glColor3f(0.862,0.282,0.211);
		glTranslatef(0.0,-0.45,-0.7);
		glPushMatrix();
			glScalef(0.2,0.35,0.1);
			glutSolidOctahedron();
		glPopMatrix();
	glPopMatrix();

//kaki2

	//paha 2
	glPushMatrix();
        glColor3f(0.905,0.898,0.839);
		glRotatef(-30.0,0.0,.0,1.0);
		glTranslatef(-0.1,-0.45,0.0);
		glPushMatrix();
			glScalef(0.125,0.4,0.125);
			glutSolidCube(1.0);
		glPopMatrix();
	glPopMatrix();

	//betis 2
	glPushMatrix();
		glRotatef(-35.0,0.0,0.0,1.0);
		glTranslatef(-0.18,-0.7,0.0);
		glPushMatrix();
			glScalef(0.4,0.125,0.125);
			glutSolidCube(1.0);
		glPopMatrix();
	glPopMatrix();

	//Octahedron 2
	glPushMatrix();
		glColor3f(0.862,0.282,0.211);
		glTranslatef(-0.7,-0.45,0.0);
		glPushMatrix();
			glScalef(0.1,0.36,0.2);
			glutSolidOctahedron();
		glPopMatrix();
	glPopMatrix();

//kaki3
	//paha 3
	glPushMatrix();
		glColor3f(0.905,0.898,0.839);
		glRotatef(-30.0,1.0,0.0,0.0);
		glTranslatef(0.0,-0.45,0.1);
		glPushMatrix();
			glScalef(0.125,0.4,0.125);
			glutSolidCube(1.0);
		glPopMatrix();
	glPopMatrix();

	//betis 3
	glPushMatrix();
		glRotatef(-35.0,1.0,0.0,0.0);
		glTranslatef(0.0,-0.7,0.18);
		glPushMatrix();
			glScalef(0.125,0.125,0.4);
			glutSolidCube(1.0);
		glPopMatrix();
	glPopMatrix();

	//Octahedron 3
	glPushMatrix();
		glColor3f(0.862,0.282,0.211);
		glTranslatef(0.0,-0.45,0.7);
		glPushMatrix();
			glScalef(0.2,0.35,0.1);
			glutSolidOctahedron();
		glPopMatrix();
	glPopMatrix();

//kaki4

	//Paha 4
	glPushMatrix();
		glColor3f(0.905,0.898,0.839);
		glRotatef(30.0,0.0,.0,1.0);
		glTranslatef(0.1,-0.45,0.0);
		glPushMatrix();
			glScalef(0.125,0.4,0.125);
			glutSolidCube(1.0);
		glPopMatrix();
	glPopMatrix();

	//betis 4
	glPushMatrix();
		glRotatef(35.0,0.0,0.0,1.0);
		glTranslatef(0.18,-0.7,0.0);
		glPushMatrix();
			glScalef(0.4,0.125,0.125);
			glutSolidCube(1.0);
		glPopMatrix();
	glPopMatrix();

	//Octahedron 4
	glPushMatrix();
		glColor3f(0.862,0.282,0.211);
		glTranslatef(0.7,-0.45,0.0);
		glPushMatrix();
			glScalef(0.1,0.36,0.2);
			glutSolidOctahedron();
		glPopMatrix();
	glPopMatrix();
	glutSwapBuffers();
}


//rotasi robot
void processSpecialKeys(int key, int x, int y)
{
	switch(key) {
		case GLUT_KEY_LEFT:
			G_fAngle_horizon -= 5.0f;
			break;
		case GLUT_KEY_RIGHT:
			G_fAngle_horizon += 5.0f;
			break;
		case GLUT_KEY_UP:
			G_fAngle_vertical -= 5.0f;
			break;
		case GLUT_KEY_DOWN:
			G_fAngle_vertical += 5.0f;
			break;
	}
	glutPostRedisplay();
}
