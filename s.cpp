#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include "rd.h"

#define width 6
#define height 5

using namespace std;

bool s(int (*)[2], int);
int* re_dxy(int);
bool contain(int (*), int (*)[2], int);
void draw(int (*)[2], int);
void gotoxy(int, int);

int main(void)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);
	CursorInfo.bVisible = false; 
	SetConsoleCursorInfo(handle, &CursorInfo);

	int array[width * height][2] = {0};
	for(int i;	i < width * height;	i++)
	{
		array[i][0] = -1;	array[i][1] = -1;
	}
	array[0][0] = 0;	array[0][1] = 0;
	
	s(array, 1);
	return 0;
}

bool s(int array[][2], int len)
{
	//_getch();
	draw(array, len);
	
	if(len == (width * height))	return true;
	int a[4] = {1, 2, 3, 4};
	rd(a, 4);
	int i, n;
	int x = array[len - 1][0], y = array[len - 1][1], dx, dy, nx, ny;
	int *dxy;
	int nxy[2];
	
	for(i = 0;	i < 4;	i++)
	{
		
		n = a[i];
		dxy = re_dxy(n);
		dx = dxy[0];	dy = dxy[1];
		nx = x + dx;	ny = y + dy;
		nxy[0] = nx;	nxy[1] = ny;
		
		if((nx >= 0) && (nx < width) && (ny >= 0) && (ny < height) && !(contain(nxy, array, len)))
		{
			array[len][0] = nx;	array[len][1] = ny;
			if(s(array, len + 1))
				return true;
		}	
	}
	
	//_getch();
	array[len][0] = -1;	array[len][1] = -1;
	draw(array, len);
	
	return false;
}

int* re_dxy(int n)
{
	int dx, dy;
	int dxy[2] = {0};

	if(n > 2)
	{
		if(n > 3)	{dx = -1;	dy = 0;}
		else	{dx = 0;	dy = -1;}
	}
	else
	{
		if (n > 1)	{dx = 1;	dy = 0;}
		else	{dx = 0;	dy = 1;}
	}

	dxy[0] = dx;	dxy[1] = dy;
	return dxy;
}

bool contain(int *nxy, int array[][2], int len)
{
	for(int i = 0;	i <= len;	i++)
	{
		if((nxy[0] == array[i][0]) && (nxy[1] == array[i][1]))
			return true;
	}
	return false;
}

void draw(int array[][2], int len)
{	
	//system("cls");
	gotoxy(0, 0);
	
	int n[2] = {0};
	for(int i = 0;	i <= height;	i++)
	{
		for(int j = 0;	j <= width;	j++)
		{
			n[0] = i;	n[1] = j;
			if(contain(n, array, len))
				cout << "▇";
			else
				cout << "  ";
		}
		cout << endl;
	}
}

void gotoxy(int x, int y) {
	COORD pos = {x,y};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// 获取标准输出设备句柄
	SetConsoleCursorPosition(hOut, pos);//两个参数分别是指定哪个窗体，具体位置
}
