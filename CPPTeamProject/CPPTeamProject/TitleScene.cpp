#include <iostream>
#include<conio.h>
#include<io.h>
#include<fcntl.h>
#include<windows.h>

#include "TitleScene.h"
#include "Console.h"

using namespace std;

void TitleRender()
{
	Gotoxy(0, 0);
	int beforemode = _setmode(_fileno(stdout), _O_U16TEXT);

	//SetColor((int)COLOR::BLUE, (int)COLOR::BLACK);
	wcout << L"████████╗██╗████████╗██╗     ███████╗    ███████╗ ██████╗███████╗███╗   ██╗███████╗" << endl;
	wcout << L"╚══██╔══╝██║╚══██╔══╝██║     ██╔════╝    ██╔════╝██╔════╝██╔════╝████╗  ██║██╔════╝" << endl;
	wcout << L"   ██║   ██║   ██║   ██║     █████╗      ███████╗██║     █████╗  ██╔██╗ ██║█████╗  " << endl;
	wcout << L"   ██║   ██║   ██║   ██║     ██╔══╝      ╚════██║██║     ██╔══╝  ██║╚██╗██║██╔══╝  " << endl;
	wcout << L"   ██║   ██║   ██║   ███████╗███████╗    ███████║╚██████╗███████╗██║ ╚████║███████╗" << endl;
	wcout << L"   ╚═╝   ╚═╝   ╚═╝   ╚══════╝╚══════╝    ╚══════╝ ╚═════╝╚══════╝╚═╝  ╚═══╝╚══════╝" << endl;

	int curoremode = _setmode(_fileno(stdout), beforemode);
}


void InfoRender()
{
	system("cls");
	cout << "조작법" << endl;
	cout << "게임 설명" << endl;
	cout << "제작" << endl;
	Sleep(100);
	while (true)
	{
		if (KeyController() == KEY::SPACE)
		{
			system("cls");
			break;
		}
	}
}

void EnterAnimation()
{
	COORD xy = GetConsoleResolution();

	int x = xy.X;
	int y = xy.Y;

	SetColor((int)COLOR::WHITE, (int)COLOR::WHITE);

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			cout << "■";
		}
		cout << '\n';
		Sleep(250);
	}

	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	system("cls");
}

MENU MenuRender()
{
    COORD Resolution = GetConsoleResolution(); // 해상도 출력
    int x = Resolution.X / 4.5;
    int y = Resolution.Y / 4;
    int originy = y;

    Gotoxy(x - 2, y); // 화살표 처음 위치에 출력
    cout << ">";
    Gotoxy(x, y);
    cout << "게임 시작";
    Gotoxy(x, y + 1);
    cout << "게임 정보";
    Gotoxy(x, y + 2);
    cout << "게임 종료";

    while (true)
    {
        // 키 입력이 된 것을 받아옴
        KEY ekey = KeyController();

        switch (ekey)
        {
            // 화살표 출력
            // 화살표 지우기
        case KEY::UP:
        {
            if (y > originy)
            {
                Gotoxy(x - 2, y);
                cout << " ";
                Gotoxy(x - 2, --y);
                cout << ">";
                Sleep(100);
            }
        }
        break;
        case KEY::DOWN:
        {
            if (y < originy + 2)
            {
                Gotoxy(x - 2, y);
                cout << " ";
                Gotoxy(x - 2, ++y);
                cout << ">";
                Sleep(100);
            }
        }
        break;
        case KEY::SPACE:
        {
            if (originy == y)
                return MENU::START;

            else if (originy + 1 == y)
                return MENU::INFO;

            else if (originy + 2 == y)
                return MENU::QUIT;
        }
        break;
        }
    }

    return MENU::INFO;
}


KEY KeyController()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		return KEY::UP;
	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		return KEY::DOWN;
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		return KEY::SPACE;
	}

	return KEY::FALE;
}

void Init()
{
	SetCursorVis(false, 40);
	system("title cppteamproject | mode con cols=120 lines=60");
}

bool TitleScene()
{
	TitleRender();
	while (true)
	{
		MENU eMenu = MenuRender();

		switch (eMenu)
		{
		case MENU::START:
			EnterAnimation();
			return true;
		case MENU::INFO:
			InfoRender();
			break;
		case MENU::QUIT:
			return false;
			break;
		}
	}
}
