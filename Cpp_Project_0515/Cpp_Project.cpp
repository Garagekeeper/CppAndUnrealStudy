#include <iostream>
#include <vector>
#include <time.h>
#include "Day0605.h"
#include "Day0610.h"
#include "Day0611.h"
#include "MazePrac.h"
#include "Coordinate.h"
using namespace std;


int main()
{
	int Seed = 0;
	//Seed = time(0);
	srand(Seed);

	//Day0529_Run();
	//MazePrac1_Run();

	//Day0602_Run();

	//Daya0605EnumTest();
	//Daya0605TestList();
	//Daya0605TestSTLList();
	//Daya0605TestVec();
	//Day0609 day0609;
	//day0609.Day0609_Main();

	//Day0610 Day010;
	//Day010.Day0610_Run();

	Day0611 Day0611;
	Day0611.Day0611_Run();
}