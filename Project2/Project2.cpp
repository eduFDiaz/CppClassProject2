#include "stdafx.h"
#include <ctime> 
#include <cstdlib>
#include <iostream>
using namespace std;

int sign(int x) {
	return (x > 0) - (x < 0);
}

int main()
{
	srand((unsigned)time(0));
	int random_integer;
	int lowest = -10, highest = 10;
	int range = (highest - lowest) + 1;
	for (int index = 0; index<20; index++) {
		random_integer = lowest + int(range*rand() / (RAND_MAX + 1.0));
		cout << sign(random_integer) << endl;
	}
    return 0;
}

