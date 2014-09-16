#include "GameObj.h"
#include "Mesh.h"
#include <GL/glew.h>
#include <iostream>

GameObj::GameObj()
{

}

GameObj::~GameObj()
{

}

void GameObj::LoadResource()
{
	GLfloat tri[9] = { 0.0f, 1.0f, 0.0f, -1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 0.0f};
	GLfloat col[9] = { 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f};

	m_Mesh.setColor(col, 9);
	m_Mesh.setData(tri, 9);
	m_Mesh.init();
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
	glewInit();
	SetPerspective(45.0f, 1.0f, 1.0f, 1000.0f);
	SetCamera(0.0f, 0.0f, -10.0f, 0.0f, 0.0f, 0.0f ,0.0f ,1.0f, 0.0f);
	LoadResource();
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
	m_Mesh.draw();
	/*
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
	*/
	Update();
}
