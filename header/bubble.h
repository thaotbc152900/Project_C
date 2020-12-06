#include "../header/MyWindows.h"
string arrayToString(int a[], int size);
void swapByValue(int x, int y); // pass by value
void swapByPointer(int* x, int* y); // pass by pointer
void swapByReference(int& x, int& y);
void drawArray(MyWindows console, int* a, int w, int size, int left);