#include "GameObj.h"

GameObj::GameObj()
{

}

GameObj::~GameObj()
{

}
void GameObj::KeyEvent(SDL_Event* e)
{
	if(e == 0) {
		return ;
	}
	if(e->key.keysym.sym == SDLK_ESCAPE) {
		Quit();
	}
}

bool GameObj::Init(const char* title, int x, int y, int w, int h, Uint32 flags)
{
	bool res =  Game::Init(title, x, y, w, h, flags);
	SetPerspective(45.0f, 1.0f, 1.0f, 1000.0f);
	SetCamera(0.0f, 0.0f, -10.0f, 0.0f, 0.0f, 0.0f ,0.0f ,1.0f, 0.0f);
	return res;
}
void GameObj::SetCamera(double posx, double posy, double posz, double dirx, double diry, double dirz, double upx, double upy, double upz)
{
	Game::SetCamera(posx, posy, posz, dirx, diry, dirz, upx, upy, upz);
}

void GameObj::SetPerspective(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar)
{
	Game::SetPerspective( fovy, aspect, zNear, zFar);
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
