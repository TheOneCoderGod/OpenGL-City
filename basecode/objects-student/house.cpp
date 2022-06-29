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
#include "house.h"
#include "utility.h"



// -----------------------------------------------------------------------------------------
// globals
// -----------------------------------------------------------------------------------------
extern vector<object3d*> gShapeVector;



// -----------------------------------------------------------------------------------------
// constructor
// -----------------------------------------------------------------------------------------

house::house()
{
	// Initialise the object's state
	setName("house");

	concrete = new texture("hwood.jpg");
    glass = new texture("glass.jpg");
	wood = new texture("wood.jpg");
	tiles = new texture("tiles.jpg");;

	body = new tcube();
	body->setTexture(concrete);
	body->setPosition(0, 7, -5);
	body->setParent(this);
	body->setDeformation(15, 10, 10);
	body->setColour(0.2, 0.2, 0.4);

	window1 = new tcube();
	window1->setTexture(glass);
	window1->setScale(3);
	window1->setPosition(-7, 7, 2.5);
	window1->setParent(this);
	//window1->setColour(1.0, 0.6, 0.4);

	window2 = new tcube();
	window2->setTexture(glass);
	window2->setScale(3);
	window2->setPosition(7,7, 2.5);
	window2->setParent(this);
	//window2->setColour(1.0, 0.6, 0.4);

	door = new tcube();
	door->setTexture(wood);
	door->setDeformation(2.0, 3.0, 0.1);
	door->setPosition(0, 0, 5);
	//door->setColour(1.0, 0.1, 0.9);
	door->setParent(this);

	roof1 = new tcube();
	roof1->setScale(5);
	roof1->setTexture(tiles);
	roof1->setParent(this);
	roof1->setPosition(7.5, 22, -3.9);
	roof1->setDeformation(0.1, 2.5, 2.0);
	roof1->setRotation('z', 60);

	roof2 = new tcube();
	roof2->setScale(5);
	roof2->setTexture(tiles);
	roof2->setParent(this);
	roof2->setPosition(-7.5, 22, -3.9);
	roof2->setDeformation(0.1, 2.5, 2.0);
	roof2->setRotation('z', -60);




	
	// put the shape onto the shapeVector so it gets draw messages
	gShapeVector.push_back(this);
}



void house::hide() {
	body->hide();
	window1->hide();
	window2->hide();
	roof1->hide();
	roof2->hide();
	door->hide();
}

void house::show() {
	body->show();
	window1->show();
	window2->show();
	roof1->show();
	roof2->show();
	door->show();
}