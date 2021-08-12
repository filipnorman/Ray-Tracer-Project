#pragma once
#include "FTuple.h"



class Colour : public FTuple {
public:

	Colour(float red, float green, float blue) : FTuple(red, green, blue, 0.f) {

	}

	Colour() : FTuple(0.f, 0.f, 0.f, 0.f) {

	}

	~Colour() {

	}

	float red() { return this->x; }

	float green() { return this->y; }

	float blue() { return this->z; }

	void setRed(float h) { this->x = h; }

	void setGreen(float h) { this->y = h; }

	void setBlue(float h) { this->z; }

	//Used to mix colours using the Hadamard Product (Schur product)
	Colour operator*(const Colour c) {
		return Colour(this->x * c.x, this->y * c.y, this->z * c.z);
	}

	Colour operator*(const float s) {
		return Colour(this->x * s, this->y * s, this->z * s);
	}
};

