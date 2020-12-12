#include "L24.h"
#include <iostream>
using namespace std;

int main()
{
	int n = 1;
	int* p = &n;
	int* p1 = p;

	cout << p1 << endl;
	cout << p << endl;
	return 0;
}