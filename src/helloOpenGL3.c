#include <GL/glut.h>

static int colorChange = 0;

/* Función de renderizado */
void render () {
  /* Limpieza de buffers */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  /* Carga de la matriz identidad */
  glLoadIdentity();
  /* Traslación */
  glTranslatef(0.0, 0.0, -4.0);

  /* Renderiza un triángulo blanco */
  glBegin(GL_TRIANGLES);
  if(colorChange%2 == 0){
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 1.0, 0.0);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-1.0, -1.0, 0.0);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(1.0, -1.0, 0.0);
    glEnd();
  }else{
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(0.0, 1.0, 0.0);
    glVertex3f(-1.0, -1.0, 0.0);
    glVertex3f(1.0, -1.0, 0.0);
    glEnd();
  }
  /* Intercambio de buffers */
  glutSwapBuffers();
  
  /* Redibujar fotograma */
  glutPostRedisplay();
  }

void resize (int w, int h) {
  /* Definición del viewport */
  glViewport(0, 0, w, h);

  /* Cambio a transform. vista */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  /* Actualiza el ratio ancho/alto */
  gluPerspective(50., w/(double)h, 1., 10.);

  /* Vuelta a transform. modelo */
  glMatrixMode(GL_MODELVIEW);
}

void teclado(unsigned char key, int x, int y) {
    if(key == 'c'){
    ++colorChange;
    glutPostRedisplay();
  }
}

void processMenuEvents(int id){
  switch(id){
    case 0:
      colorChange *= 2;
      break;
    case 1:
      colorChange *= 2;
      ++colorChange;
      break;
  }
}

void init (void) {
  glEnable(GL_DEPTH_TEST);
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(400, 400);
  glutInitWindowPosition(200, 200);

  glutCreateWindow("Hola Mundo con OpenGL!");

  init();

  /* Registro de funciones de retrollamada */
  glutDisplayFunc(render);
  glutReshapeFunc(resize);
  glutKeyboardFunc(teclado);
  glutCreateMenu(processMenuEvents);
  glutAddMenuEntry("Colores", 0);
  glutAddMenuEntry("Blanco", 1);
  glutAttachMenu(GLUT_RIGHT_BUTTON);

  /* Bucle de renderizado */
  glutMainLoop();

  return 0;
}