
#include <bits/stdc++.h>
#include<windows.h>
#include <GL/glut.h>
using namespace std;

struct point{
    double x, y;
    point(double a, double b ){
        x = a; y = b;
    }
};
struct colour{
    double R, G, B;
    colour(double a, double b, double c ){
        R = a; G = b; B = c;
    }
};

//Called when a key is pressed
void handleKeypress(unsigned char key, //The key that was pressed
					int x, int y) {    //The current mouse coordinates
	switch (key) {
		case 27: //Escape key
			exit(0); //Exit the program
	}
}
//Initializes 3D rendering
void initRendering() {
	//Makes 3D drawing work when something is in front of something else
	glEnable(GL_DEPTH_TEST);
}
//Called when the window is resized
void handleResize(int w, int h) {
	//Tell OpenGL how to convert from coordinates to pixel values
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective
	//Set the camera perspective
	glLoadIdentity(); //Reset the camera
	gluPerspective(45.0,                  //The camera angle
                    (double)w / (double)h, //The width-to-height ratio
                    1.0,                   //The near z clipping coordinate
                    200.0);                //The far z clipping coordinate
}

void drawFilledCircle(  double x, double y, double radius, double R, double G, double B ){
    float theta;
    glColor3f(R, G, B);
    glBegin(GL_POLYGON);
    for(int i = 0; i < 360; i++ )
    {
        theta = i*3.1416/180;
        glVertex3f(x+radius*cosf(theta),y+radius*sinf(theta),-5.0f);
    }
    glEnd();
}

void rectangle(point lowerLeft, point lowerRight, point upperRight, point upperLeft, colour c ){
    glBegin(GL_QUADS);

	glColor3f(c.R, c.G, c.B);
	glVertex3f(lowerLeft.x, lowerLeft.y, -5.0f);
	glVertex3f(lowerRight.x, lowerRight.y, -5.0f);
	glVertex3f(upperRight.x, upperRight.y, -5.0f);
	glVertex3f(upperLeft.x, upperLeft.y, -5.0f);

	glEnd(); //End quadrilateral coordinates
}

void triangle( point baseLeft, point baseRight, point up, colour c ){
    glBegin(GL_TRIANGLES);//Begin triangle coordinates

    glColor3f(c.R, c.G, c.B);
	glVertex3f(baseLeft.x, baseLeft.y, -5.0f);
	glVertex3f(baseRight.x, baseRight.y, -5.0f);
	glVertex3f(up.x, up.y, -5.0f);

	glEnd(); //End triangle coordinates
}

//Draws the 3D scene
void drawScene() {
	//Clear information from last draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective

	glTranslatef(1.0f,0.0f,0.0f);

    drawFilledCircle(-.05, -1.15, .030, 0.502, 0.502, 0.000 ); // dorojar left handle
    drawFilledCircle(.05, -1.15, .030, 0.502, 0.502, 0.000 ); // dorojar right handle
    rectangle( point(-.005f, -1.50f), point(.005f, -1.5f), point(.005f, -.7f), point(-.005f, -.7f), colour( 0.000f, 0.000f, 0.000f ) ); // dorojar majh
    rectangle( point(-.250f, -1.50f), point(.250f, -1.5f), point(.250f, -.7f), point(-.250f, -.7f), colour( 0.333, 0.420, 0.184  ) ); // doroja

    rectangle( point(-.30f, -1.50f), point(.30f, -1.5f), point(.30f, -1.6f), point(-.30f, -1.6f), colour( 1.000, 0.627, 0.478  ) ); // siri
    rectangle( point(-.250f, -1.60f), point(.25f, -1.6f), point(.25f, -1.7f), point(-.25f, -1.7f), colour( 0.878, 1.000, 1.000  ) ); // siri

    rectangle( point(-.70f, -1.2f), point(-.68f, -1.2f), point(-.68f, -.8f), point(-.7f, -.8f), colour( 0.000, 0.000, 0.000 ) ); // janala left grill
    rectangle( point(-.580f, -1.2f), point(-.60f, -1.2f), point(-.60f, -.8f), point(-.580f, -.8f), colour( 0.000, 0.000, 0.000 ) ); // janala left grill
    rectangle( point(-.50f, -1.2f), point(-.48f, -1.2f), point(-.48f, -.8f), point(-.50f, -.8f), colour( 0.000, 0.000, 0.000 ) ); // janala left grill
    rectangle( point(-.80f, -1.2f), point(-.40f, -1.2f), point(-.40f, -.8f), point(-.80f, -.8f), colour( 0.502, 0.000, 0.000 ) ); // janala left

    rectangle( point(.68f, -.8f), point(.7f, -.8f),point(.70f, -1.2f), point(.68f, -1.2f),  colour( 0.000, 0.000, 0.000 ) ); // janala left grill
    rectangle( point(.60f, -.8f), point(.580f, -.8f), point(.580f, -1.2f), point(.60f, -1.2f), colour( 0.000, 0.000, 0.000 ) ); // janala left grill
    rectangle( point(.48f, -.8f), point(.50f, -.8f), point(.50f, -1.2f), point(.48f, -1.2f), colour( 0.000, 0.000, 0.000 ) ); // janala right grill
    rectangle( point(.40f, -.8f), point(.80f, -.8f), point(.80f, -1.2f), point(.40f, -1.2f), colour( 0.502, 0.000, 0.000 ) ); // janala right

    rectangle( point(-1.0f, -1.5f), point(1.0f, -1.5f), point(1.0f, -.2f), point(-1.0f, -.2f), colour( 1.000, 0.271, 0.000 ) ); // body

    triangle( point(-1.5, -.2), point( 1.5 ,-.2), point(0.0, .5), colour(0.000, 0.000, 0.000) );// roof

    glTranslatef(-1.0f,0.0f,0.0f);

    triangle( point(-3.05, -1.4), point( -2.85 ,-1.4), point(-2.95, -.5), colour(0.133, 0.545, 0.133) ); // tree er matha
    rectangle( point(-3.0f, -1.8f), point(-2.90f, -1.8f), point(-2.90f, -1.0f), point(-3.0f, -1.0f), colour( 0.824, 0.412, 0.118 ) );//tree er body

    triangle( point(3.05, -1.4), point( 2.85 ,-1.4), point(2.95, -.5), colour(0.133, 0.545, 0.133) ); // tree er matha
    rectangle( point(2.90f, -1.0f), point(3.0f, -1.0f), point(3.0f, -1.8f), point(2.90f, -1.8f), colour( 0.824, 0.412, 0.118 ) );//tree er body

   glTranslatef(.0f,-0.6f,0.0f);
    rectangle( point(-4.0f, -.52f), point(-3.6f, -.20f), point(-3.6f, -.10f), point(-4.1f, -.5f), colour(  1.000, 0.843, 0.000 ) ); //nouka
    glTranslatef(.0f,0.5f,0.0f);

    rectangle( point(-5.0f, -5.0f), point(5.0f, -5.0f), point(5.0f, -1.75f), point(-5.0f, -1.75f), colour(  0.741, 0.718, 0.420 ) ); //mati

    drawFilledCircle(3.5, 1.1, .20, 0.961, 0.961, 0.961 );//cloud
    drawFilledCircle(3.7, 1.2, .20, 0.961, 0.961, 0.961 );//cloud
    drawFilledCircle(3.9, 1.1, .20, 0.961, 0.961, 0.961 );//cloud
    drawFilledCircle(3.6, 1.0, .20, 0.961, 0.961, 0.961 );//cloud
    drawFilledCircle(3.8, 1.0, .20, 0.961, 0.961, 0.961 );//cloud

    drawFilledCircle(1.0, 1.6, .20, 0.961, 0.961, 0.961 );//cloud
    drawFilledCircle(1.2, 1.7, .20, 0.961, 0.961, 0.961 );//cloud
    drawFilledCircle(1.4, 1.6, .20, 0.961, 0.961, 0.961 );//cloud
    drawFilledCircle(1.1, 1.5, .20, 0.961, 0.961, 0.961 );//cloud
    drawFilledCircle(1.3, 1.5, .20, 0.961, 0.961, 0.961 );//cloud

    drawFilledCircle(-2.5, 1.4, .20, 0.961, 0.961, 0.961 );//cloud
    drawFilledCircle(-2.7, 1.5, .20, 0.961, 0.961, 0.961 );//cloud
    drawFilledCircle(-2.9, 1.4, .20, 0.961, 0.961, 0.961 );//cloud
    drawFilledCircle(-2.6, 1.3, .20, 0.961, 0.961, 0.961 );//cloud
    drawFilledCircle(-2.8, 1.3, .20, 0.961, 0.961, 0.961 );//cloud


    drawFilledCircle(3.0, 1.6, .20, 1.000, 1.000, 0.000 );//cloud//Sun

    drawFilledCircle(1.0, -6.15, 7.05, 0.000, 0.392, 0.000 ); // grass

    rectangle( point(-5.0f, -.8f), point(.90f, -.8f), point(-.50f, .90f), point(-5.0f, .4f), colour(  0.000, 1.000, 1.000 ) ); // nodi
    drawFilledCircle(.1, -6.35, 7.3, 0.000, 1.000, 1.000 ); // nodi

    rectangle( point(-5.0, -5.0f), point(5.0f, -5.0f), point(5.0f, 5.0f), point(-5.0f, 5.0f), colour(0.392, 0.584, 0.929 ) ); // akash

	glutSwapBuffers(); //Send the 3D scene to the screen
}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1500, 700); //Set the window size
	//Create the window
	glutCreateWindow("Basic Shapes");
	initRendering(); //Initialize rendering
	//Set handler functions for drawing, keypresses, and window resizes
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);

	glutMainLoop(); //Start the main loop.  glutMainLoop doesn't return.
	return 0; //This line is never reached
}
