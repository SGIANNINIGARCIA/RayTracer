/*
 * main.cpp
 *
 *  Created on: Apr 10, 2020
 *      Author: sandrogiannini
 */

#include "Image.h"

#include <iostream>



int main() {

	Image image;
	image.runRayTracer();
	image.write("./project3a.ppm");

}




