#include "GameObj.h"

int main(int argc, char* argv[])
{
	GameObj theGame;
	theGame.Init("GLFramework Demo",100,100,640,480,SDL_WINDOW_OPENGL);
	theGame.Run();
	return 0;
}
