#include<iostream>
#include<conio.h>
#include<io.h>
#include<fcntl.h>

#include"TitleScene.h"

using namespace std;

void TitleRender()
{
	int beforemode = _setmode(_fileno(stdout), _O_U16TEXT);

	//SetColor((int)COLOR::BLUE, (int)COLOR::BLACK);
	wcout << L"██████╗  ██████╗ ███╗   ███╗██████╗ ███╗   ███╗ █████╗ ███╗   ██╗" << endl;
	wcout << L"██╔══██╗██╔═══██╗████╗ ████║██╔══██╗████╗ ████║██╔══██╗████╗  ██║" << endl;
	wcout << L"██████╔╝██║   ██║██╔████╔██║██████╔╝██╔████╔██║███████║██╔██╗ ██║" << endl;
	wcout << L"██╔══██╗██║   ██║██║╚██╔╝██║██╔══██╗██║╚██╔╝██║██╔══██║██║╚██╗██║" << endl;
	wcout << L"██████╔╝╚██████╔╝██║ ╚═╝ ██║██████╔╝██║ ╚═╝ ██║██║  ██║██║ ╚████║" << endl;
	wcout << L"╚═════╝  ╚═════╝ ╚═╝     ╚═╝╚═════╝ ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝" << endl;

	int curoremode = _setmode(_fileno(stdout), beforemode);
}
void InfoRender()
{
	system("cls");
	cout << "조작법" << endl;
	cout << "스토리" << endl;
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

