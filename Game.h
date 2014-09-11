#ifndef GLFRAMEWORK_HEADER
#define GLFRAMEWORK_HEADER

#include <SDL.h>
#include <GL/glew.h>
#include <iostream>
#include <GL/glu.h>

class Game
{
	public:
		Game();
		virtual ~Game();
		virtual void LoadResource();

		virtual bool Init(const char* title, int x ,int y, int w, int h, Uint32 flags);
		virtual void SetPerspective(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar);
		virtual void KeyEvent(SDL_Event* e);
		virtual void SetCamera(double posx, double posy, double posz, double dirx, double diry, double dirz, double upx, double upy, double upz);
		void Run();
		void Quit();
		void Update();
		virtual void Frame();
	private:
		bool m_bQuit;
		SDL_Window* m_MainWindow;
		SDL_GLContext m_MainGLContext;
};

#endif
