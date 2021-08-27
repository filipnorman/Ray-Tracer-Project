#pragma once
#include "Canvas.h"
#include <String>
#include <cmath>

//Responsible for creating the PPMContainer for the canvas
PPMContainer Canvas::canvasToPPM()
{
	std::string magicNumber;
	magicNumber.append("P3\n" + std::to_string(m_width) + " " + std::to_string(m_height) + "\n" + "255\n");
	std::string pixelData;
	for (int y = 0; y < m_height; y++) {
		pixelData.append(rowToPPM(y));
	}

	pixelData.append("\n");

	//Reset the counter.
	PPMRowLength = 0;
	return PPMContainer{ magicNumber.c_str() , pixelData.c_str()};
}


//Private method for converting a row of pixel data into ppm
std::string Canvas::rowToPPM(int y) 
{
	Colour temp;
	std::string rowStr;
	std::string cToken;
	int lenToken = 0;
	float cVal = 0;

	for (int x = 0; x < m_width; x++) {

		temp = getPixelColour(x, y);

		for (int i = 0; i < 3; i++) {

			//Obtain Colour Value
			cVal = temp[i];

			//Round off values that are not in 0 to 1 boundary
			if (cVal < 0.f) { cVal = 0.f; }
			else if (cVal > 1.f) { cVal = 1.f; }

			//Generate an int between 0 to 255
			cToken = std::to_string(static_cast<int> (round((cVal * 255.f))));
			lenToken = cToken.length();

			//if the token will fit on the current row
			if (lenToken + PPMRowLength <= PPM_COLUMN_LENGTH) { // The token will fit
				PPMRowLength += lenToken;
				
				//if there is no more space on the row
				if (PPMRowLength == PPM_COLUMN_LENGTH) { // No more tokens will fit

					rowStr.append(cToken + "\n");
					PPMRowLength = 0;
				} else {  // More tokens have the potential to fit

					rowStr.append(cToken + " ");
					PPMRowLength++;
				}	
			} else { // There is no space left

				PPMRowLength = lenToken + 1;
				rowStr.append("\n" + cToken + " ");
			}
		}
	}
	return rowStr;
}
