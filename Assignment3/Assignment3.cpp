#include<windows.h>
#include <iostream>
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
using namespace std;

float xx = 0.0, yy = 0.0, zz = 0.0;
float _angle = 30.0f;
float _cameraAngle = 0.0f;

bool okLeft( double x ){
    if( ( 1 + x ) < -1 ) return false;
    return true;
}
bool okDown( double x ){
    if( ( -.5 + x ) < -1 ) return false;
    return true;
}
bool okRight( double x ){
    if( ( 1.5 + x ) > 2 ) return false;
    if( yy > 0 && ( ( 1.5 + x ) > 0 ) ) return false;
    return true;
}
bool okUp( double x ){
    if( ( 0 + x ) > 2 ) return false;
    if( ( 1.5 + xx ) > 0 && ( x > 0 ) ) return false;
    return true;
}

//Called when a key is pressed
void handleKeypress(unsigned char key, int x, int y) {
    cout << key << "\n";
	if( key == '4' ){
        if( okLeft( xx - .5 ) ){
           xx -= .5;
        }
	}else if( key == '2' ){
	    if( okDown( yy - .5 ) ){
            yy -= .5;
	    }
	}else if( key == '6' ){
	    if( okRight( xx + .5 ) ){
           xx += .5;
	    }
	}else if( key == '8' ){
	    if( okUp( yy + .5 ) ){
            yy += .5;
	    }
	}
}
//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL); //Enable color
	glClearColor(0.7f, 0.9f, 1.0f, 1.0f); //Change the background to sky blue
}
//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

void object(){
    glTranslatef(xx, yy, 0.0f);

    glPushMatrix();
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);

	glVertex3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.5f, 0.0f, 0.0f);
	glVertex3f(1.5f, -.5f, 0.0f);
	glVertex3f(1.0f, -.5f, 0.0f);

	glEnd();
	glPopMatrix();

	glTranslatef(-xx, -yy, 0.0f);
}

//Draws the 3D scene
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, 0.0f, -5.0f);
	object();

	glColor3f(1.0f, 1.0f, 1.0f);

	glPushMatrix();
	glBegin(GL_QUADS);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(2.0f, 0.0f, 0.0f);
	glVertex3f(2.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_QUADS);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, 2.0f, 0.0f);
	glVertex3f(0.0f, 2.0f, 0.0f);

	glEnd();
	glPopMatrix();

	glutSwapBuffers();
}

void update(int value) {
	glutPostRedisplay();
	glutKeyboardFunc(handleKeypress);
	glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1500, 700);

	//Create the window
	glutCreateWindow("Color");
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);

	glutTimerFunc(25, update, 0); //Add a timer

	glutMainLoop();
	return 0;
}







