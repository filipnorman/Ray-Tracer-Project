#pragma once
#include<cmath> 
#include "FTuple.h"

//Member Function Returning the magnitude();
float FTuple::magnitude()
{
	return sqrtf(powf(x,2) + powf(y,2) + powf(z,2) + powf(w,2));
}

//Member Function returning a normailised version of the vector
FTuple FTuple::normalise()
{
	float mag = magnitude();
	return FTuple(x/mag, y/mag, z/mag, w/mag);
}

//Dot Product function
float dot(FTuple a, FTuple b)
{
	return (a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w);
}

//Cross Product function
FTuple cross(FTuple a, FTuple b)
{
	return vector(a.y * b.z - a.z * b.y,
						  a.z * b.x - a.x * b.z,
			              a.x * b.y - a.y * b.x);
}

FTuple point(float x_, float y_, float z_)
{
	return FTuple(x_, y_, z_, 1);
}

FTuple vector(float x_, float y_, float z_)
{
	return FTuple(x_, y_, z_, 0);
}
