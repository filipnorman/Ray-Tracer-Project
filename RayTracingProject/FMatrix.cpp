#pragma once
#include "FMatrix.h"
#include <iostream>
#include <String>
#include <math.h>


















//Overloading the << for FMatrix so that the matrix can be outputted in a readable format
//Testing Purposes only, designed to only output at (1DP)
std::ostream& operator<<(std::ostream& os,  FMatrix& matrix)
{
	//Find the largest value
	float max = 0;
	for (int y = 0; y < matrix.m_rows; y++) {
		for (int x = 0; x < matrix.m_cols; x++) {
			if (max <= matrix(y, x)) max = matrix(y, x);
		}
	}

	//Determin the width of space reserved for whole numbers
	os << std::endl << matrix.m_rows << "x" << matrix.m_cols << " Matrix:" << std::endl;
	int width = std::to_string(std::floor(max)).length();
	int startOffset = 0;
	bool whole = true;

	for (int y = 0; y < matrix.m_rows; y++) {
		for (int x = 0; x < matrix.m_cols; x++) {
			os << "| ";

			float current = matrix(y, x);

			if (!(current == (int)current)) {
				current = std::round(current * 10) / 10;
				whole = false;
			}

			std::string string = std::to_string(current);
			startOffset = width - string.length();

			for (int i = 0; i < startOffset; i++) {
				os << " ";
			}

			os << current;

			//If fill in the decimal spaces;
			if (whole) {
				os << "  ";
			}
			//Padding
			os << " ";

			whole = true;
		}
		os << "|\n";
	}
	return os;
}
