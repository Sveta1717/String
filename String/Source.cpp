#include "String.h"

//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <ctime>
//using namespace std;

//#include "MyString.h"

int main()
{
	setlocale(0, "UKR");
	srand(time(0));

	String b(" hello world ");
	String c = b;
	b.Print();
	c.Print();
}

//int main()
//{
//	setlocale(0, "UKR");
//	srand(time(0));
//	int x = 2022;
//	double y = 20.22;
//	int z = 0;
//	const char* w = ";";
//	const char* line = " hello world ";
//	String a;
//	String b(" hello world ");
//	String c = b;
//	String s = " hello happy New Year ";
//	String d = "Ñ ÍÎÂÛÌ ÃÎÄÎÌ";
//	String e = "ס םמגûל דמהמל";
//
//	a.Print();
//	cout << "========================\n";
//	b.Print();
//	cout << "========================\n";
//	c.PrintLn();
//	cout << "========================\n";
//	cout << b.GetCharAt(7) << "\n";
//	cout << "========================\n";
//	b.GetLine();
//	b.Print();
//	cout << "========================\n";
//	cout << b.CompareTo(d) << "\n";
//	cout << "========================\n";
//	cout << d.CompareTo(line) << "\n";
//	cout << "========================\n";
//	b.Concat(s);
//	b.Print();
//	cout << "========================\n";
//	s.Concat(" Happy!\n");
//	s.Print();
//	cout << "========================\n";
//	s.Concat(x);
//	s.Print();
//	cout << "========================\n";
//	s.Concat(y);
//	s.Print();
//	cout << "========================\n";
//	cout << b.Contains(s) << "\n";
//	cout << "========================\n";
//	cout << b.EndsWith(line);
//	cout << "========================\n";
//	cout << b.StartsWith(line);
//	cout << "========================\n";
//	cout << b.Equals(s) << "\n";
//	cout << "========================\n";
//	s.Trim();
//	s.Print();
//	cout << "========================\n";
//	s.TrimEnd();
//	s.Print();
//	cout << "========================\n";
//	s.TrimStart();
//	s.Print();
//	cout << "========================\n";
//	d.Split(w, z);
//	d.Print();
//	cout << "========================\n";
//	d.ToLower();
//	d.Print();
//	cout << "========================\n";
//	e.ToUpper();
//	e.Print();
//	cout << "========================\n";
//	b.SortAZ();
//	b.Print();
//	cout << "========================\n";
//	b.SortZA();
//	b.Print();
//	cout << "========================\n";
//	b.Remove(3);
//	b.Print();
//	cout << "========================\n";
//	b.Remove(3, 2);
//	b.Print();
//	cout << "========================\n";
//	a.RandomFill();
//	a.Print();
//	cout << b.IndexOf('l') << "\n";
//	cout << "========================\n";
//	cout << b.LastIndexOf('l') << "\n";
//	cout << "========================\n";
//	cout << s.IndexOf(b) << "\n";
//	cout << "========================\n";
//	s.Reverse();
//	s.Print();
//	cout << "========================\n";
//	b.Replace('l', 't');
//	b.Print();
//	cout << "========================\n";
//	b.Shuffle();
//	b.Print();
//	cout << "========================\n";
//	cout << b.GetLength() << endl;
//	cout << b.GetCapacity() << endl;
//	cout << "========================\n";
//	a.SetString("nice weather");
//	cout << a.GetLength() << endl;
//	cout << a.GetCapacity() << endl;
//	cout << "========================\n";
//	a.Clear();
//	cout << a.GetLength() << endl;
//	cout << a.GetCapacity() << endl;
//	cout << "========================\n";
//	a.ShrinkToFit();
//	cout << a.GetLength() << endl;
//	cout << a.GetCapacity() << endl;
//	cout << "\n";
//}
