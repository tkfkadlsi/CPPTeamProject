#include "Console.h"
#include "GameLogic.h"
#include "mci.h"
void Frame(int frame)
{
	clock_t oldtime, curtime;
	oldtime = clock();

	while (true)
	{
		curtime = clock();
		if (curtime - oldtime > 1000 / frame)
		{
			oldtime = curtime;
			break;
		}
	}
}
bool Update(char map[8][8], PPLAYER pPlayer)
{
	MoveUpdate(map, pPlayer);

	POS playerPos = pPlayer->position;

	map[playerPos.y][playerPos.x] = '1';

	return true;
}

void Render(char map[8][8], PPLAYER pPlayer)
{
	COORD mapStart =
	{ GetConsoleResolution().X / 2 - 4,
	  GetConsoleResolution().Y / 2 - 4 };


	for (int y = 0; y < 8; y++)
	{
		Gotoxy(mapStart.X, mapStart.Y + y);
		for (int x = 0; x < 8; x++)
		{
			switch (map[y][x])
			{
			case '0':
				cout << "бр";
				break;
			case '1':
				cout << "в▄";
				break;
			case '2':
				cout << "б▌";
				break;
			}
		}
		cout << '\n';
	}
}

void BorderRender(int mapSize)
{
	PlayBgm(TEXT("CatEscapeBGM.mp3"), 500);

	SetColor((int)COLOR::WHITE, (int)COLOR::WHITE);
	COORD mapStartpos =
	{ GetConsoleResolution().X / 2 - 4,
	  GetConsoleResolution().Y / 2 - 4 };

	int bordersize = mapSize + 2;
	COORD borderStartpos =
	{
		mapStartpos.X - 2, mapStartpos.Y - 1
	};

	for (int i = 0; i < bordersize; i++)
	{
		for (int j = 0; j < bordersize; j++)
		{
			if ((i == 0 || i == 9) || (j == 0 || j == 9))
			{
				Gotoxy(borderStartpos.X + i * 2, borderStartpos.Y + j);
				cout << "бс";
			}
		}
	}
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
}

void MoveUpdate(char map[8][8], PPLAYER pPlayer)
{
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		if (pPlayer->position.y == 0) return;
		map[pPlayer->position.y][pPlayer->position.x] = '0';
		--pPlayer->position.y;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		if (pPlayer->position.y == 7) return;
		map[pPlayer->position.y][pPlayer->position.x] = '0';
		++pPlayer->position.y;
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{
		if (pPlayer->position.x == 0) return;
		map[pPlayer->position.y][pPlayer->position.x] = '0';
		--pPlayer->position.x;
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		if (pPlayer->position.x == 7) return;
		map[pPlayer->position.y][pPlayer->position.x] = '0';
		++pPlayer->position.x;
	}
}
