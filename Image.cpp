/*
 * Image.cpp
 *
 *  Created on: Apr 10, 2020
 *      Author: sandrogiannini
 */

#include "Image.h"


Image::Image() {

	circle = Sphere(0, 0, -1, 0.50);

}

Image::~Image() {

}

void
Image::write(std::string filename){

	std::ofstream picture;
	picture.open (filename);

	// writing some metadata
	picture << "P3\n";
	picture << std::to_string(COLUMNS) + " " + std::to_string(ROWS)+ "\n";
	picture << "255 \n";

	// writing pixels
	for (unsigned int i = 1; i <= ROWS; i++){

		if(i % 10 == 0) {
			std::cout << i << " Rows have been processed" << std::endl;
		}

		for (unsigned int z = 0; z < COLUMNS; z++){
			picture << pixel[i - 1][z].getX();
			picture << " ";
			picture << pixel[i - 1][z].getY();
			picture << " ";
			picture << pixel[i - 1][z].getZ();
			picture << " ";

		}
			picture << "\n";
	}

	picture.close();

}

void
Image::runRayTracer(){

	Vector3d verticalOffset(0,0,0);
	Vector3d horizontalOffset(0,0,0);
	Vector3d destinationVector(0,0,0);
	Vector3d originVector(0,0,0);
	Vector3d bottomLeftCorner(-2, -1, -1);
	Vector3d pixelColor;
	double x, y;


	for (unsigned int i = 0; i < ROWS; i++){

		 y = ((double)i/ROWS) * 2;
		 verticalOffset.setY(y);

		for (unsigned int z = 0; z < COLUMNS; z++){


			 x = ((double)z/COLUMNS) * 4;

			 horizontalOffset.setX(x);
			 destinationVector = verticalOffset + horizontalOffset + bottomLeftCorner;

			 Ray ray(originVector, destinationVector);
			 pixelColor = calculatePixelColor(ray, i);

			 //store it
			 pixel[i][z] = pixelColor;
		}

	}

}

Vector3d
Image::calculatePixelColor(Ray ray, double y){

	Vector3d blue(0, 0, 255);
	Vector3d white(255, 255, 255);
	Vector3d pixelColor(1.0,1.0,1.0);


	if(rayHitsSphere(ray)){
		pixelColor = Vector3d(255, 0, 0);
	} else {

		//pixelColor = (1.0-t)*blue + t*white
		double t = y / 100;
		blue = blue * (1.0 - t);
		white = white * t;
		pixelColor = blue + white;

		//Casting to integers
		pixelColor.setX((int)pixelColor.getX());
		pixelColor.setY((int)pixelColor.getY());
		pixelColor.setZ((int)pixelColor.getZ());
	}

	return pixelColor;
}

bool
Image::rayHitsSphere(Ray ray){

	Vector3d e = ray.getOriginVector();
	Vector3d d = ray.getDestinationVector();
	Vector3d c = circle.getCenter();
	double r  = circle.getRarius();


	//D = (d·(e-c))2 – (d·d)((e-c)·(e-c)-R2)
	double disc = ((d.dot(e - c)) * (d.dot(e - c))) -
			( (d.dot(d)) *
					((e-c).dot(e-c) -
							(r*r)));
	// TESTING
	//std::cout << "origin is X: " << e.getX() << " Y: " << e.getY() <<
	//		" destination is X: " << d.getX() << " Y: " << d.getY()
	//		<< " circle center is X: " << c.getX() << " Y: " << c.getY() <<
	//		" Radius is " << r << std::endl;

	if (disc > 0){
		return true;
	} else {

	return false;

	}
}

