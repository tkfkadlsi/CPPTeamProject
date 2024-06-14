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

void Frame(int frame);
bool Update(char map[8][8], PPLAYER pPlayer);
void Render(char map[8][8], PPLAYER pPlayer);
void BorderRender(int mapSize);
void MoveUpdate(char map[8][8], PPLAYER pPlayer);