/*
 * ClosesHit.cpp
 *
 *  Created on: Apr 20, 2020
 *      Author: sandrogiannini
 */

#include "ClosesHit.h"

ClosesHit::ClosesHit() {
	// TODO Auto-generated ructor stub

}

ClosesHit::~ClosesHit() {
	// TODO Auto-generated destructor stub
}

 Vector3d&
 ClosesHit::getHitPoint()  {
	return HitPoint;
}

void
ClosesHit::setHitPoint( Vector3d &hitPoint) {
	HitPoint = hitPoint;
}

 Vector3d&
 ClosesHit::getNormal()  {
	return Normal;
}

void
ClosesHit::setNormal( Vector3d &normal) {
	Normal = normal;
}

double
ClosesHit::getT()  {
	return t;
}

void
ClosesHit::setT(double t) {
	this->t = t;
}

bool
ClosesHit::isTexture(){
	return texture;
}

bool ClosesHit::isSpecular() const {
	return specular;
}

void ClosesHit::setSpecular(bool specular) {
	this->specular = specular;
}

void
ClosesHit::setTexture(bool texture) {
	this->texture = texture;
}

const Vector3d& ClosesHit::getColor() const {
	return Color;
}

void ClosesHit::setColor(const Vector3d &color) {
	Color = color;
}

double ClosesHit::getFuzziness() const {
	return fuzziness;
}

void ClosesHit::setFuzziness(double fuzziness) {
	this->fuzziness = fuzziness;
}

bool ClosesHit::isSingleStripe() const {
	return singleStripe;
}

void ClosesHit::setSingleStripe(bool singleStripe) {
	this->singleStripe = singleStripe;
}
