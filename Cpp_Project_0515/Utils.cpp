#include <float.h>
#include <math.h>
#include <iostream>

#include "Utils.h"


bool IsFloatEqual(float A, float B)
{
	return fabsf(A - B) <= FLT_EPSILON;
}

int RandomRange(int Min, int Max)
{
	return rand() % (Max - Min + 1) + Min;
}

int RandomRange(int Max)
{
	return RandomRange(0, Max);
}

float GetRandom()
{
	return rand() / (float)RAND_MAX;
}
