/*
 * Sphere.h
 *
 *  Created on: Apr 12, 2020
 *      Author: sandrogiannini
 */

#ifndef SPHERE_H_
#define SPHERE_H_

#include "Vector3d.h"

class Sphere {

private:
	Vector3d center;
	double   radius;

public:
	Sphere();
	Sphere(float, float, float, double);
	virtual ~Sphere();
	double getRarius();
	void setRadius(double);
	Vector3d getCenter();
	void setCenter(Vector3d);
};

#endif /* SPHERE_H_ */
