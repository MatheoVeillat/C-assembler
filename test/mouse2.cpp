#include <glut.h>

void Draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	glCouleur3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
		glVertex3f(0.25, 0.25, 0.0);
		glVertex3f(0.75, 0.75, 0.0);
	glFin();
	glFlush();
}

void Initialiser() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glModeMatrix(GL_PROJECTION);
	glLoadIdentité();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int iArgc, char** cppArgv) {
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("XoaX.net");
	Initialiser();
	glutDisplayFunc(Draw);
	glutMainLoop();
	renvoie 0 ;
}