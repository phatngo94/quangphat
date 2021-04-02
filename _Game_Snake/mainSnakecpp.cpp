#include <iostream>
#include <windows.h>

#include <cstdlib>
#include <ctime>
using namespace std;
//khai bao toa do cua node
struct node {
	int xpos;
	int ypos;

};

node Snake[100]= { node{9,7},node{8,7},node{7,7} };//Khoi tao con Ran co so dot toi da la 100;
int dot = 3;// Khoi tao con Ran ban dau co 3 dot
boolean run = true;//Bien kiem tra vong lap game co ket thuc khong 
int direc = 1; // Bien kiem tra huong duy chuyen cua Ran 1=Right | 2=LEFT | 3=UP 4=DOWN
node fruit = {10,10};
void gotoXY(int x, int y) ; // Ham duy chuyen con tro chout den vi tri chi dinh
//int checkkey = 0; //Bien kiem tra xem Ran se duy chuyen theo nguoi choi lua chon hay duy chuyen thang tu do



void drawBox() ; //ve khung gioi han di chuyen
void drawSnake() ; //ve toa do cua Ran
void drawfruit() ; // Ve moi ma Ran can phai an
void checkWall() ; //Kiem tra xam Ran co va vao tuong(khung gioi han di chuyen) khong hoac tu an chinh minh 
void checkDirection() ; //kiem tra xem Ran dang duy chuyen theo huong nao 
void moveSnake() ; // Tao di chuyen cho Ran
void snakeEat() ;
void swapNode(node nodesnake, node itemNodeDau, node itemNodeGiu) ; // Ham ho tro cap nhap lai cac dot cua Ran ki duy chuyen
void startGame() ;
void ShowConsoleCursor(bool showFlag);// ham xoa con tro chuot
void reSetSnake() ;
void checkbody();




int main() {

	startGame();
	ShowConsoleCursor(false);
	gotoXY(25, 17);
	cout << "GAME OVER";
	Sleep(3000);
	return 1;
}


void gotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Khung co gioi han x=20 y=20 tren truc toa do
void drawBox() {

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (i == 0 || i == 19 || j == 0 || j == 19) {
				cout << "o";
			}
			else {
				cout << " ";
			}
		}
		cout << "\n";
	}
}

void drawSnake() {
	for (int i = 0; i < dot; i++) {
		ShowConsoleCursor(false);
		gotoXY(Snake[i].xpos, Snake[i].ypos);
		cout << "*";
	}
}

void drawfruit() {
	ShowConsoleCursor(false);
	gotoXY(fruit.xpos, fruit.ypos);
	cout << "@";

}

void checkWall() {
	if (Snake[0].xpos == 0 || Snake[0].xpos == 19 || Snake[0].ypos == 0 || Snake[0].ypos == 19) {
		run = false;
	}
}

void checkDirection() {
	if (Snake[0].xpos == Snake[1].xpos - 1) {
		direc = 1;  //xpos-- Con Ran dang di chuyen sang trai
	}
	else if (Snake[0].xpos == Snake[1].xpos + 1)
	{
		direc = 2; //xpos++ Con Ran dang duy chuyen sang phai
	}
	else if (Snake[0].ypos == Snake[1].ypos + 1) {
		direc = 3; //ypos++ Con Ran dang duy chuyen xuong duoi
	}
	else if (Snake[0].ypos == Snake[1].ypos - 1) {
		direc = 4; //ypos-- Con Ran dang di chuyen len tren
	}
}

void swapNode(node nodesnake, node itemNodeDau, node itemNodeGiu) {
	itemNodeGiu = nodesnake;
	nodesnake = itemNodeDau;
	itemNodeDau = itemNodeGiu;
}


void snakeEat() {
	if (Snake[0].xpos == fruit.xpos && Snake[0].ypos == fruit.ypos) {
		srand(time(0));
		int x = rand() % (16 - 1) + 1;
		int y = rand() % (16- 1) + 1;
		fruit.xpos = x;
		fruit.ypos = y;
		if (direc == 1) {
			node nodeitemdau;
			node nodeiteamGiu;
			nodeitemdau = Snake[0];
			Snake[0].xpos--;
			for (int i = 1; i < dot; i++) {
				nodeiteamGiu = Snake[i];
				Snake[i] = nodeitemdau;
				nodeitemdau = nodeiteamGiu;
			}
			dot++;
			Snake[dot]=nodeitemdau;
		}
		else if (direc == 2) {
			node nodeitemdau;
			node nodeiteamGiu;
			nodeitemdau = Snake[0];
			Snake[0].xpos++;
			for (int i = 1; i < dot; i++) {
				nodeiteamGiu = Snake[i];
				Snake[i] = nodeitemdau;
				nodeitemdau = nodeiteamGiu;
			}
			dot++;
			Snake[dot] = nodeitemdau;
		}
		else if (direc == 3) {
			node nodeitemdau;
			node nodeiteamGiu;
			nodeitemdau = Snake[0];
			Snake[0].ypos++;
			for (int i = 1; i < dot; i++) {
				nodeiteamGiu = Snake[i];
				Snake[i] = nodeitemdau;
				nodeitemdau = nodeiteamGiu;
			}
			dot++;
			Snake[dot] = nodeitemdau;
		}
		else if (direc == 4) {
			node nodeitemdau;
			node nodeiteamGiu;
			nodeitemdau = Snake[0];
			Snake[0].ypos--;
			for (int i = 1; i < dot; i++) {
				nodeiteamGiu = Snake[i];
				Snake[i] = nodeitemdau;
				nodeitemdau = nodeiteamGiu;
			}
			dot++;
			Snake[dot] = nodeitemdau;
		}
	}
}

void moveSnake() {
	int checkkey = 0;
	if (GetAsyncKeyState(VK_UP) && 0x8000 != 0) {
		checkkey = 1;
		if ( direc !=3 && direc!=4) { ///khong cho phep Ran di nguoc chieu dang di chuyen va chi cho phep di chuyen khac huong
			node nodeitemdau;
			node nodeiteamGiu;
			nodeitemdau = Snake[0];
			Snake[0].ypos--;
			for (int i = 1; i < dot; i++) {

				//swapNode(Snake[i], nodeitemdau, nodeiteamGiu);
				nodeiteamGiu = Snake[i];
				Snake[i] = nodeitemdau;
				nodeitemdau = nodeiteamGiu;
			}
		}

	}
	else if (GetAsyncKeyState(VK_DOWN) && 0x8000 != 0) {
		checkkey = 1;
		if (direc !=3 && direc != 4) { ///khong cho phep Ran di nguoc chieu dang di chuyen va chi cho phep di chuyen khac huong
			node nodeitemdau;
			node nodeiteamGiu ;
			nodeitemdau = Snake[0];
			Snake[0].ypos++;
			for (int i = 1; i < dot; i++) {

				//swapNode(Snake[i], nodeitemdau, nodeiteamGiu);
				nodeiteamGiu = Snake[i];
				Snake[i] = nodeitemdau;
				nodeitemdau = nodeiteamGiu;
			}
		}

	}
	else if (GetAsyncKeyState(VK_LEFT) && 0x8000 != 0) {
		checkkey = 1;
		if (direc !=1 && direc!= 2) { ///khong cho phep Ran di nguoc chieu dang di chuyen va chi cho phep di chuyen khac huong
			node nodeitemdau;
			node nodeiteamGiu;
			nodeitemdau = Snake[0];
			Snake[0].xpos--;
			for (int i = 1; i < dot; i++) {

				//swapNode(Snake[i], nodeitemdau, nodeiteamGiu);
				nodeiteamGiu = Snake[i];
				Snake[i] = nodeitemdau;
				nodeitemdau = nodeiteamGiu;
			}
		}

	}
	else if (GetAsyncKeyState(VK_RIGHT) && 0x8000 != 0) {
		checkkey = 1;
		if (direc !=1 && direc != 2) { ///khong cho phep Ran di nguoc chieu dang di chuyen va chi cho phep di chuyen khac huong
			node nodeitemdau; 
			node nodeiteamGiu;
			nodeitemdau = Snake[0];
			Snake[0].xpos++;
			for (int i = 1; i < dot; i++) {

				//swapNode(Snake[i], nodeitemdau, nodeiteamGiu);
				nodeiteamGiu = Snake[i];
				Snake[i] = nodeitemdau;
				nodeitemdau = nodeiteamGiu;
			}
		}

	}

	if (checkkey != 1) {
		if (direc == 1) {
			node nodeitemdau;
			node nodeiteamGiu;
			nodeitemdau = Snake[0];
			Snake[0].xpos--;
			for (int i = 1; i < dot; i++) {

				//swapNode(Snake[i], nodeitemdau, nodeiteamGiu);
				nodeiteamGiu = Snake[i];
				Snake[i] = nodeitemdau;
				nodeitemdau = nodeiteamGiu;
			}
		}
		if (direc == 2) {
			node nodeitemdau;
			node nodeiteamGiu;
			nodeitemdau = Snake[0];
			Snake[0].xpos++;
			for (int i = 1; i < dot; i++) {

				//swapNode(Snake[i], nodeitemdau, nodeiteamGiu);
				nodeiteamGiu = Snake[i];
				Snake[i] = nodeitemdau;
				nodeitemdau = nodeiteamGiu;
			}
		}
		if (direc == 3) {
			node nodeitemdau;
			node nodeiteamGiu;
			nodeitemdau = Snake[0];
			Snake[0].ypos++;
			for (int i = 1; i < dot; i++) {

				//swapNode(Snake[i], nodeitemdau, nodeiteamGiu);
				nodeiteamGiu = Snake[i];
				Snake[i] = nodeitemdau;
				nodeitemdau = nodeiteamGiu;
			}
		}
		if (direc == 4) {
			node nodeitemdau;
			node nodeiteamGiu;
			nodeitemdau = Snake[0];
			Snake[0].ypos--;
			for (int i = 1; i < dot; i++) {

				//swapNode(Snake[i], nodeitemdau, nodeiteamGiu);
				nodeiteamGiu = Snake[i];
				Snake[i] = nodeitemdau;
				nodeitemdau = nodeiteamGiu;
			}
		}
	}
}

void reSetSnake() {
	for(int i=0;i<dot;i++){
		ShowConsoleCursor(false);
		gotoXY(Snake[i].xpos, Snake[i].ypos);
		cout << " ";
	}
}

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void checkbody() {
	for (int i = 1; i < dot; i++) {
		if (Snake[0].xpos == Snake[i].xpos && Snake[0].ypos == Snake[i].ypos) {
			run = false;
			break;
		}

	}
}


void startGame() {
	while (run)
	{
		ShowConsoleCursor(false);
		reSetSnake();
		gotoXY(0, 0);
		drawBox();
		drawSnake();
		drawfruit();
		checkDirection();
		moveSnake();
		snakeEat();
		checkWall();
		checkbody();

		ShowConsoleCursor(false);
		gotoXY(25, 15);
		cout << "SCORE: " << dot;
		Sleep(150);

	}
}
