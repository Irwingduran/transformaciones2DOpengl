#include <GL/glut.h>

void drawTriangle() {
	// Tamaño y posición de los triángulos
	GLfloat size = 0.5;
	GLfloat offset = 0.1;
	
	// Triángulo original (en blanco)
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex2f(0.0, 0.0);
	glVertex2f(size, 0.0);
	glVertex2f(size / 2.0, size);
	glEnd();
	
	// Reflexión en el eje X (en rojo)
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(0.0 + size + offset, 0.0);
	glVertex2f(size + size + offset, 0.0);
	glVertex2f((size + offset) + size / 2.0, size);
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	drawTriangle();
	glFlush();
}

void init() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	gluOrtho2D(-1.0, 2.5, -1.0, 2.0); // Aumenta el rango en X para acomodar los triángulos
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutCreateWindow("Reflexiones en OpenGL");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
