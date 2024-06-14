#include "Console.h"
#include "TitleScene.h"
#include "GameLogic.h"
using namespace std;

int main()
{
	Init();

	char map[8][8] = { '0' };
	//std::fill(map[0][0], map[7][7], '0');
	PLAYER player =
	{
		player.position = { 4, 4 }
	};


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
		Frame(60);
	}
}