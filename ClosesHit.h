/*
 * ClosesHit.h
 *
 *  Created on: Apr 20, 2020
 *      Author: sandrogiannini
 */

#ifndef CLOSESHIT_H_
#define CLOSESHIT_H_

#include "Vector3d.h"

class ClosesHit {



public:

	double t;
	Vector3d Normal;
	Vector3d HitPoint;
	Vector3d Color;
	bool texture;
	bool specular;
	bool singleStripe;
	double fuzziness;

	ClosesHit();
	virtual ~ClosesHit();
	 Vector3d& getHitPoint() ;
	void setHitPoint( Vector3d &hitPoint);
	 Vector3d& getNormal() ;
	void setNormal( Vector3d &normal);
	double getT() ;
	void setT(double t);
	bool isTexture();
	void setTexture(bool texture);
	bool isSpecular() const;
	void setSpecular(bool specular);
	const Vector3d& getColor() const;
	void setColor(const Vector3d &color);
	double getFuzziness() const;
	void setFuzziness(double fuzziness);
	bool isSingleStripe() const;
	void setSingleStripe(bool singleStripe);
};

#endif /* CLOSESHIT_H_ */
