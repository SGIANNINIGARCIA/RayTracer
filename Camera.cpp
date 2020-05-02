/*
 * Camera.cpp
 *
 *  Created on: Apr 22, 2020
 *      Author: sandrogiannini
 */

#include "Camera.h"

Camera::Camera(double vfov, double aspectRatio) {

	m_vUp = Vector3d(0,-3,0);
	m_lookFrom = Vector3d(0,0,4);
	m_lookAt = Vector3d(0,-2.5,-8);


	Vector3d w = m_lookFrom - m_lookAt;
	w.makeUnitVector();

	Vector3d u =  m_vUp.cross(w);
	u.makeUnitVector();

	Vector3d v = w.cross(u);

	double theta = vfov * DEG_TO_RAD;
	double halfHeight = tan(theta/2);
	double halfWidth = aspectRatio * halfHeight;

	m_origin = m_lookFrom;
	m_width = u * (2 * halfWidth);
	m_height = v * (2 * halfHeight);
	m_bottomLeftCorner = m_origin - (u * halfWidth) - (v * halfHeight) - w;


}

Camera::~Camera() {

}

 Vector3d&
Camera::getBottomLeftCorner()  {
	return m_bottomLeftCorner;
}

void
Camera::setBottomLeftCorner( Vector3d &bottomLeftCorner) {
	m_bottomLeftCorner = bottomLeftCorner;
}

Vector3d
Camera::getHeight()  {
	return m_height;
}

void
Camera::setHeight(Vector3d &height) {
	m_height = height;
}

 Vector3d&
Camera::getOrigin()  {
	return m_origin;
}

void
Camera::setOrigin( Vector3d &origin) {
	m_origin = origin;
}

Vector3d
Camera::getWidth()  {
	return m_width;
}

Ray
Camera::getRay(double u, double v) {

	//w = unitVector(lookFrom - lookAt)
	//u = unitVector(vUp x w)
	//v = w x u

	Vector3d destinationVector(0,0,0);

	destinationVector = m_bottomLeftCorner + m_height * u + m_width * v;

	Ray ray(m_origin, destinationVector - m_origin);

	return ray;

}

 Vector3d& Camera::getLookAt()  {
	return m_lookAt;
}

void Camera::setLookAt( Vector3d &lookAt) {
	m_lookAt = lookAt;
}

 Vector3d& Camera::getLookFrom()  {
	return m_lookFrom;
}

void Camera::setLookFrom( Vector3d &lookFrom) {
	m_lookFrom = lookFrom;
}

 Vector3d& Camera::getVUp()  {
	return m_vUp;
}

void Camera::setVUp( Vector3d &vUp) {
	m_vUp = vUp;
}

void
Camera::setWidth(Vector3d &width) {
	m_width = width;
}

