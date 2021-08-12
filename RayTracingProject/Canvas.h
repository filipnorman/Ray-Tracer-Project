#pragma once
#include "Colour.h"
#define INDEX(x, y, no_x) (y*no_x + x)

class Canvas {
public:

	int m_width;
	int m_height;
	
	Canvas(int width, int height) : m_width(width), m_height(height) {
		canvas_arr = new Colour[m_width * m_height];
	}

	~Canvas() {
		delete [] canvas_arr;
	}

	void write_pixel(int x, int y, Colour c) {
		canvas_arr[INDEX(x,y,m_width)] = c;
	}

	Colour getPixelColour(int x, int y) {
		return canvas_arr[INDEX(x,y,m_width)];
	}

private:
	Colour* canvas_arr;
};
