#include "print.h"
#include <iostream>

using namespace std;

void printN(int n)
{
	for (int i = 1; i <= n; i++)
		cout << i << " ";
}

void printReverseN(int n)
{
	for (int i = n; i >= 1; i--)
		cout << i << " ";
}
