#include <GL/glut.h>

static GLint rotate = 0;
static GLint incremento = 1.0;
static GLchar eje = 'a';
static GLfloat rotaY = 0.5;
static GLfloat rotaZ = 0.5;

void render () { 
  /* Limpieza de buffers */
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  /* Carga de la matriz identidad */
  glLoadIdentity();
  /* Posición de la cámara virtual (position, look, up) */
  gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  
  /* En color blanco */
  glColor3f( 1.0, 1.0, 1.0 );  
  if (eje == 'y'){
    glRotatef(rotate, 0.0, rotaY, 0.0);
  } else if (eje == 'z'){
    glRotatef(rotate, 0.0, 0.0, rotaZ);
  }

  /* Renderiza la tetera */
  glutWireTeapot(1.5);
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
  gluPerspective(50., w/(double)h, 1., 10.);

  /* Vuelta a transform. modelo */
  glMatrixMode(GL_MODELVIEW);
}

void rotar() {
  rotate = (rotate + incremento) % 360;
  glutPostRedisplay();
}

void teclado(unsigned char key, int x, int y){
  if (key == 'y'){
    eje = 'y';
    glutIdleFunc(rotar);
  } else if (key == 'z'){
    eje = 'z';
    glutIdleFunc(rotar);    
  } else if (key == 's'){
    glutIdleFunc(NULL);    
  }
}

void flechas(int key, int x, int y){
  if (key == GLUT_KEY_RIGHT){
    rotaY = 0.5;
    rotaZ = 0.5;
    glutIdleFunc(rotar);
  } else if (key == GLUT_KEY_LEFT){
    rotaY = -0.5;
    rotaZ = -0.5;
    glutIdleFunc(rotar);
  }
}

int main (int argc, char* argv[]) { 
  glutInit( &argc, argv ); 
  glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE ); 
  glutInitWindowSize(640, 480); 
  glutCreateWindow( "IVI - Sesion 2" ); 
  glEnable (GL_DEPTH_TEST);
  
  /* Registro de funciones de retrollamada */
  glutDisplayFunc(render); 
  glutReshapeFunc(resize);
  glutKeyboardFunc(teclado);
  glutSpecialFunc(flechas);
  
  /* Bucle de renderizado */
  glutMainLoop();  
  
  return 0; 
} 
