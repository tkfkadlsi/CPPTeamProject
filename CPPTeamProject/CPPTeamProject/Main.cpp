#include "Console.h"
#include "TitleScene.h"
#include "GameLogic.h"
using namespace std;

int main()
{
	Init();

	int map[8][8] = { 0, };
	PLAYER player = { };


	while (true)
	{
		bool isGameStart = TitleScene();
		if (isGameStart) break;
		else return 0;
	}
	BorderRender(8);
	while (true)
	{
		Update(map, &player);
		Render(map, &player);
	}
}