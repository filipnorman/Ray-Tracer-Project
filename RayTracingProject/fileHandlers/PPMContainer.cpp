#pragma once
#include "PPMContainer.h"

int savePPM(PPMContainer ppm, std::string filename)
{
	std::ofstream ofs(filename + ".ppm", std::ios_base::out | std::ios_base::binary);
	ofs << ppm.magicNumber << ppm.arr_PixelData;

	ofs.close();

	return 0;
}
