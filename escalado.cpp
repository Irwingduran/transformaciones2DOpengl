#include <GL/glut.h>

// Factor de escala en las direcciones x e y
float Sx = 15.0f;
float Sy = 20.0f;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	// Definir los vértices del triángulo original
	float triangle[][3] = {
		{0.0f, 0.0f, 1.0f},
	{1.0f, 0.0f, 1.0f},
		{0.5f, 1.0f, 1.0f}
	};
	
	// Matriz de escalamiento
	float scaleMatrix[3][3] = {
		{Sx, 0.0f, 0.0f},
	{0.0f, Sy, 0.0f},
		{0.0f, 0.0f, 1.0f}
	};
	
	// Aplicar la matriz de transformación a los vértices
	for (int i = 0; i < 3; i++) {
		float x = triangle[i][0];
		float y = triangle[i][1];
		triangle[i][0] = x * scaleMatrix[0][0] + y * scaleMatrix[0][1] + scaleMatrix[0][2];
		triangle[i][1] = x * scaleMatrix[1][0] + y * scaleMatrix[1][1] + scaleMatrix[1][2];
	}
	
	// Dibujar el triángulo escalado
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);  // Color rojo
	glVertex2f(triangle[0][0], triangle[0][1]);
	glVertex2f(triangle[1][0], triangle[1][1]);
	glVertex2f(triangle[2][0], triangle[2][1]);
	glEnd();
	
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Triángulo Escalado");
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // Color de fondo blanco
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
