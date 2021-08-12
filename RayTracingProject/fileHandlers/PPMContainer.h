#pragma once
#include <String>
#include <fstream>
#include <cstdio>
#define PPM_COLUMN_LENGTH 69
#define PPM_COLOUR_DEPTH 255

struct PPMContainer {
	//Identifier of PPM file format
	std::string magicNumber;
	//Pixel Colour data stored
	std::string arr_PixelData;
};


int savePPM(PPMContainer ppm, std::string filename);