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
	bool     texture;
	bool 	 reflection;
	double   fuzziness;
	Vector3d movement;


public:
	Vector3d color;
	Sphere();
	Sphere(Vector3d, Vector3d, double);
	virtual ~Sphere();
	double getRarius();
	void setRadius(double);
	Vector3d getCenter();
	void setCenter(Vector3d);
	bool isTexture();
	void setTexture(bool texture);
	double getFuzziness();
	void setFuzziness(double fuzziness);
	bool isReflection();
	void setReflection(bool reflection);
	void move();
	bool isSingleStripe() const;
	void setSingleStripe(bool singleStripe);
};

#endif /* SPHERE_H_ */
