#include "stdafx.h"
#include <ctime> 
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
//Eduardo Antonio Fernandez Diaz

int genRand(int a, int b) {
	// This function generates a random number
	// between a and b with range (b - a) + 1
	int random_integer;
	int range = (b - a) + 1;
	return (a + int(range*rand() / (RAND_MAX + 1.0)));
}

int main()
{
	int observedTime;
	cout << "For how many hours do you want to observe the elevator? [1-10](hours): ";
	cin >> observedTime;
	if (observedTime < 1 || observedTime>10)
	{
		cout << "Enter a valid time range to watch the elevator"<<endl;
		return 0;
	}

	//each hour has 60 minutes and the elevator will move up or down every 5 minutes
	// (observeTime will hold the number of times the elevator will move)
	observedTime = observedTime * 60 / 5;

	//An array to store floor visits is initialized
	int floorVisits[25] = { 0 };
	//actual floor var for the initial state of the elevator
	int actualFloor;
	cout << "Enter the initial state of the elevator: [1-25](floor): ";
	cin >> actualFloor;
	if (actualFloor < 1 || actualFloor>25)
	{
		cout << "Enter a valid floor for the initial state of the elevator" << endl;
		return 0;
	}
	actualFloor -= 1;

	//We set to 1 the visits to the floor where the elevator is
	floorVisits[actualFloor] += 1;
	
	srand((unsigned)time(0));
	// For the project let's generate numbers between 0 and 1
	// to find out later the sign of it, if we have -1 the elevator will
	// go down and +1 if the elevator will go up
	int a = 0, b = 1; 
	//up or down will take values +1 or -1, explained in previous comment
	int upOrDown;

	for (int index = 0; index < observedTime ; index++) {
		upOrDown = genRand(a, b) * 2 - 1; //  rand(0,1)* 2 - 1 Artifact to simulate a sign function for our values
		
		switch (actualFloor)
		{
			// In cases 24 (top floor) and 0 ( bottom floor) the elevator is forced 
			// to go in the only posible direction down and up respectively :)
			case 24: actualFloor -= 1; floorVisits[actualFloor] += 1; break;
			case 0: actualFloor += 1; floorVisits[actualFloor] += 1; break;
			default:
			{
				//in the default case is ok to add a visit to the floor
				actualFloor += upOrDown;
				floorVisits[actualFloor] += 1;
				break;
			}
		}
	}

	//Finally we print the visits as a bar chart
	cout << endl<< "Floor" << setw(2) << " Number of visits" << endl;
	cout  << "-----" << setw(2) << " ----------------" << endl;
	for (int i = 24; i >-1 ; i--){
		cout << setw(5) << i + 1;
		for(int j=0; j < floorVisits[i]; j++)
		cout << setw(2) << '*' ;
		cout << endl;
	}
	
    return 0;
}

