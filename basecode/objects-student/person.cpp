// *****************************************************************************************
// KXC354 - Computer Graphics & Animation - 2014
// Assignment 1 & 2
// 3D Engine Code
// *****************************************************************************************
//
// Author: Tony Gray
//
// person.cpp
//
// This file defines the class for person objects



// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "prefix.h"
#include "person.h"
#include "utility.h"



// -----------------------------------------------------------------------------------------
// globals
// -----------------------------------------------------------------------------------------
extern vector<object3d*> gShapeVector;



// -----------------------------------------------------------------------------------------
// constructor
// -----------------------------------------------------------------------------------------

person::person()
{
	// Initialise the object's state
	setName("person");
	
	//body
	body = new cube;
	body->setDeformation(1.0, 1.0, 0.5);
	body->setParent(this);
	body->setColour(1.0, 1.0, 1.0);
	
	//head
	head = new sphere(20);
	head->setScale(0.7);
	head->setColour(1.0, 1.0, 1.0);
	head->setPosition(0.0, 1.4, 0.0);
	head->setParent(body);
	
	//shouder_right
	rightsShoulder = new sphere(20);
	rightsShoulder->setScale(0.4);
	rightsShoulder->setColour(0.0, 1.0, 1.0);
	rightsShoulder->setPosition(0.9, 0.6, 0.0);
	rightsShoulder->setParent(body);
	
	leftShoulder = new sphere(20);
	leftShoulder->setScale(0.4);
	leftShoulder->setColour(0.0, 1.0, 1.0);
	leftShoulder->setPosition(-0.9, 0.6, 0.0);
	leftShoulder->setParent(body);

	//left_arm
	leftArm = new cube;
	leftArm->setScale(1.0);
	leftArm->setColour(1.0, 1.0, 0.0);
	leftArm->setParent(rightsShoulder);
	leftArm->setDeformation(2.0, 0.5, 0.5);
	leftArm->setPosition(1.0, -2.0, 0.0);
	leftArm->setRotation('z', -90);

	//right_arm
	rightArm = new cube;
	rightArm->setScale(1.0);
	rightArm->setColour(1.0, 1.0, 0.0);
	rightArm->setParent(leftShoulder);
	rightArm->setDeformation(2.0, 0.5, 0.5);
	rightArm->setPosition(-1.0, -2.0, 0.0);
	rightArm->setRotation('z', 90);

	//left_leg
	leftLeg = new cube;
	leftLeg->setDeformation(0.2, 0.8, 0.3);
	leftLeg->setPosition(0.4, -1.5, 0.0);
	leftLeg->setColour(1.0, 0.0, 0.0);
	leftLeg->setParent(body);

	//right_leg
	rightLeg = new cube;
	rightLeg->setDeformation(0.2, 0.8, 0.3);
	rightLeg->setPosition(-0.4, -1.5, 0.0);
	rightLeg->setColour(1.0, 0.0, 0.0);
	rightLeg->setParent(body);

	this->setPosition(0 * 1.0, -0.5, 0);

	// put the shape onto the shapeVector so it gets draw messages
	gShapeVector.push_back(this);
}

void person::show()
{
	head->show();
	rightsShoulder->show();
	leftShoulder->show();
	body->show();
	rightArm->show();
	leftArm->show();
	rightArm->show();
	leftLeg->show();
	rightLeg->show();
}

void person::hide()
{
	head->hide();
	rightsShoulder->hide();
	leftShoulder->hide();
	body->hide();
	rightArm->hide();
	leftArm->hide();
	rightArm->hide();
	leftLeg->hide();
	rightLeg->hide();
}


void person::animate(float time, float positionx, float positionz)
{
	float theAngle = (sin_d(time * 360) * (-10)) + (10);
	leftLeg->setRotation('x', theAngle);
	float theAngle2 = (sin_d(time * 360) * (10)) + (-10);
	rightLeg->setRotation('x', theAngle2);
	this->setRotation('y', 90);
	this->setPosition(positionx + time * 1.0, -0.5, positionz);

}