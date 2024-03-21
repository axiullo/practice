#include "L11.h"
#include <iostream>
using namespace std;

//#define test
void print_definetest()
{
	cout << "print_definetest" << endl;
}

int main()
{
	/*
	int n = 1;
	int* p = &n;
	int* p1 = p;

	cout << p1 << endl;
	cout << p << endl;
	*/

	Solution example;
	example.test();
	system("pause");

#ifdef test
	print_definetest();
#endif // test

	return 0;
}