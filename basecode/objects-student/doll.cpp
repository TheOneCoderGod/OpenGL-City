// *****************************************************************************************
// KXC354 - Computer Graphics & Animation - 2014
// Assignment 1 & 2
// 3D Engine Code
// *****************************************************************************************
//
// Author: Tony Gray
//
// doll.cpp
//
// This file defines the class for letterU objects



// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "prefix.h"
#include "utility.h"
#include "doll.h"





// -----------------------------------------------------------------------------------------
// globals
// -----------------------------------------------------------------------------------------
extern vector<object3d*> gShapeVector;



// -----------------------------------------------------------------------------------------
// constructor
// -----------------------------------------------------------------------------------------

doll::doll()
{
	// Initialize the object's state
	setName("doll");
	setColour(0.15, .85, .35, 1.0);					// default color

	//main body
	roda = new wheel(200);
	roda->setParent(this);
	roda->setColour(1.0, 0.5, 0.4);

	//Left leg
	leftLeg = new sweep("jar.txt", 200);
	leftLeg->setPosition(-1, -1.2, 1.0);
	leftLeg->setScale(0.4);
	leftLeg->setParent(roda);
	leftLeg->setColour(1.0, 0.8, 0.4);

	//Right leg
	rightLeg = new sweep("jar.txt", 200);
	rightLeg->setPosition(1, -1.2, 1.0);
	rightLeg->setScale(0.4);
	rightLeg->setParent(roda);
	rightLeg->setColour(1.0, 0.8, 0.4);

	//Left Arm
	leftArm = new sweep("jar.txt", 200);
	leftArm->setRotation('z', -60);
	leftArm->setPosition(1, 1.2, 1.0);
	leftArm->setScale(0.5);
	leftArm->setParent(roda);
	leftArm->setColour(1.0, 0.5, 0.8);

	//Right Arm
	rightArm = new sweep("jar.txt", 200);
	rightArm->setRotation('z', 60);
	rightArm->setPosition(-1, 1.2, 1.0);
	rightArm->setScale(0.5);
	rightArm->setParent(roda);
	rightArm->setColour(1.0, 0.5, 0.8);

	//Neck
	neck = new cube();
	neck->setPosition(0, 2, -0.7);
	neck->setParent(roda);
	neck->setColour(0.6, 0.9, 0.6);

	//Head
	head = new sphere(200);
	head->setPosition(0, 4, -0.7);
	head->setScale(2);
	head->setParent(roda);
	//head->setColour(1.0, 0.5, 0.4);

	//left eye
	leftEye = new sphere(200);
	leftEye->setRotation('y', -90);
	leftEye->setDeformation(0.1, 0.5, 0.3);
	leftEye->setPosition(-0.5, 4, 1.2);
	leftEye->setColour(1.0, 0.5, 0.4);
	leftEye->setParent(roda);
	leftEye->setColour(0.0, 0.0, 0.0);
	
	// right eye
	rightEye = new sphere(200);
	rightEye->setRotation('y', -90);
	rightEye->setDeformation(0.1, 0.5, 0.3);
	rightEye->setPosition(0.5, 4, 1.2);
	rightEye->setColour(1.0, 0.5, 0.4);
	rightEye->setParent(roda);
	rightEye->setColour(0.0, 0.0, 0.0);
	
	//Mouth
	mouth = new sphere(200);
	mouth->setRotation('y', -90);
	mouth->setDeformation(0.2, 0.2, 0.5);
	mouth->setPosition(0, 3, 1.1);
	mouth->setColour(1.0, 0.5, 0.4);
	mouth->setParent(roda);
	//mouth->setColour(1.0, 0.5, 0.4);

	//Tail
	tail = new extrusion("star.txt","path.txt");
	tail->setRotation('y', -180,'x', -50);
	tail->setPosition(0, -1, -1.5); 
	tail->setScale(0.5);
	tail->setParent(roda);
	//tail->setColour(1.0, 0.5, 0.4);

	//hat
	hat = new torus(200,20,1,0.2);
	hat->setScale(2);
	hat->setPosition(0, 5.2, 0);
	hat->setParent(roda);
	//hat->setColour(1.0, 0.5, 0.4);

	hat2 = new sphere(200);
	hat2->setPosition(0, 5.5, 0);
	hat2->setDeformation(1, 0.25559, 1);
	hat2->setScale(2);
	hat2->setParent(roda);
	hat2->setColour(1.0, 1.0, 0.0);


	// put the shape onto the shapeVector so it gets draw messages
	gShapeVector.push_back(this);
}

void doll::hide() {
	 roda->hide();
	 leftLeg->hide();
	 rightLeg->hide();
	 rightArm->hide();
	 leftArm->hide();
	 neck->hide();
	 head->hide();
	 leftEye->hide();
	 rightEye->hide();
	 mouth->hide();
	 tail->hide();
	 hat->hide();
	 hat2->hide();
}

void doll::show() {
	roda->show();
	leftLeg->show();
	rightLeg->show();
	rightArm->show();
	leftArm->show();
	neck->show();
	head->show();
	leftEye->show();
	rightEye->show();
	mouth->show();
	tail->show();
	hat->show();
	hat2->show();
}

void doll::animate(float time) {
	roda->setRotation('y', +time * 90);
	
}



