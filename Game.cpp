#include "Game.h"

Game::Game()
{
	m_bQuit = false;
	m_MainWindow = 0;
	m_MainGLContext = 0;
}

Game::~Game()
{
	SDL_GL_DeleteContext(m_MainGLContext);
	SDL_DestroyWindow(m_MainWindow);
}

bool Game::Init(const char* title, int x,int y, int w, int h, Uint32 flags)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout<<"Game Init error"<<std::endl;
		return false;
	}
	m_MainWindow = SDL_CreateWindow(title, x, y, w,h, flags);
	if( m_MainWindow == 0 ) {
		std::cout<<"Cannot create SDL window"<<std::endl;
		return false;
	}
	m_MainGLContext = SDL_GL_CreateContext(m_MainWindow);
	if( m_MainGLContext == 0) {
		std::cout<<"Cannot create GL context"<<std::endl;
		return 0;
	}
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);
	SDL_GL_SetSwapInterval(1);
	return true;
}

void Game::Update()
{
	SDL_GL_SwapWindow(m_MainWindow);
}

void Game::Frame()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	Update();
}

void Game::Run()
{
	SDL_Event e;
	while(!m_bQuit)
	{
		if( SDL_PollEvent(&e)) {
			if( e.type == SDL_QUIT) {
				m_bQuit = true;
			}
		}
		else {
			Frame();
		}
	}
}
