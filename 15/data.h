#pragma once
#include<iostream>
#include<iomanip>
#include<conio.h>
#include<time.h>
#include<Windows.h>
using namespace std;
HANDLE h;
COORD c;

FILE* file;

typedef unsigned short ushort;
enum controllers { LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80 };
enum levels
{
		EASY=10, MEDIUM=150,HARD=500
};

enum WASD
{
	A = 97, D = 100, W = 119, S = 115
};
struct Coord {
	ushort x : 3;
	ushort y : 3;
} coord;

const levels levelArray[3]{ EASY, MEDIUM, HARD };


struct User {
	char username[50];
	char password[50];
	ushort game_field[4][4]{};
};

int length = 1;

User* users = new User[1];