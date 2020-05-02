/*
 * Camera.h
 *
 *  Created on: Apr 22, 2020
 *      Author: sandrogiannini
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include "Vector3d.h"
#include "Ray.h"
#include "Constants.h"

class Camera {

	Vector3d m_origin;
	Vector3d m_bottomLeftCorner;
	Vector3d m_lookFrom;
	Vector3d m_lookAt;
	Vector3d m_vUp;
	Vector3d m_width;
	Vector3d m_height;

public:
	Camera(double, double);
	virtual ~Camera();
	Ray getRay(double, double);
	 Vector3d& getBottomLeftCorner() ;
	void setBottomLeftCorner( Vector3d &bottomLeftCorner);
	 Vector3d getHeight() ;
	void setHeight( Vector3d &height);
	 Vector3d& getOrigin() ;
	void setOrigin( Vector3d &origin);
	 Vector3d getWidth() ;
	void setWidth( Vector3d &width);
	 Vector3d& getLookAt() ;
	void setLookAt( Vector3d &lookAt);
	 Vector3d& getLookFrom() ;
	void setLookFrom( Vector3d &lookFrom);
	 Vector3d& getVUp() ;
	void setVUp( Vector3d &vUp);
};

#endif /* CAMERA_H_ */
