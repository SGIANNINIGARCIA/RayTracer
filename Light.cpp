/*
 * Light.cpp
 *
 *  Created on: Apr 20, 2020
 *      Author: sandrogiannini
 */

#include "Light.h"

Light::Light(Vector3d c, double dif, double amb, double spec) {

	this->center = c;
	this->diffuse = dif;
	this->ambience = amb;
	this->specular = spec;

}

Light::Light() {

	this->center = Vector3d(0, 10, 0);
	this->diffuse = 0.1;
	this->ambience = 0.1;
	this->specular = 0.1;

}

double Light::getAmbience()  {
	return ambience;
}

void Light::setAmbience(double ambience) {
	this->ambience = ambience;
}

 Vector3d& Light::getCenter()  {
	return center;
}

void Light::setCenter( Vector3d &center) {
	this->center = center;
}

double Light::getDiffuse()  {
	return diffuse;
}

void Light::setDiffuse(double diffuse) {
	this->diffuse = diffuse;
}

double Light::getSpecular()  {
	return specular;
}

void Light::setSpecular(double specular) {
	this->specular = specular;
}

Light::~Light() {
	// TODO Auto-generated destructor stub
}

