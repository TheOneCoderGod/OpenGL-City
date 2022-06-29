// *****************************************************************************************
// KXC354 - Computer Graphics & Animation - 2014
// Assignment 1 & 2
// 3D Engine Code
// *****************************************************************************************
//
// Author: Tony Gray
//
// cube.cpp
//
// This file defines the class for cube objects



// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "prefix.h"
#include "environmet.h"
#include "utility.h"
#include "camera.h"


// -----------------------------------------------------------------------------------------
// globals
// -----------------------------------------------------------------------------------------
extern vector<object3d*> gShapeVector;
extern cameraClass		gCamera;								// the camera



// -----------------------------------------------------------------------------------------
// constructor
// -----------------------------------------------------------------------------------------

environmet::environmet()
{
	// Initialize the object's state
	setName("cube");

	//people
	person1 = new person();
	person2 = new person();
	person3 = new person();
	person4 = new person();
	person5 = new person();
	person6 = new person();

	person1->hide();
	person2->hide();
	person3->hide();
	person4->hide();
	person5->hide();
	person6->hide();
	
	//cars
	car1 = new cart();
	car2 = new cart();
	car3 = new cart();
	car4 = new cart();
	car5 = new cart();
	car6 = new cart();

	car1->hide();
	car2->hide();
	car3->hide();
	car4->hide();
	car5->hide();
	car6->hide();
	

	// put the shape onto the shapeVector so it gets draw messages
	gShapeVector.push_back(this);
}


void environmet::animate(float time) {
	int speed = 3;
	int carSpeed = 3;

	if (time >= 0 && time <= 10) {
		gCamera.setPosition(-(time), (time), (time));
		gCamera.setTarget(car1);
		car1->show();
		car1->animate(-(time), -15, -10);
		car2->show();
		car2->animate(-(time), -15, 0);
	
	}else if (time > 10 && time <= 20) {

		person1->hide();
		person2->hide();
		person3->hide();
		person4->hide();
		person5->hide();
		person6->hide();
		car1->hide();
		car2->hide();
		car3->hide();
		car4->hide();
		car5->hide();
		car6->hide();

		gCamera.setPosition((time), (time), (time));
		gCamera.setTarget(person4);
		
		person4->show();
		person4->animate((time ), 30, 50);
		person5->show();
		person5->animate((time - 5), 30, 50);
	    person6->show();
		person6->animate((time - 5), 30, 60);

	}else if (time > 20 && time <= 50) {

		person1->hide();
		person2->hide();
		person3->hide();
		person4->hide();
		person5->hide();
		person6->hide();
		car1->hide();
		car2->hide();
		car3->hide();
		car4->hide();
		car5->hide();
		car6->hide();

		gCamera.setPosition(-50 - (time - 20) * 10, 70, 12);
		gCamera.setTarget(150, 0, 0);

		//people
		//people going from right to left in the front
		person1->show();
		person1->animate(-(time)*speed, -30, -30);

		person2->show();
		person2->animate(-(time)*speed, -30, -40);
		
		person3->show();
		person3->animate(-(time - 5) * speed, 30, -30);
		
		//people going from left to right in the back
		
		person4->show();
		person4->animate((time ) * speed, 30, 50);
		
		person5->show();
		person5->animate((time - 5) * speed, 30, 50);
		
		person6->show();
		person6->animate((time - 5) * speed, 30, 60);
		
		//cars
		//cars coming from left to right in front
		
		car1->show();
		car1->animate(-(time)*carSpeed, -15, -10);
		
		car2->show();
		car2->animate(-(time)*carSpeed, -15, 0);
		
		car3->show();
		car3->animate((-time+30)*carSpeed, -15, -10);
		
		//cars going from left to right back
	
		car4->show();
		car4->animate((time)*carSpeed, 15, 30);
	
		car5->show();
		car5->animate((time-30)*carSpeed, 15, 30);

		car6->show();
		car6->animate((time-60)*carSpeed, 15, 30);
	
	}else if (time > 30 && time <= 40) {

		gCamera.setPosition(-150 + (time - 30), 70 + (time - 30) * 5, 12 + (time - 30));
		gCamera.setTarget(150, 0, 0);

	}else if (time > 40 && time <= 50) {

		gCamera.setPosition(-150 + (time - 30), 70 + (time - 30) * 1.5, 12 + (time - 30));
		gCamera.setTarget(car6);

	}else if (time > 50 && time <= 60) {
		person1->hide();
		person2->hide();
		person3->hide();
		person4->hide();
		person5->hide();
		person6->hide();
		car1->hide();
		car2->hide();
		car3->hide();
		car4->hide();
		car5->hide();
		car6->hide();

		gCamera.setPosition(-70 + (time - 30), 5 + (time - 30) * 1.5, 0 + (time - 30));
		gCamera.setTarget(car6);

		car6->show();
		car6->animate((time - 60), 15, 30);
	}
	


	//people
	//people going from right to left in the front
	//if (time > 0) {
	//	person1->show();
	//	person1->animate(-(time)*speed, -15, -30);
	//}

	//if (time > 0) {
	//	person2->show();
	//	person2->animate(-(time)*speed, -15, -40);
	//}

	//if (time > 2) {
	//	person3->show();
	//	person3->animate(-(time - 5) * speed, -15, -30);
	//}

	////people going from left to right in the back
	//if (time > 10 && time <= 20) {
	//	person4->show();
	//	person4->animate((time ) * speed, 15, 50);
	//}

	//if (time > 10 && time <= 20) {
	//	person5->show();
	//	person5->animate((time - 5) * speed, 15, 50);
	//}

	//if (time > 10 && time <= 20) {
	//	person6->show();
	//	person6->animate((time - 5) * speed, 15, 60);
	//}

	////cars
	////cars coming from left to right in front
	//if (time >= 0 && time <= 10) {
	//	car1->show();
	//	car1->animate(-(time)*carSpeed, -15, -10);
	//}

	//if (time >= 0 && time <= 10) {
	//	car2->show();
	//	car2->animate(-(time)*carSpeed, -15, 0);
	//}

	//if (time > 6) {
	//	car3->show();
	//	car3->animate((-time+30)*carSpeed, -15, -10);
	//}

	////cars going from left to right back
	//if (time > 0) {
	//	car4->show();
	//	car4->animate((time)*carSpeed, 15, 30);
	//}

	//if (time > 10) {
	//	car5->show();
	//	car5->animate((time-30)*carSpeed, 15, 30);
	//}

	//if (time > 20) {
	//	car6->show();
	//	car6->animate((time-60)*carSpeed, 15, 30);
	//}

}

void environmet::hide() {
	person1->hide();
	person2->hide();
	person3->hide();
	person4->hide();
	person5->hide();
	person6->hide();

	car1->hide();
	car2->hide();
	car3->hide();
	car4->hide();
	car5->hide();
	car6->hide();
}

void environmet::show() {
	person1->show();
	person2->show();
	person3->show();
	person4->show();
	person5->show();
	person6->show();

	car1->show();
	car2->show();
	car3->show();
	car4->show();
	car5->show();
	car6->show();
}