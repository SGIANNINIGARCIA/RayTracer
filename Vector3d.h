/*
 * Vector3d.h
 *
 *  Created on: Feb 23, 2020
 *      Author: sandrogiannini
 */

#ifndef SRC_VECTOR2D_H_
#define SRC_VECTOR2D_H_

#include <cmath>
#include <iostream>

class Vector3d {
private:
	float m_x;
	float m_y;
	float m_z;

public:
	Vector3d();
	Vector3d(float x, float y, float z);
	virtual ~Vector3d();
	Vector3d operator+(Vector3d vec);
	Vector3d cross(Vector3d vec);
	Vector3d operator-(Vector3d vec);
	Vector3d operator*(float);
	Vector3d operator*( Vector3d &vec);
	Vector3d operator/(float);
	Vector3d operator/(Vector3d);
	void makeUnitVector();
	float getX() ;
	void setX(float x);
	float getY() ;
	void setY(float y);
	float getZ();
	void setZ(float);
	double dot( Vector3d &vec);
	void print();
	void castToInt();
	void clamp();
};

#endif /* SRC_VECTOR2D_H_ */
