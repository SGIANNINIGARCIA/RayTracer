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
	texture = false;
	reflection = true;
	fuzziness = 0.9;
	movement = Vector3d(0,0,0);

}

Sphere::Sphere(Vector3d s, Vector3d c,  double r) {

	radius = r;
	center = s;
	color = c;
	texture = false;
	reflection = true;
	fuzziness = 0.5;
	movement = Vector3d(0,0,0);

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

bool
Sphere::isTexture(){
	return texture;
}

double
Sphere::getFuzziness(){
	return fuzziness;
}

void Sphere::setFuzziness(double fuzziness) {
	this->fuzziness = fuzziness;
}

bool
Sphere::isReflection(){
	return reflection;
}

void
Sphere::setReflection(bool reflection) {
	this->reflection = reflection;
}

void
Sphere::setTexture(bool texture) {
	this->texture = texture;
}

void
Sphere::move(){

	center = center + movement;

}
