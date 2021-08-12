#pragma once
#include "Colour.h"
#include "fileHandlers/PPMContainer.h"
#include <String>

#define INDEX(x, y, no_x) (y*no_x + x) 

class Canvas {
public:

	int m_width;
	int m_height;
	
	//2D Array implematiation using a single block 
	Canvas(int width, int height) : m_width(width), m_height(height) {
		canvas_arr = new Colour[m_width * m_height];
	}

	~Canvas() {
		delete [] canvas_arr;
	}

	//Write a colour value to a single pixel at a specific x and y coordinate
	void write_pixel(int x, int y, Colour c) {
		if (x >= m_width || y >= m_height) return;

		canvas_arr[INDEX(x,y,m_width)] = c;
	}

	//Get a colour value from a single pixel at a specific x and y coordinate
	Colour getPixelColour(int x, int y) {
		if (x >= m_width || y >= m_height) return Colour(0.f, 0.f, 0.f);
		return canvas_arr[INDEX(x,y,m_width)];
	}

	PPMContainer canvasToPPM();

private:
	Colour* canvas_arr;
	int PPMRowLength = 0;
	std::string rowToPPM(int y);


};



