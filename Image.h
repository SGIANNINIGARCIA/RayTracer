/*
 * Image.h
 *
 *  Created on: Apr 10, 2020
 *      Author: sandrogiannini
 */

#ifndef IMAGE_H_
#define IMAGE_H_

#include <iostream>
#include <fstream>
#include "Constants.h"
#include <vector>
#include "Vector3d.h"
#include "Ray.h"
#include "Sphere.h"

class Image {
private:

	Vector3d pixel[ROWS][COLUMNS];
	Vector3d calculatePixelColor(Ray, double);
	Sphere circle;

	bool rayHitsSphere(Ray);

public:

	Image();
	virtual ~Image();
	void write(std::string filename);
	void runRayTracer();
};

#endif /* IMAGE_H_ */
