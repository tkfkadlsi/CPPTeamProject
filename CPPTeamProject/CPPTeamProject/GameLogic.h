#pragma once

typedef struct _tagpos
{
	int x;
	int y;
	bool operator == (const _tagpos& other)
	{
		if (x == other.x && y == other.y) return true;
		else return false;
	}
}POS, *PPOS;

typedef struct _tagplayer
{
	POS position;
}PLAYER, *PPLAYER;

bool Update(int map[8][8], PPLAYER pPlayer);
void Render(int map[8][8], PPLAYER pPlayer);
void BorderRender(int mapSize, COORD mapStartpos);