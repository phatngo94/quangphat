#include<iostream>
#include<windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

void drawBox();
void drawBird ();
void drawFunnel1 ();
void drawFunnel2();
void drawFunnel3();
void moveBird();
void startGame();
void moveFunnel();
void check();
void checkScore();
void ShowConsoleCursor(bool showFlag);

struct node {
	int xpos;
	int ypos;
};


node Funnel[30];
int FU1, FD1; int FU2, FD2; int FU3, FD3;
int y = 13;
int X1 = 63; int X2 = 63; int X3 = 63;
int checkF1 = 0; int checkF2 = 0; int checkF3 = 0;
int T1 = 1; int T2 = 0; int T3 = 0;
int score = 0;
boolean run = true;

void gotoXY(int x,int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

node Bird[4] = { node{11,8},node{11,9},node{10,8},node{10,9} };
int main() {

	startGame();
	gotoXY(78, 9);
	cout << "GAME OVER !";
	Sleep(4000);
	return 1;
}

void drawBox() {

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 68; j++) {
			if (i == 0 || i == 14 || j == 0 || j == 67) {
				cout << "0";
			}
			else {
				cout << " ";
			}
			
		}
		cout << "\n";
	}
}

void drawBird() {
	for (int i = 0; i < 4; i++) {
		gotoXY(Bird[i].xpos, Bird[i].ypos);
		cout << "*";
		
	}
}


void moveBird() {
	if (GetAsyncKeyState(VK_UP)) {
		for (int i = 0; i < 4; i++) {
			Bird[i].ypos--;
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			Bird[i].ypos++;
		}
	}
}

void drawFunnel1() {

	if (checkF1 == 0) {
		//srand(time(NULL));
		srand((int)time(0));
		FU1 = rand() % (6 - 2 + 1) + 2;
	}


	FD1 = 8 - FU1;
	int x1;
	int giu = 12;
	x1 = X1;
	for (int i = 0; i< FU1; i++) {
		for (int j = 0; j < 3; j++) {

			gotoXY(x1, y - giu);

			if (i == 0 || i == FU1-1 || j == 0 || j == 2) {
				cout << "0";
			}
			else {
				cout << " ";
			}
			cout << "\n";
			x1++;
		}
		x1 = X1;
		giu--;

	}
	for (int i = 0; i < FD1; i++) {
		for (int j = 0; j < 3; j++) {
			gotoXY(x1, y);
			if (i == 0 || i == FD1-1 || j == 0 || j == 2) {
				cout << "0";
			}
			else {
				cout << " ";
			}
			cout << "\n";
			x1++;
		}
		x1 = X1;
		y--;

	}
	//y = 13;
	//x = 50;

	checkF1 = 1;
}

void drawFunnel2() {
	
	if (checkF2 == 0) {
		//srand(time(NULL));
		srand((int)time(0));
		FU2 = rand() % (6 - 2 + 1) + 2;
	}
	
	
	FD2 = 8 - FU2;
	int x1;
	int giu=12;
	x1 = X2;
	for (int i = 0; i < FU2; i++) {
		for (int j = 0; j < 3; j++) {
			ShowConsoleCursor(false);
			gotoXY(x1, y-giu);
			
			if (i == 0 || i == FU2-1 || j == 0 || j == 2) {
				cout << "0";
			}
			else {
				cout << " ";
			}
			cout << "\n";
			x1++;
		}
		x1 = X2;
		giu--;
		
	}
	for (int i = 0; i < FD2; i++) {
		for (int j = 0; j < 3; j++) {
			ShowConsoleCursor(false);
			gotoXY(x1, y);
			if (i == 0 || i == FD2-1 || j == 0 || j == 2) {
				cout << "0";
			}
			else {
				cout << " ";
			}
			cout << "\n";
			x1++;
		}
		x1 = X2;
		y--;
		
	}
	//y = 13;
	//x = 50;
	
	checkF2 = 1;
}

void drawFunnel3() {

	if (checkF3 == 0) {
		srand((int)time(0));
		FU3 = rand() % (6 - 2 + 1) + 2;
	}


	FD3 = 8 - FU3;
	int x1;
	int giu = 12;
	x1 = X3;
	for (int i = 0; i < FU3; i++) {
		for (int j = 0; j < 3; j++) {
			ShowConsoleCursor(false);
			gotoXY(x1, y - giu);

			if (i == 0 || i == FU3-1 || j == 0 || j == 2) {
				cout << "0";
			}
			else {
				cout << " ";
			}
			cout << "\n";
			x1++;
		}
		x1 = X3;
		giu--;

	}
	for (int i = 0; i < FD3; i++) {
		for (int j = 0; j < 3; j++) {
			ShowConsoleCursor(false);
			gotoXY(x1, y);
			if (i == 0 || i == FD3-1 || j == 0 || j == 2) {
				cout << "0";
			}
			else {
				cout << " ";
			}
			cout << "\n";
			x1++;
		}
		x1 = X3;
		y--;

	}
	//y = 13;
	//x = 50;

	checkF3 = 1;
}


void moveFunnel() {
	
	if (T1 == 1) {
		gotoXY(X1, y);
		drawFunnel1();
		if (X1 == 42) {
			T2 = 1;
		}
		if (X1 == 9) {
			score++;
		}
		X1--;
		if (X1 == 0) {
			X1 = 63;
			checkF1 = 0;
		}
		y = 13;
	}
	if (T2 == 1) {
		gotoXY(X2, y);
		drawFunnel2();
		if (X2 == 42) {
			T3 = 1;
		}
		if (X2 == 9) {
			score++;
		}
		X2--;
		if (X2 == 0) {
			X2 = 63;
			checkF2 = 0;
		}
		y = 13;

	}
	if (T3 == 1) {
		gotoXY(X3, y);
		drawFunnel3();
		/*if (X3 == 21) {
			T3 = 1;
		}*/
		if (X3 == 9) {
			score++;
		}
		X3--;
		if (X3 == 0) {
			X3 = 63;
			checkF3 = 0;
		}
		y = 13;

	}
	
}


void check() {
	if (Bird[0].ypos < 0 || Bird[1].ypos > 14) {
		run = false;
	}
	else if (((Bird[0].ypos <= FU1 || Bird[1].ypos>=FU1+8)&& (Bird[0].xpos==X1))
		|| ((Bird[0].ypos <= FU2 || Bird[1].ypos >= FU2+8) && Bird[0].xpos == X2 )
		|| ((Bird[0].ypos <= FU3 || Bird[1].ypos >= FU3 + 8)&& Bird[0].xpos == X3))
		
	{
		run = false;
	}
	else if ((((Bird[0].ypos <= FU1 || Bird[1].ypos >= FU1 + 8) && (Bird[0].xpos == X1 + 1))
		|| ((Bird[0].ypos <= FU2 || Bird[1].ypos >= FU2 + 8)&& Bird[0].xpos == X2 + 1)
		|| ((Bird[0].ypos <= FU3 || Bird[1].ypos >= FU3 + 8) && Bird[0].xpos == X3 + 1)))
	{
		run = false;
	}
	else if ((((Bird[0].ypos <= FU1 || Bird[1].ypos >= FU1 + 8) && (Bird[0].xpos == X1 + 2))
		|| ((Bird[0].ypos <= FU2 || Bird[1].ypos >= FU2 + 8) && Bird[0].xpos == X2 + 2)
		|| ((Bird[0].ypos <= FU3 || Bird[1].ypos >= FU3 + 8) && Bird[0].xpos == X3 + 2)))
	{
		run = false;
	}
	
}

void checkScore() {


}

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}
void startGame() {

	while (run)
	{
		ShowConsoleCursor(false);
		gotoXY(0,0);
		drawBox();
		drawBird();
		moveFunnel();
		moveBird();
		check();
		gotoXY(78, 8);
		cout << "Score: " << score;
		Sleep(50);
	}
	
	
}