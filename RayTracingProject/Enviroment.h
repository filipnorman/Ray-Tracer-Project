#pragma once
#include "FTuple.h"
#include "mathFunctions/FloatOp.h"


//Enivroment Class, Used To Demo The Integration of Vectors and Colour Implementations
class Enviroment {
public:

	FTuple gravity;
	FTuple wind;

	Enviroment(FTuple gravity_, FTuple wind_) : gravity(gravity_), wind(wind_) { }

	~Enviroment() { }



};