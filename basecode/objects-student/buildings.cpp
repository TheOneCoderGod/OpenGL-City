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
#include "buildings.h"
#include "utility.h"



// -----------------------------------------------------------------------------------------
// globals
// -----------------------------------------------------------------------------------------
extern vector<object3d*> gShapeVector;



// -----------------------------------------------------------------------------------------
// constructor
// -----------------------------------------------------------------------------------------

buildings::buildings()
{
	// Initialise the object's state
	setName("buildings");

	concrete = new texture("concrete.jpg");
	wood = new texture("wood.jpg");
	glass = new texture("glass.jpg");

	body = new tcube();
	body->setTexture(concrete);
	body->setPosition(0, 17, 0);
	body->setParent(this);
	body->setDeformation(10, 20, 5);

	window1 = new tcube();
	window1->setTexture(glass);
	window1->setScale(3);
	window1->setPosition(-5, 10,2.5);
	window1->setParent(this);
	//window1->setColour(1.0, 0.6, 0.4);

	window2 = new tcube();
	window2->setTexture(glass);
	window2->setScale(3);
	window2->setPosition(5, 10, 2.5);
	window2->setParent(this);
	//window2->setColour(1.0, 0.6, 0.4);

	window3 = new tcube();
	window3->setTexture(glass);
	window3->setScale(3);
	window3->setPosition(-5, 20, 2.5);
	window3->setParent(this);
	//window3->setColour(1.0, 0.6, 0.4);

	window4 = new tcube();
	window4->setTexture(glass);
	window4->setScale(3);
	window4->setPosition(5, 20, 2.5);
	window4->setParent(this);
	//window4->setColour(1.0, 0.6, 0.4);

	window5 = new tcube();
	window5->setTexture(glass);
	window5->setScale(3);
	window5->setPosition(-5, 30, 2.5);
	window5->setParent(this);
	//window5->setColour(1.0, 0.6, 0.4);

	window6 = new tcube();
	window6->setTexture(glass);
	window6->setScale(3);
	window6->setPosition(5, 30, 2.5);
	window6->setParent(this);
	//window6->setColour(1.0, 0.6, 0.4);

	door = new tcube();
	door->setTexture(wood);
	door->setDeformation(2.0, 3.0, 0.1);
	door->setPosition(0, 0, 5);
	//door->setColour(1.0, 0.1, 0.9);
	door->setParent(this);

	
	// put the shape onto the shapeVector so it gets draw messages
	gShapeVector.push_back(this);
}



void buildings::hide() {
	body->hide();
	window1->hide();
	window2->hide();
	window3->hide();
	window4->hide();
	window5->hide();
	window6->hide();
	door->hide();
}

void buildings::show() {
	body->show();
	window1->show();
	window2->show();
	window3->show();
	window4->show();
	window5->show();
	window6->show();
	door->show();

}