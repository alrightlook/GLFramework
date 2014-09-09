#ifndef GLFRAMEWORK_HEADER
#define GLFRAMEWORK_HEADER

#include <SDL.h>
#include <SDL_opengl.h>
#include <iostream>

class Game
{
	public:
		Game();
		virtual ~Game();

		virtual bool Init(const char* title, int x ,int y, int w, int h, Uint32 flags);
		void Run();
		void Update();
		virtual void Frame();
	private:
		bool m_bQuit;
		SDL_Window* m_MainWindow;
		SDL_GLContext m_MainGLContext;
};

#endif
