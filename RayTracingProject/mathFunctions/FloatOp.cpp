#pragma once
#include "FloatOp.h"
#include<cmath> 

//Custom comparison of floating point numbers to prevent round-off error inconsitancies
bool equal(float a, float b) {
	return (abs(a - b) < EPSILON);
}



