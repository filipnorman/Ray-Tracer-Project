#pragma once
#include "FTuple.h"
#include "mathFunctions/FloatOp.h"

class Projectile {
public:

	FTuple position;
	FTuple velocity;

	Projectile(FTuple position_, FTuple velocity_) : position(position_), velocity(velocity_) {

	}

	~Projectile() {

	}

};