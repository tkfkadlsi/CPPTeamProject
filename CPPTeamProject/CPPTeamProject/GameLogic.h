#pragma once
#include <vector>
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
	long waitMSForMove = 100;
	long countMoveTime = 0;

	long superGuardTime = 0;
	long superGuardCoolTime = 5000;
	long countSuperGuardCoolDown = 5000;
}PLAYER, *PPLAYER;

typedef struct _tagarrow
{
	POS position;
	int spawnDir;
	long countwaitTime;
	bool isBombed = false;
	long countAfterBombTime;

	bool operator==(_tagarrow other)
	{
		return
			position == other.position &&
			spawnDir == other.spawnDir &&
			countwaitTime == other.countwaitTime &&
			isBombed == other.isBombed &&
			countAfterBombTime == countAfterBombTime;
	}
}ARROW, *PARROW;

void Frame(int frame, PPLAYER pPlayer, long* deltaTime);
bool Update(char map[8][8], PPLAYER pPlayer, long* deltaTime);
void Render(char map[8][8], PPLAYER pPlayer, time_t currentTime);
void BorderRender(int mapSize);
void MoveUpdate(char map[8][8], PPLAYER pPlayer);
void CreateArrow(char map[8][8], PPLAYER pPlayer, std::vector<ARROW>& arrowVec, COORD mapStart, long* deltaTime);
void ActiveArrow(char map[8][8], std::vector<ARROW>& arrowVec, COORD mapStart, long* deltaTime);
void DeleteArrow(char map[8][8], std::vector<ARROW>& arrowVec, COORD mapStart, long* deltaTime);
