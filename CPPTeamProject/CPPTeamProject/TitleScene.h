#pragma once

void TitleRender();

enum class MENU
{
	START, INFO, QUIT
};

enum class KEY
{
	UP, DOWN, SPACE, FALE
};

void InfoRender();
KEY KeyController();

