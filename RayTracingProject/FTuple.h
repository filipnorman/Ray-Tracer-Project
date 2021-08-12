#pragma once
#include "mathFunctions/FloatOp.h"

//FTuple Class Responsible for the foundations of render calculations with the use of custom tuple types. 
class FTuple {
	public:
		float x;
		float y;
		float z;
		float w; 

		//Constructor
		FTuple(float x_, float y_, float z_, float w_) : x(x_), y(y_), z(z_), w(w_) {}

		//Destructor 
		~FTuple() {}

		//Overloading of the comparison operator for FTuples
		bool operator==(const FTuple a) {
			return equal(x, a.x) && equal(y, a.y) && equal(z, a.z) && equal(w, a.w);
		}

		//Overloading of plus operator 
		FTuple operator+(const FTuple b) {
			return FTuple(x + b.x, y + b.y, z + b.z, w + b.w);
		}

		//Overloading of minus operator 
		FTuple operator-(const FTuple b) {
			return FTuple(x - b.x, y - b.y, z - b.z, w - b.w);
		}

		//Overloading of the multiplication operator
		FTuple operator*(const float s) {
			return FTuple(x * s, y * s, z * s, w * s);
		}

		//Overloading of the division operator
		FTuple operator/(const float s) {
			return FTuple(x / s, y / s, z / s, w / s);
		}

		//Overloading of the negation operator
		FTuple operator-() {
			return FTuple(-x,-y,-z,-w);
		}

		float magnitude();

		FTuple normalise();


		//Does Not Boundry Check
		float& operator[] (size_t i)
		{
			return (&x)[i];
		}

	};

float dot(FTuple a, FTuple b); 

FTuple cross(FTuple a, FTuple b);

//Factory Method for Creating a point tuple
FTuple point(float x_, float y_, float z_);

//Factory Method for Creating a vector tuple
FTuple vector(float x_, float y_, float z_);















