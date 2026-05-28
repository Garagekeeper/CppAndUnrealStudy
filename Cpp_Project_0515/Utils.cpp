#include "Utils.h"
#include <float.h>
#include <math.h>

bool IsFloatEqual(float A, float B)
{
	return fabsf(A - B) <= FLT_EPSILON;
}
