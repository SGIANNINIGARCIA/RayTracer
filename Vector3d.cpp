/*
 * Vector3d.cpp
 *
 *  Created on: Feb 23, 2020
 *      Author: sandrogiannini
 */

#include "Vector3d.h"

Vector3d::Vector3d() {

	m_x = 0;
	m_y = 0;
	m_z = 0;
}

Vector3d::Vector3d(float x, float y, float z) {

	m_x = x;
	m_y = y;
	m_z = z;

}

Vector3d::~Vector3d() { }



float Vector3d::getX()  {
	return m_x;
}

void Vector3d::setX(float x) {
	m_x = x;
}

float Vector3d::getY()  {
	return m_y;
}

void Vector3d::setY(float y) {
	m_y = y;
}

float Vector3d::getZ(){
	return m_z;
}

void Vector3d::setZ(float z){
	m_z = z;
}

Vector3d
Vector3d::operator+(Vector3d vec)  {

	Vector3d sum;
	sum.m_x = m_x + vec.m_x;
	sum.m_y = m_y + vec.m_y;
	sum.m_z = m_z + vec.m_z;

	return sum;
}

Vector3d
Vector3d::operator*(float x)  {

	Vector3d mul;
	mul.m_x = m_x * x;
	mul.m_y = m_y * x;
	mul.m_z = m_z * x;

	return mul;
}

Vector3d
Vector3d::operator*( Vector3d &vec){
	Vector3d mul;
	mul.m_x = m_x * vec.m_x;
	mul.m_y = m_y * vec.m_y;
	mul.m_z = m_z * vec.m_z;

	return mul;

}

Vector3d
Vector3d::operator/(Vector3d vec){
	Vector3d mul;
	mul.m_x = m_x / vec.m_x;
	mul.m_y = m_y / vec.m_y;
	mul.m_z = m_z / vec.m_z;

	return mul;

}

Vector3d
Vector3d::operator-( Vector3d vec)  {

	Vector3d def;
	def.m_x = m_x + (-vec.m_x);
	def.m_y = m_y + (-vec.m_y);
	def.m_z = m_z + (-vec.m_z);

	return def;
}

Vector3d
Vector3d::operator/(float div){

	Vector3d res;
	res.m_x = m_x / div;
	res.m_y = m_y / div;
	res.m_z = m_z / div;

	return res;

}

void
Vector3d::makeUnitVector(){

	float magnitud = sqrt((m_x*m_x) + (m_y*m_y) + (m_z*m_z));

	m_x = (m_x/magnitud);
	m_y = (m_y/magnitud);
	m_z = (m_z/magnitud);

}

double
Vector3d::dot( Vector3d &vec){
	return (m_x * vec.m_x) + (m_y * vec.m_y) + (m_z * vec.m_z);
}

void
Vector3d::print(){
	std::cout << " X= " << m_x << " Y= " << m_y << " Z= " << m_z << std::endl;
}

void
Vector3d::castToInt(){

	m_x = (int)m_x;
	m_y = (int)m_y;
	m_z = (int)m_z;

}
void
Vector3d::clamp(){

	m_x = (m_x > 255) ? 255 : m_x;
	m_y = (m_y > 255) ? 255 : m_y;
	m_z = (m_z > 255) ? 255 : m_z;

}

Vector3d
Vector3d::cross(Vector3d vec){

	    Vector3d res(0,0,0);

	    res.m_x = m_y * vec.m_z - m_z * vec.m_y;
	    res.m_y = m_z * vec.m_x - m_x * vec.m_z;
	    res.m_z = m_x * vec.m_y - m_y * vec.m_x;
		return res;
}

