#pragma once
#include"data.h"
#include"helper_func.h"
void startIntro() {
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	const char* intro[]{
	"111   5555555    GGGGGGG      AAA       MMM    MMM   EEEEEEEE  ",
	"111   55         GG    G     AA AA      MMM    MMM   EE    EE ",
	"111   55         GG         AA   AA     MM M  M MM   EE        ",
	"111   5555555    GG         AA   AA     MM  MM  MM   EEEEEEEE  ",
	"111         55   GG  GGG    AAAAAAA     MM  MM  MM   EE        " ,
	"111         55   GG   GG    AA   AA     MM      MM   EE    EE  ",
	"111    555555    GGGGGGG    AA   AA     MM      MM   EEEEEEEE  "
	};

	c.X = 20;
	c.Y = 0;
	
for (size_t i = 0; i < 7; i++)
{	SetConsoleCursorPosition(h, c);
	++c.Y;
	for (size_t j = 0; j < strlen(intro[i]); j++){
		cout << intro[i][j];
	Sleep(5);

}
cout << endl;
}
Sleep(100);
system("cls");
}

void menu_color(int a) {

	h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, a);
}

void win_animation() {
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (size_t i = 0; i < 10; i++)
	{
		if (i % 2 == 0) {
			SetConsoleTextAttribute(h, 5);
		}
		else {
			SetConsoleTextAttribute(h, 9);
		}
		cout << "YOU WIN!!" << endl;
		Sleep(100);
		Beep(1500, 100);
		system("cls");
		cout << " ";

		system("cls");
	}
}

ushort menu(const char* Menu[], ushort length) {
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	unsigned char key{};
	short menuPos = 0;

	
	while (true)
	{   
		menuPos %= length;
		if (menuPos < 0) menuPos = length - 1;
		c.X = 40;
	    c.Y = 10;
		for (size_t i = 0; i < length; i++)
		{
			SetConsoleCursorPosition(h, c);
			++c.Y;
			menu_color(79);
			if (i == menuPos)
				cout << ">" << Menu[i] << setw(10) << ' ' << endl;
			else {
				menu_color(15);
				cout << " " << Menu[i] << setw(10) << ' ' << endl;
			}

		}
		key = _getch();
		if (key == 224) {
			key = _getch();
			switch (key)
			{

			case UP:
				menuPos--;
				break;
			case DOWN:
				menuPos++;
				break;

			}
		}
		else {
			if (key == 13) {
				return menuPos + 1;

			}
		}

		system("cls");
	}


}


void showFields(ushort game_field[][4]) {
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			if (game_field[i][j] == 16) {
				SetConsoleTextAttribute(h, 0);
				

			}
			else if (isRightPosition(game_field, Coord{ ushort(i),ushort(j) })) 
			{
					SetConsoleTextAttribute(h, 10);
				}
				else 
			{ 
				SetConsoleTextAttribute(h, 4); 
			}
				cout << setw(5) << right << game_field[i][j];
				SetConsoleTextAttribute(h, 0);
		}
		cout << endl << endl;

	}
}
