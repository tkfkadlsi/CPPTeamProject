#include "Console.h"
#include "TitleScene.h"
#include "GameLogic.h"
#include "mci.h"
#include<iostream>
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

    // 게임 시작 시간
    time_t startTime = time(NULL);

    while (true)
    {
        if (Update(map, &player, &deltaTime) == false)
        {
            // 게임 종료 시간
            time_t endTime = time(NULL);

            // 경과 시간 계산
            double duration = difftime(endTime, startTime);
            cout << "버틴 시간: " << duration << "초" << endl;

            // 타이틀 화면으로 돌아가기
            while (true)
            {
                bool isGameStart = TitleScene();
                if (isGameStart)
                {
                    // 게임 초기화
                    player.position = { 4, 4 };
                    std::fill(&map[0][0], &map[0][0] + sizeof(map), 0);
                    BorderRender(8);
                    startTime = time(NULL); // 게임 시작 시간 초기화
                    PlayBgm(TEXT("CatEscapeBGM.mp3"), 500);
                    break;
                }
                else return 0;
            }
        }
        Render(map, &player);
        Frame(60, &player, &deltaTime);
    }

    return 0;
}