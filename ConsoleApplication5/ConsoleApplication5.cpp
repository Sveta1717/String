#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
using namespace std;

#include "String.h"

int main()
{
	setlocale(0, "UKR");
	srand(time(0));

	String b(" hello world ");
	String c = b;
	b.Print();
	c.Print();
}