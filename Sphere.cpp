/*
 * Sphere.cpp
 *
 *  Created on: Apr 12, 2020
 *      Author: sandrogiannini
 */

#include "Sphere.h"

Sphere::Sphere() {

	radius = 0;
	center = Vector3d(0,0,0);

}

Sphere::Sphere(float x, float y, float z, double r) {

	radius = r;
	center = Vector3d(x,y,z);

}

Sphere::~Sphere() {
}

double
Sphere::getRarius(){

	return radius;
}
void
Sphere::setRadius(double r){

	radius = r;

}
Vector3d
Sphere::getCenter(){

	return center;

}
void
Sphere::setCenter(Vector3d c){

	center = c;

}

