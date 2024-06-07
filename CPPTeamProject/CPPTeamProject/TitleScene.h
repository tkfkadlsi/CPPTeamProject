#pragma once


enum class MENU
{
	START, INFO, QUIT
};

enum class KEY
{
	UP, DOWN, SPACE, FALE
};

bool TitleScene();
void TitleRender();
void InfoRender();
MENU MenuRender();
KEY KeyController();

