
#include <Tail.h>
#include <glut.h>
#include <window.h>
#include <Grid.h>
#include <Head.h>
#include <Vector.h>


#define COLUMNS 100
#define ROWS 100
#define FPS 30

Vector pos(ROWS / 2, COLUMNS / 2);
Head curHead(ROWS, COLUMNS, pos, 1);
Tail curTail;


void Display() {
	glClear(GL_COLOR_BUFFER_BIT);
	Grid curGrid(COLUMNS, ROWS);
	curGrid.DrawGrid();
	curTail.AddNew(curHead);
	curHead.DrawHead(curHead);
	curTail.DrawTail(curTail);
	glutSwapBuffers();
}
void Reshape(int curWidth, int CurHeight)
{
	glViewport(0, 0, (GLsizei)curWidth, (GLsizei)CurHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, COLUMNS, 0.0, ROWS, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}
void Timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, Timer, 0);
}

void Keyboard(int key, int, int){
	switch (key)
	{
	case GLUT_KEY_UP:
		if(curHead.resultVec.getY() < 2)
		{
			Vector upVec(0, 1);
			curHead.resultVec += upVec;
		}
		break;
	case GLUT_KEY_DOWN:
		if (curHead.resultVec.getY() > -2)
		{
			Vector downVec(0, -1);
			curHead.resultVec += downVec;
		}
		break;
	case GLUT_KEY_RIGHT:
		if (curHead.resultVec.getX() < 2)
		{
			Vector rightVec(1, 0);
			curHead.resultVec += rightVec;
		}
		break;
	case GLUT_KEY_LEFT:
		if (curHead.resultVec.getX() > -2)
		{
			Vector leftVec(-1, 0);
			curHead.resultVec += leftVec;
		}
		break;
	default:
		//curHead.resultVec = curHead.resultVec*0.9;
		break;
	}
}

void Initialize() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	
}
int main(int argc, char ** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB);
	//Window curWindow;
	Window curWindow(800,800,400,200,"My first glut project");
	curWindow.initilization();
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutTimerFunc(0, Timer, 0);
	glutSpecialFunc(Keyboard);
	Initialize();
	glutMainLoop();
	return 0;
}