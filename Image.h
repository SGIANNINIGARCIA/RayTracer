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
#include "Light.h"
#include "ClosesHit.h"
#include "Camera.h"

class Image {
private:

	Vector3d pixel[ROWS][COLUMNS];
	std::vector<Sphere> spheres;
	std::vector<Light> lights;
	Vector3d calculatePixelColor(Ray, double, int);
	Sphere circle;
	Light light;
	void setUp();
	bool rayHitsSphere(Ray&, ClosesHit&);
	bool generateBrightTexture(ClosesHit&, Ray);
	Vector3d randomeCubeNumber();
	double randomNumber();

public:

	Image();
	virtual ~Image();
	void write(std::string filename);
	void runRayTracer();
};

#endif /* IMAGE_H_ */
