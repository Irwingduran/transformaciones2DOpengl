#include <GL/glut.h>

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 800.0, 0.0, 800.0); // Configura el sistema de coordenadas (1 cm: 200 píxeles)
}

void drawTriangle() {
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0); // Color rojo
	glVertex2f(100.0, 100.0); // Vertice A
	glVertex2f(200.0, 100.0); // Vertice B
	glVertex2f(150.0, 200.0); // Vertice C
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	// Realiza la traslación de T(15, 25)
	glTranslatef(15.0, 25.0, 0.0);
	
	drawTriangle();
	
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Traslacion en OpenGL");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
