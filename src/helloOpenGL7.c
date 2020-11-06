#include <GL/glut.h>

#define DIST_TIERRA 3
#define DIST_LUNA_ROJA 1
#define DIST_LUNA_VERDE 2

static GLfloat tierra_rotacion = 0.0;
static GLfloat tierra_orbita = 0.0;
static GLfloat luna_roja_orbita = 0.0;
static GLfloat luna_verde_orbita = 0.0;

void render () { 
  /* Limpieza de buffers */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  /* Carga de la matriz identidad */
  glLoadIdentity();
  /* Posición de la cámara virtual (position, look, up) */
  gluLookAt (0.0, 0.0, 8.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

  /* Renderiza un Sol amarillo */
  glColor3ub (255, 186, 0);
  glutWireSphere (0.6, 16, 16);

  /* Transformaciones de la tierra */
  glRotatef(tierra_orbita, 0.0, 0.0, 1.0);
  glTranslatef(DIST_TIERRA, 0.0, 0.0);
  glRotatef(tierra_rotacion, 0.0, 0.0, 1.0);

  /* Renderiza una Tierra azul */
  glColor3ub (0, 0, 255);
  glutWireSphere (0.3, 8, 8);

  glPushMatrix();

  /* Transformaciones de la luna roja */
  glTranslatef(DIST_LUNA_ROJA, 0.0, 0.0);
  glRotatef(luna_roja_orbita, 0.0, 0.0, 1.0);

  /* Renderiza una luna roja */
  glColor3ub (255, 0, 0);
  glutWireSphere (0.15, 8, 8);

  glPopMatrix();
  glPushMatrix();

  /* Transformaciones de la luna verde */
  glTranslatef(DIST_LUNA_VERDE, 0.0, 0.0);
  glRotatef(luna_verde_orbita, 0.0, 0.0, 1.0);
  
  /* Renderiza una luna verde */
  glColor3ub (0, 255, 0);
  glutWireSphere (0.18, 8, 8);

  glPopMatrix();

  /* Intercambio de buffers... Representation ---> Window */
  glutSwapBuffers();      
} 

void resize (int w, int h) {
  /* Definición del viewport */
  glViewport(0, 0, w, h);

  /* Cambio a transform. vista */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  /* Actualiza el ratio ancho/alto */
  gluPerspective(60., w/(double)h, 1., 20.);

  /* Vuelta a transform. modelo */
  glMatrixMode(GL_MODELVIEW); 
} 

void update (unsigned char key, int x, int y) { 
  tierra_orbita += 0.2;
  tierra_rotacion += 5.8;
  luna_roja_orbita += 1.0;
  luna_verde_orbita += 1.5;
  /* Fuerza re-dibujado */
  glutPostRedisplay();
}

int main (int argc, char* argv[]) { 
  glutInit(&argc, argv); 

  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); 
  glutInitWindowSize(640, 480); 
  glutCreateWindow("IVI - Sesion 2"); 

  /* Registro de funciones de retrollamada */
  glutDisplayFunc(render); 
  glutReshapeFunc(resize);
  glutKeyboardFunc(update);

  /* Bucle de renderizado */
  glutMainLoop();  

  return 0; 
} 
