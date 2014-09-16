#ifndef GAMEOBJ_HEADER
#define GAMEOBJ_HEADER
#include "Game.h"
#include "Mesh.h"
#include <GL/glew.h>
#include "Shader.h"

class GameObj :public Game
{
	public:
		GameObj();
		virtual ~GameObj();

		void LoadResource();
		bool Init(const char* title, int x, int y, int w, int h, Uint32 flags);
		void SetPerspective(GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar);
		void SetCamera(double posx, double posy, double posz, double dirx, double diry, double dirz, double upx, double upy, double upz);
		void KeyEvent(SDL_Event* e);
		void Frame();
	private:
		Mesh m_Mesh;
		Shader m_Shader;
};
#endif
