#include "GL/freeglut.h"
#include "GL/gl.h"

void drawTriangle() {
  glClearColor(0.4, 0.4, 0.4, 0.4);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 1.0);
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
  
  glBegin(GL_TRIANGLES);
  glVertex3f(-0.7, 0.7, 0);
  glVertex3f(0.7, 0.7, 0);
  glVertex3f(0, -1, 0);
  glFlush();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Hello OpenGL!!");
  glutMainLoop();
  return 0;
}
