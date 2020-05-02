/*
 * Ray.cpp
 *
 *  Created on: Apr 10, 2020
 *      Author: sandrogiannini
 */

#include "Ray.h"

Ray::Ray() {

	originVector = Vector3d(0,0,0);
	destinationVector = Vector3d(0,0,0);

}

Ray::Ray(Vector3d origin, Vector3d destination) {

	originVector = origin;
	destinationVector = destination;

}

Ray::~Ray() {
	// TODO Auto-generated destructor stub
}

 Vector3d&
Ray::getDestinationVector()  {
	return destinationVector;
}

void
Ray::setDestinationVector( Vector3d &destinationVector) {
	this->destinationVector = destinationVector;
}

 Vector3d&
Ray::getOriginVector()  {
	return originVector;
}

void
Ray::setOriginVector( Vector3d &originVector) {
	this->originVector = originVector;
}

Vector3d
Ray::pointAtParameter(float t){
	return originVector + ( destinationVector * t);
}
