//#include<iostream>
//#include<Windows.h>
//using namespace std;
//
//HANDLE h;
//COORD c;
//
//int main() {
//	h = GetStdHandle(STD_OUTPUT_HANDLE);
//	unsigned char symb = 178; 
//	c.X = 0;
//	c.Y = 0;
//	SetConsoleTextAttribute(h, 10);
//	for (size_t i = 0; i < 50; i++)
//	{
//		SetConsoleCursorPosition(h, c);
//		++c.X;
//		++c.Y;
//		cout << symb<<symb << endl;
//		Sleep(15);
//		system("cls");
//	}
//}