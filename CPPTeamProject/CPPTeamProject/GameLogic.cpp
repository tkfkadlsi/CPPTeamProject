#include "Console.h"
#include "GameLogic.h"
bool Update(int map[8][8], PPLAYER pPlayer)
{
	map = { 0, };
	POS playerPos = pPlayer->position;

	map[playerPos.y][playerPos.x] = 1;

	return true;
}

void Render(int map[8][8], PPLAYER pPlayer)
{
	COORD mapStart =
	{ GetConsoleResolution().X / 2 - 4,
	  GetConsoleResolution().Y / 2 - 4 };

	BorderRender(8, mapStart);

	Gotoxy(mapStart.X, mapStart.Y);

	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			switch (map[y][x])
			{
			case 0:
				cout << " ";
				break;
			case 1:
				cout << "¢Ü";
				break;
			case 2:
				cout << "¡Ý";
				break;
			}
		}
	}
}

void BorderRender(int mapSize)
{
	COORD mapStartpos =
	{ GetConsoleResolution().X / 2 - 4,
	  GetConsoleResolution().Y / 2 - 4 };

	int bordersize = mapSize + 2;
	COORD borderStartpos =
	{
		mapStartpos.X - 1, mapStartpos.Y - 1
	};

	for (int i = 0; i < bordersize; i++)
	{
		for (int j = 0; j < bordersize; j++)
		{
			if (i == 0 || i == 7 && j == 0 || j == 7)
			{
				Gotoxy(borderStartpos.X + i, borderStartpos.Y + j);
				cout << "¡á";
			}
		}
	}
}
