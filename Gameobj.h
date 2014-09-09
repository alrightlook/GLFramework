#ifndef GAMEOBJ_HEADER
#define GAMEOBJ_HEADER
#include "Game.h"

class GameObj :public Game
{
	public:
		GameObj();
		virtual ~GameObj();

		bool Init(const char* title, int x, int y, int w, int h, Uint32 flags);
		void Frame();
};
#endif
