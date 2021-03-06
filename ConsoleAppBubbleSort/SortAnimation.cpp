﻿/*
	Ten: ...
	Lop: ...
	Project: ....
	.....
*/
#include <iostream>
#include <conio.h> 
#include <string>
#include <algorithm>
#include <windows.h> 
#include <cstdlib>
#include <fstream> 
#include <time.h>       /* time */
#include "MyWindows.h"

using namespace std;

#define WIDTH 80
#define HEIGHT 30
#define BLACK			0
#define BLUE			1
#define GREEN			2
#define CYAN			3
#define RED				4
#define MAGENTA			5
#define BROWN			6
#define LIGHTGRAY		7
#define DARKGRAY		8
#define ORANGE			9
#define LIGHTGREEN		10
#define LIGHTCYAN		11
#define LIGHTRED		12
#define LIGHTMAGENTA	13
#define YELLOW			14
#define WHITE			15


void swapByValue(int x, int y) // pass by value
{
	int temp = x;
	x = y;
	y = temp;
};
void swapByPointer(int* x, int* y) // pass by pointer
{
	int temp = *x;
	*x = *y;
	*y = temp;
};
void swapByReference(int& x, int& y) // pass by reference
{
	int temp = x;
	x = y;
	y = temp;
};
void drawArray(MyWindows console, int *a, int w, int size, int left) {
	for (int k = 0; k < size; k++)
	{
		int color = a[k] % 15;
		if (color == BLUE) color = BLACK;
		MyWindows xoa(left + w * k, 1, w - 1, HEIGHT - 4, BLUE, BLUE);
		xoa.clearConsole();
		xoa.drawFrame();
		MyWindows c1(left + w * k, HEIGHT - 4 - a[k], w - 1, a[k], color, WHITE);
		c1.clearConsole();
		c1.drawFrame();
		//console.Write("  ", left + w * k, HEIGHT - 3, BLUE, WHITE);
		console.Write(to_string(a[k]) + " ", left + w * k, HEIGHT - 3, BLUE, WHITE);
	}
} 
int option(MyWindows input) {
	input.clearConsole();
	input.drawFrame();
	input.Write("Menu", 16, 0, YELLOW, RED);
	input.Write(" 1. Bubble Sort", 5, 3, BLACK, RED);
	input.Write(" 2. Selection Sort", 5, 6, BLACK, RED);
	input.Write(" 3. Insertion Sort", 5, 9, BLACK, RED);
	input.Write(" 4. Exit", 5, 12, BLACK, RED);
	input.Write("Moi ban nhap lua chon :", 1, 15, BLACK, RED);
	input.gotoXY(29, 15);
	int op;
	cin >> op;
	return op;
}

int main()
{
	
	/*MyWindows menu(5, 24, 60, 5, RED, WHITE);
	menu.clearConsole();
	menu.drawFrame();
	menu.Write("Menu", 12, 0, BLUE, WHITE);*/
	while (true) {
	MyWindows input(85, 2, 35, 20, BLACK, WHITE);
	
	
	
	MyWindows console(0, 0, WIDTH, HEIGHT, BLUE, RED);
	console.clearConsole();
	console.drawFrame();
	console.Write("Sort ", 12, 0, BLUE, WHITE);

	int a[15] = { };
	int size = sizeof(a) / sizeof(a[0]);
	srand(time(0));
	for (int i = 0; i < size; i++)
	{
		a[i] = (rand() % (HEIGHT - 6)) + 2; // 1 to 100
	}
	int w = 4;
	int left = (WIDTH - (w * size)) / 2;
	drawArray(console, a, w, size, left);
	
	

		int op = option(input);
		switch (op) {
		case 1:
		{
			console.Write(" Bubble Sort ", 12, 0, BLUE, WHITE);
			for (int i = 0; i < size - 1; i++)
			{
				for (int j = 0; j < size - 1 - i; j++)
				{
					for (int k = 0; k < size; k++)
					{
						console.Write("  ", left + w * k, HEIGHT - 2, BLUE, WHITE);
					}
					console.Write("L", left + w * j, HEIGHT - 2, RED, WHITE);
					console.Write("R", left + w * (j + 1), HEIGHT - 2, RED, WHITE);
					if (a[j] > a[j + 1]) {
						swapByPointer(&a[j], &a[j + 1]);

						drawArray(console, a, w, size, left);
					}
					console.Write("L", left + w * j, HEIGHT - 2, RED, WHITE);
					console.Write("R", left + w * (j + 1), HEIGHT - 2, RED, WHITE);
					Sleep(200);
				}

				for (int h = size - 1 - i; h < size; h++)
				{
					console.Write(to_string(a[h]) + " ", left + w * h, HEIGHT - 3, RED, WHITE);
				}
				Sleep(200);
				// Bắt phím ESC để dừng console chương trình
				if (_kbhit())
				{
					char key = _getch();
					if (key == 27)
					{
						break;
					}
				}
			}
			console.Write(to_string(a[0]) + " ", left, HEIGHT - 3, RED, WHITE);
			console.Write("   ", left, HEIGHT - 2, BLUE, WHITE);
			console.Write("   ", left + w, HEIGHT - 2, BLUE, WHITE);
			console.Write("DONE", (WIDTH - 6) / 2, HEIGHT - 2, BLUE, WHITE);
			char c = _getch();
			break;
		}
		case 2:
		{
			console.clearConsole();
			console.drawFrame();
			console.Write(" Selection Sort ", 2, 0, BLUE, WHITE);
			for (int i = 0; i < size - 1; i++)
			{
				int minidx = i;
				console.Write("L", left + w * i, HEIGHT - 2, RED, WHITE);
				for (int j = i + 1; j < size; j++)
				{
					console.Write("R", left + w * j, HEIGHT - 2, RED, WHITE);
					if (a[j] < a[minidx])
						/*minidx = j;*/
						swapByPointer(&a[j], &a[minidx]);

					drawArray(console, a, w, size, left);
					Sleep(100);
					console.Write(" ", left + w * j, HEIGHT - 2, BLUE, WHITE);
				}
				console.Write(" ", left + w * i, HEIGHT - 2, BLUE, WHITE);
				// Bắt phím ESC để dừng console chương trình
				if (_kbhit())
				{
					char key = _getch();
					if (key == 27)
					{
						break;
					}
				}
			}
			//drawArray(two, b, wb, sizeb, leftb + WIDTH / 2);
			console.Write(to_string(a[0]) + " ", left, HEIGHT - 3, RED, WHITE);
			console.Write("   ", left, HEIGHT - 2, BLUE, WHITE);
			console.Write("   ", left + w, HEIGHT - 2, BLUE, WHITE);
			console.Write("DONE", (WIDTH - 6) / 2, HEIGHT - 2, BLUE, WHITE);


			char c1 = _getch();
			break;
		}
		//insert sort 
		case 3:
		{
			console.clearConsole();
			console.drawFrame();
			console.Write(" Insertion Sort ", 2, 0, BLUE, WHITE);
			for (int i = 1; i < size; i++) {
				console.Write("L", left + w * i, HEIGHT - 2, RED, WHITE);
				int j = i - 1;
				// Bắt phím ESC để dừng console chương trình
				if (_kbhit())
				{
					char key = _getch();
					if (key == 27)
					{
						break;
					}
				}
				while (j >= 0 && a[j] > a[j + 1]) {

					swapByPointer(&a[j], &a[j + 1]);
					//three.Write("R", leftd + wd *(j-1), HEIGHT - 2, RED, WHITE);
					console.Write("M", left + w * j, HEIGHT - 2, RED, WHITE);
					drawArray(console, a, w, size, left);
					Sleep(100);
					console.Write(" ", left + w * j, HEIGHT - 2, BLUE, WHITE);
					//three.Write(" ", leftd + wd * (j-1), HEIGHT - 2, BLUE, WHITE);
					j--;
				}
				console.Write(" ", left + w * i, HEIGHT - 2, BLUE, WHITE);
				//console.Write("DONE", (WIDTH - 6) / 2, HEIGHT - 2, BLUE, WHITE);

			}
			console.Write(to_string(a[0]) + " ", left, HEIGHT - 3, RED, WHITE);
			console.Write("   ", left, HEIGHT - 2, BLUE, WHITE);
			console.Write("   ", left + w, HEIGHT - 2, BLUE, WHITE);
			console.Write("DONE", (WIDTH - 6) / 2, HEIGHT - 2, BLUE, WHITE);
			char c2 = _getch();

			break;
		}
		case 4:
		{
			/*input.Write("Bạn đã thoát chương trình", 1, 15, BLACK, RED);*/
			console.clearConsole();
			input.clearConsole();
			break;
		}

		}
	}
}

