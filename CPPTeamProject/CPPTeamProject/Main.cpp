#include "Console.h"
#include "TitleScene.h"
#include "GameLogic.h"
using namespace std;

int main()
{
	Init();

	long deltaTime = 0;
	char map[8][8] = { 0 };
	//std::fill(map[0][0], map[7][7], '0');
	PLAYER player =
	{
		player.position = { 4, 4 },
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
		if (Update(map, &player, &deltaTime) == false)
		{
			return 0;
		}
		Render(map, &player);
		Frame(60, &player, &deltaTime);
	}

	//여기서 게임 끝났을 때 버틴 시간 보여주기. 그리고 타이틀 화면으로 돌아가기
}