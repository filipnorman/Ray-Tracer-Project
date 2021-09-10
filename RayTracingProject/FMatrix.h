#pragma once
#include "mathFunctions/FloatOp.h"
#include <iostream>
#define INDEX(x, y, no_x) (y*no_x + x) 

//Matrix Base Class. Includes all of the for matrices 
class FMatrix {

public:
	unsigned m_rows, m_cols, m_size;


	FMatrix(unsigned rows_, unsigned cols_) : m_rows(rows_), m_cols(cols_), m_size(rows_ * cols_) {
		//The () initialises the the floats to the default value of 0
		arr_Matrix = new float[m_rows * m_cols]();
	}


	//Frees memory from the dynamically alocated matrix array
	~FMatrix(){
		delete[] arr_Matrix;
	}

	// returns float& so that the value can be altered in place.
	float& operator()(unsigned rows_, unsigned cols_) {
		if (rows_ < m_rows && cols_ < m_cols)
			return arr_Matrix[INDEX(cols_, rows_, m_cols)];
	}





protected:


private:
	float* arr_Matrix;

};

std::ostream& operator<<(std::ostream& os,  FMatrix& matrix);