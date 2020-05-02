/*
 * Light.h
 *
 *  Created on: Apr 20, 2020
 *      Author: sandrogiannini
 */

#ifndef LIGHT_H_
#define LIGHT_H_

#include "Vector3d.h"

class Light {

	double diffuse;
	double ambience;
	double specular;
	Vector3d center;




public:
	Light(Vector3d c, double dif, double amb, double spec);
	Light();
	virtual ~Light();
	double getAmbience() ;
	void setAmbience(double ambience);
	 Vector3d& getCenter() ;
	void setCenter( Vector3d &center);
	double getDiffuse() ;
	void setDiffuse(double diffuse);
	double getSpecular() ;
	void setSpecular(double specular);
};

#endif /* LIGHT_H_ */
