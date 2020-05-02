/*
 * Image.cpp
 *
 *  Created on: Apr 10, 2020
 *      Author: sandrogiannini
 */

#include "Image.h"


Image::Image() {

	setUp();

}

Image::~Image() {

}

void
Image::setUp(){

	spheres.push_back(circle);
	circle = Sphere(Vector3d(-0.4, -0.4, -2.8),Vector3d(0,100,0), 0.5);
	circle.setReflection(false);
	spheres.push_back(circle);
	circle = Sphere(Vector3d(1.2, -0.4, -2.7),Vector3d(240,128,128), 0.5);
	circle.setFuzziness(0.0001);
	spheres.push_back(circle);
	circle = Sphere(Vector3d(0, -30, -10),Vector3d(204,204,0), 30);
	circle.setTexture(true);
	circle.setFuzziness(0.1);
	spheres.push_back(circle);

	light = Light(Vector3d(-5,0,5), 0.9, 0.7, 0.7);
	lights.push_back(light);

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
	for (unsigned int i = ROWS; i > 0; i--){

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
	std::cout << "Image finished rendering" << std::endl;

}

void
Image::runRayTracer(){

	Vector3d verticalOffset(0,0,0);
	Vector3d horizontalOffset(0,0,0);
	Vector3d destinationVector(0,0,0);
	Vector3d originVector(0,0,0);
	Vector3d bottomLeftCorner(-2, -1, -1);
	double x, y;
	Camera camera (-25, double(COLUMNS/ROWS));
	int initDepth = 0;


	for (unsigned int i = 0; i < ROWS; i++){

		if((i + 1)  % 10 == 0) {
			std::cout << i + 1 << " Rows have been processed" << std::endl;
		}

		for (unsigned int z = 0; z < COLUMNS; z++){

			Vector3d pixelColor;

			// ANTI ALIASING
			for (unsigned int a = 0; a < ALIASING; a++){

				y = ((double)(i + randomNumber())/ROWS);
				x = ((double)(z + randomNumber())/COLUMNS);

				Ray ray = camera.getRay(y, x);

				//Vector3d temp = calculatePixelColor(ray, i);

				pixelColor = pixelColor + calculatePixelColor(ray, i, initDepth);

			}

			//store it
			pixelColor = (pixelColor/(ALIASING));
			pixelColor.castToInt();
			pixel[i][z] = pixelColor;
		}

	}

}

Vector3d
Image::calculatePixelColor(Ray ray, double y, int depth){

	if(depth > 3){
		return Vector3d(0,0,0);
	}

	Vector3d totalPixelColor(0,0,0);
	ClosesHit closesHit;
	Vector3d specC;



	if(rayHitsSphere(ray, closesHit)){


		for(int i = 0; i < lights.size(); i++){

			light = lights[i];
			Vector3d pixelColor(0,0,0);


			Vector3d ambient(0,0,0);
			Vector3d diffuse(0,0,0);
			Vector3d specular(0,0,0);

			// Ambient
			// L = kaIa
			//
			ambient = closesHit.Color * light.getAmbience();


			// Diffuse
			// L = kdI max(0,n·l)
			//
			Vector3d n = closesHit.Normal;
			n.makeUnitVector();
			Vector3d l = light.getCenter() - closesHit.HitPoint;
			l.makeUnitVector();
			diffuse = closesHit.Color * light.getDiffuse() * std::max(0.0, n.dot(l));


			// Specular
			// L = kdI max(0,n·h)^p
			//
			Vector3d temp = ray.getDestinationVector() + l;
			temp.makeUnitVector();
			Vector3d h = (ray.getDestinationVector() + l) / (temp);
			h.makeUnitVector();
			specular = closesHit.Color * light.getSpecular() * pow(std::max(0.0, n.dot(h)), SPECULAR_EXP);
			//specular.print();

			// set final color
			pixelColor =  ambient + diffuse + specular;

			pixelColor.clamp();

			Vector3d tempo = ray.getDestinationVector();
			tempo.makeUnitVector();
			specC = tempo - n * 2.0 * tempo.dot(n);

			//specular
			if(closesHit.specular){
				specC = specC +randomeCubeNumber() * closesHit.fuzziness;
				Ray specularRay(closesHit.HitPoint, specC);
				ClosesHit specularHit;

				if(rayHitsSphere(specularRay, specularHit)){
					pixelColor = pixelColor + calculatePixelColor(specularRay, y, depth + 1) * 0.5;
				}
			}

			// Calculate shadow
			Ray shadowRay = Ray(closesHit.HitPoint, light.getCenter());
			ClosesHit shadowHit;

			if(rayHitsSphere(shadowRay, shadowHit)){

				pixelColor = pixelColor * 0.2;

			}



			// if closestHit object should be textured
			if (closesHit.texture) {
				if (generateBrightTexture(closesHit, ray)) {
					pixelColor = pixelColor * 0.4;
				}
			}


			pixelColor.clamp();

			totalPixelColor = totalPixelColor + pixelColor;

		}

		totalPixelColor = totalPixelColor/lights.size();



	} else {

		//pixelColor = (1.0-t)*blue + t*white
		totalPixelColor = Vector3d(173, 216, 230);

	}


	return totalPixelColor;
}

bool
Image::rayHitsSphere(Ray& ray, ClosesHit& closesHit){
	Vector3d e = ray.getOriginVector();
	Vector3d d = ray.getDestinationVector();
	bool flag = false;
	double closestT =  tmax;

	Vector3d c;
	double r;
	double disc = -1;

	for(int i = 0; i < spheres.size(); i++){

		circle = spheres[i];
		Vector3d center = circle.getCenter();
		r  = circle.getRarius();

		// TRIED A DIFFFERENT APPROACH JUST IN CASE
		Vector3d oc = e - center;
		float a = d.dot(d);
		float b = 2 * oc.dot(d);
		float c = oc.dot(oc) - (r*r);
		disc = b*b - 4*a*c;

		//TESTING
		//std::cout << "origin is X: " << e.getX() << " Y: " << e.getY() <<
		//		" destination is X: " << d.getX() << " Y: " << d.getY()
		//		<< " circle center is X: " << c.getX() << " Y: " << c.getY() <<
		//		" Radius is " << r << " and disk is:" << std::endl;


		if (disc > 0) {
			//find both t values
			double t1 = (-b - sqrt(disc)) / (2.0*a);
			double t2 = (-b + sqrt(disc)) / (2.0*a);

			if( t1 > tmin && t1 < tmax ){
				if (t1 < closestT){
					closestT = t1;
					closesHit.t = t1;
					closesHit.HitPoint = ray.pointAtParameter(t1);
					closesHit.Normal = closesHit.HitPoint - center; // will normalize later
					flag = true;
					closesHit.Color = circle.color;
					closesHit.texture = circle.isTexture();
					closesHit.specular = circle.isReflection();
					closesHit.fuzziness = circle.getFuzziness();
				}
			}

			if( t2 > tmin && t2 < tmax ){
				if (t2 < closestT){
					closestT = t2;
					closesHit.t = t2;
					closesHit.HitPoint = ray.pointAtParameter(t2);
					closesHit.Normal = center - closesHit.HitPoint; // will normalize later
					flag = true;
					closesHit.Color = circle.color;
					closesHit.texture = circle.isTexture();
					closesHit.specular = circle.isReflection();
					closesHit.fuzziness = circle.getFuzziness();
				}
			}

		}


	}


	return flag;

}

bool
Image::generateBrightTexture(ClosesHit& ch, Ray ray){

	return (cos(ray.pointAtParameter(ch.getT()).getX() * 2) > 0 ^ sin(ray.pointAtParameter(ch.getT()).getZ() * 2) > 0);
}

Vector3d
Image::randomeCubeNumber() {

	double x = 2 * randomNumber() -1;
	double y = 2 * randomNumber() -1;
	double z = 2 * randomNumber() -1;

	return Vector3d(x,y,z);
}

double
Image::randomNumber(){
	return (double)rand() / (double)RAND_MAX;
}
