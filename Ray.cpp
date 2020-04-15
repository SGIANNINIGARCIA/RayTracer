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

const Vector3d&
Ray::getDestinationVector() const {
	return destinationVector;
}

void
Ray::setDestinationVector(const Vector3d &destinationVector) {
	this->destinationVector = destinationVector;
}

const Vector3d&
Ray::getOriginVector() const {
	return originVector;
}

void
Ray::setOriginVector(const Vector3d &originVector) {
	this->originVector = originVector;
}
