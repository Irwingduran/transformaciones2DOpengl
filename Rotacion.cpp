#include <GL/glut.h>
#include <math.h>

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
	
	// Realiza la rotación de 45 grados
	float angle = 45.0; // Ángulo de rotación en grados
	float radian = angle * M_PI / 180.0; // Convierte a radianes
	glTranslatef(150.0, 150.0, 0.0); // Translada el triángulo al origen
	glRotatef(angle, 0.0, 0.0, 1.0); // Realiza la rotación
	glTranslatef(-150.0, -150.0, 0.0); // Translada de nuevo al lugar original
	
	drawTriangle();
	
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Rotacion en OpenGL");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
