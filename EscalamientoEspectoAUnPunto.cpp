#include <GL/glut.h>

// Coordenadas del triángulo original
GLfloat verticesOriginal[3][2] = {
	{50.0, 50.0},
{100.0, 50.0},
	{75.0, 100.0}
};

// Factor de escala
GLfloat Sx = 2.0; // Escala en el eje X
GLfloat Sy = 2.0; // Escala en el eje Y

// Punto fijo para la transformación
GLfloat xF = 55.0;
GLfloat yF = 60.0;

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 200.0);
}

void drawTriangle(GLfloat vertices[3][2]) {
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 3; i++) {
		glVertex2fv(vertices[i]);
	}
	glEnd();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	// Dibujar el triángulo original (en rojo)
	glColor3f(1.0, 0.0, 0.0);
	drawTriangle(verticesOriginal);
	
	// Aplicar la transformación de escalamiento
	for (int i = 0; i < 3; i++) {
		GLfloat x = verticesOriginal[i][0];
		GLfloat y = verticesOriginal[i][1];
		verticesOriginal[i][0] = x * Sx + (1.0 - Sx) * xF;
		verticesOriginal[i][1] = y * Sy + (1.0 - Sy) * yF;
	}
	
	// Dibujar el triángulo escalado (en verde)
	glColor3f(0.0, 1.0, 0.0);
	drawTriangle(verticesOriginal);
	
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Escalamiento respecto a un punto");
	
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	
	return 0;
}
