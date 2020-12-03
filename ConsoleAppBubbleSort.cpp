/*
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
#include "MyWindows.h";



using namespace std;

#define WIDTH  120
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
#define LIGHTBLUE		9
#define LIGHTGREEN		10
#define LIGHTCYAN		11
#define LIGHTRED		12
#define LIGHTMAGENTA	13
#define YELLOW			14
#define WHITE			15
   
string arrayToString(int a[], int size) 
{

	string st = "";
	for (int i = 0; i < size; i++)
	{
		st += to_string(a[i]) + " ";
	}
	return st;
}
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

int main()
{
	srand(time(0));
	int select;
	do
	{
		MyWindows console(0, 0, WIDTH, HEIGHT, BLACK, WHITE);
		console.clearConsole();
		console.drawFrame();
		console.Write("Menu", 10, 0, YELLOW, RED);
		console.Write(" 1. Bubble Sort", 40, 8, BLACK, RED);
		console.Write(" 2. Selection Sort", 40, 10, BLACK, RED);
		console.Write(" 3. Insertion Sort", 40, 12, BLACK, RED);
		console.Write(" 4. Exit", 40, 14, BLACK, RED);
		console.Write("Moi ban nhap lua chon :", 10, 15, BLACK, RED);
		/*cout << " -----------------------------------------------TRANG CHU------------------------------------- \n";
		cout << "|                                      ___________________________                            |\n";
		cout << "|                                     |       1. Bubble Sort      |                           |\n";
		cout << "|                                     |___________________________|                           |\n";
		cout << "|                                      ___________________________                            |\n";
		cout << "|                                     |     2. Selection Sort     |                           |\n";
		cout << "|                                     |___________________________|                           |\n";
		cout << "|                                      ___________________________                            |\n";
		cout << "|                                     |     3. Insertion Sort     |                           |\n";
		cout << "|                                     |___________________________|                           |\n";
		cout << " --------------------------------------------------------------------------------------------- \n";*/

		/*cout << "\n";
		cout << "\n";
		cout << "Moi ban nhap lua chon : \n >";*/
		cin >> select;
		switch (select) {
			
		case 1:
		{
			console.clearConsole();
			MyWindows console(0, 0, WIDTH, HEIGHT, BLUE, RED);
			console.clearConsole();
			console.drawFrame();
			console.Write(" Bubble Sort ", 12, 0, BLUE, WHITE);
			int a[15] = { };
			int size = sizeof(a) / sizeof(a[0]);

			for (int i = 0; i < size; i++)
			{
				a[i] = (rand() % (HEIGHT - 6)) + 2; // 1 to 100
			}
			/*int stA[] = arrayToString(a, size);
			console.Write("Input: " + stA, 1, 12, BLUE, WHITE);*/
			int w = 4;
			int left = (WIDTH - (w * size)) / 2;

			drawArray(console, a, w, size, left);
			// bubble sort  
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
					Sleep(100);
				}
				for (int h = size - 1 - i; h < size; h++)
				{
					//console.Write(to_string(a[h]) + " ", left + w * h, HEIGHT - 3, RED, WHITE);
				}
				Sleep(1000);
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

			MyWindows two(0, 0, WIDTH, HEIGHT, BLUE, WHITE);
			two.clearConsole();
			two.drawFrame();
			two.Write(" Select Sort ", 2, 0, BLUE, WHITE);
			int b[15] = { };
			int sizeb = sizeof(b) / sizeof(b[0]);

			for (int i = 0; i < sizeb; i++)
			{
				b[i] = (rand() % (HEIGHT - 6)) + 2; // 1 to 100
			}
			/*int stA[] = arrayToString(a, size);
			console.Write("Input: " + stA, 1, 12, BLUE, WHITE);*/
			int wb = 4;
			int leftb = (WIDTH  - (wb * sizeb)) / 2;

			drawArray(two, b, wb, sizeb, leftb);
			// select sort  
			for (int i = 0; i < sizeb - 1; i++)
			{
				int minidx = i;
				two.Write("L", leftb + wb * i, HEIGHT - 2, RED, WHITE);
				for (int j = i + 1; j < sizeb; j++)
				{
					two.Write("R", leftb + wb * j, HEIGHT - 2, RED, WHITE);
					if (b[j] < b[minidx])
						/*minidx = j;*/
						swapByPointer(&b[j], &b[minidx]);

					drawArray(two, b, wb, sizeb, leftb);
					Sleep(100);
					two.Write(" ", leftb + wb * j, HEIGHT - 2, BLUE, WHITE);
					/*console.Write("", left + w1 * j, HEIGHT - 2, RED, WHITE);
					console.Write("", left + w1 * (j + 1), HEIGHT - 2, RED, WHITE);*/
				}
				two.Write(" ", leftb + wb * i, HEIGHT - 2, BLUE, WHITE);

				/*Sleep(100);
				if (a[minidx] < a[i]) {
					swapByPointer(&a[minidx], &a[i]);
					drawArray(console, a, w, size, left );
				}*/
				/*Sleep(100);*/
			}
			//drawArray(two, b, wb, sizeb, leftb + WIDTH / 2);
			two.Write(to_string(b[0]) + " ", leftb, HEIGHT - 3, RED, WHITE);
			two.Write("   ", leftb, HEIGHT - 2, BLUE, WHITE);
			two.Write("   ", leftb + wb, HEIGHT - 2, BLUE, WHITE);
			two.Write("DONE", (WIDTH - 6) / 2, HEIGHT - 2, BLUE, WHITE);

			char c1 = _getch();
			break;
		}
		//insert sort 
		case 3:
		{

			MyWindows three(0, 0, WIDTH, HEIGHT, BLUE, WHITE);
			three.clearConsole();
			three.drawFrame();
			three.Write(" Insert Sort ", 2, 0, BLUE, WHITE);
			int d[15] = { };
			int sized = sizeof(d) / sizeof(d[0]);

			for (int i = 0; i < sized; i++)
			{
				d[i] = (rand() % (HEIGHT - 6)) + 2; // 1 to 100
			}
			/*int stA[] = arrayToString(a, size);
			console.Write("Input: " + stA, 1, 12, BLUE, WHITE);*/
			int wd = 4;
			int leftd = (WIDTH - (wd * sized)) / 2;
			for (int i = 1; i < sized; i++) {
				three.Write("L", leftd + wd * i, HEIGHT - 2, RED, WHITE);
				int j = i - 1;				
				while (j >= 0 && d[j] > d[j + 1]) {
					
					swapByPointer(&d[j], &d[j + 1]); 
					//three.Write("R", leftd + wd *(j-1), HEIGHT - 2, RED, WHITE);
					three.Write("M", leftd + wd * j, HEIGHT - 2, RED, WHITE);
					drawArray(three, d, wd, sized, leftd);
					
					Sleep(100);
					three.Write(" ", leftd + wd * j, HEIGHT - 2,BLUE, WHITE);
					//three.Write(" ", leftd + wd * (j-1), HEIGHT - 2, BLUE, WHITE);
					j--;
					
				}
				three.Write(" ", leftd + wd * i, HEIGHT - 2, BLUE, WHITE);
				//console.Write("DONE", (WIDTH - 6) / 2, HEIGHT - 2, BLUE, WHITE);
			}
			char c2 = _getch();
			break;
		}
		case 4:
		{
			cout << "Ban da thoat chuong trinh" << endl;
			break;
		}
		}
	} while (select != 4); ;
}

 

