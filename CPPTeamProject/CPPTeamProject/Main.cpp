#include "Console.h"
#include "TitleScene.h"
#include "GameLogic.h"
#include "mci.h"
#include<iostream>
#include<conio.h>
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
		while (true)
		{
			bool isGameStart = TitleScene();
			if (isGameStart) break;
			else return 0;
		}
		BorderRender(8);
		// 게임 시작 시간
		time_t startTime = time(NULL);
		while (true)
		{
			if (Update(map, &player, &deltaTime) == false)
			{
				break;
			}
			Render(map, &player);
			Frame(60, &player, &deltaTime);
		}
		time_t endTime = time(NULL);
		// 게임 종료 시간


		system("cls");
		// 경과 시간 계산
		double duration = difftime(endTime, startTime);
		cout << "버틴 시간: " << duration << "초" << endl;
		Sleep(500);
		cout << "잠시 후 타이틀로 돌아갑니다.";

		Sleep(3000);
	}
	return 0;
}

