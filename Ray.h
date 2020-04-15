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
	const Vector3d& getDestinationVector() const;
	void setDestinationVector(const Vector3d &destinationVector);
	const Vector3d& getOriginVector() const;
	void setOriginVector(const Vector3d &originVector);
};

#endif /* RAY_H_ */
