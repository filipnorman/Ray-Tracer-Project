#pragma once
#include "gtest/gtest.h"
#include "FTuple.h"
#include "Enviroment.h"
#include "Projectile.h"
#include "Canvas.h"
#include "fileHandlers/PPMContainer.h"

#include <iostream> //Included for temporary integration testing WINK WINK

//The following file is the programs starting point. 

Projectile tick(Enviroment env, Projectile proj);


int main(int argc, char** argv) {
	testing::InitGoogleTest(&argc, argv);
	


	FTuple ree = FTuple(1.f, 2.f, 3.f, 4.f);

	std::cout << "x: " << ree[0] << " y: " << ree[1] << " z: " << ree[2] << " w: " << ree[3] << std::endl;

	Canvas canvas = Canvas(900, 550);
	
	Enviroment env = Enviroment(vector(0.f, -0.1f, 0.f), vector(-0.01f, 0.f, 0.f));
	Projectile proj = Projectile(point(0, 1, 0), vector(1, 1.8, 0).normalise() * 11.25);

	int iterations = 0;
	while (proj.position.y >= 0) {
		proj = tick(env, proj);
		canvas.write_pixel(proj.position.x, 550 - proj.position.y, Colour(1.f, 0.f, 0.f));
		iterations++;
	}

	std::cout << "Iterations: " << iterations << std::endl;

	PPMContainer ppm = canvas.canvasToPPM();

	savePPM(ppm, "nicetry222");
	

	return RUN_ALL_TESTS();

}


Projectile tick(Enviroment env, Projectile proj) {
	FTuple position = proj.position + proj.velocity;
	FTuple velocity = proj.velocity + env.gravity + env.wind;
	return Projectile(position, velocity);

}
