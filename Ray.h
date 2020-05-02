/*
 * Ray.h
 *
 *  Created on: Apr 10, 2020
 *      Author: sandrogiannini
 */

#ifndef RAY_H_
#define RAY_H_

#include "Vector3d.h"

class Ray {

	Vector3d originVector;
	Vector3d destinationVector;

public:
	Ray(Vector3d, Vector3d);
	Ray();
	virtual ~Ray();
	 Vector3d& getDestinationVector() ;
	void setDestinationVector( Vector3d &destinationVector);
	 Vector3d& getOriginVector() ;
	void setOriginVector( Vector3d &originVector);
	Vector3d pointAtParameter(float t);
};

#endif /* RAY_H_ */
