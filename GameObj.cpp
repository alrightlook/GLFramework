#include "GameObj.h"

GameObj::GameObj()
{

}

GameObj::~GameObj()
{

}

bool GameObj::Init(const char* title, int x, int y, int w, int h, Uint32 flags)
{
	bool res =  Game::Init(title, x, y, w, h, flags);
	return res;
}

void GameObj::Frame()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glBegin(GL_TRIANGLES);
		glColor3f(1.0f,0.0f,0.0f);
		glVertex3f(0.0f, 1.0f, 0.0f);

		glColor3f(0.0f,1.0f,0.0f);
		glVertex3f(-1.0f, -1.0f, 0.0f);

		glColor3f(0.0f,0.0f,1.0f);
		glVertex3f(1.0f, -1.0f, 0.0f);
	glEnd();
	glFlush();
	Update();
}
