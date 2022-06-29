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
#include "trees.h"
#include "utility.h"



// -----------------------------------------------------------------------------------------
// globals
// -----------------------------------------------------------------------------------------
extern vector<object3d*> gShapeVector;



// -----------------------------------------------------------------------------------------
// constructor
// -----------------------------------------------------------------------------------------

trees::trees()
{
	// Initialise the object's state
	setName("trees");
	tronco = new texture("tronco.jpg");
	folhas = new texture("folhas.jpg");

	body = new tcube();
	body->setTexture(tronco);
	body->setDeformation(1,3,1);
	body->setPosition(0, 2, 0);
    //body->setColour(1.0, 0.3, 0.1);
	body->setParent(this);

	leaves = new tsphere();
	leaves->setTexture(folhas);
	leaves->setScale(4);
	leaves->setParent(this);
	leaves->setPosition(0,7, 0);
	leaves->setColour(0.8, 1,0.1);
	
	
	// put the shape onto the shapeVector so it gets draw messages
	gShapeVector.push_back(this);
}



void trees::hide() {
	body->hide();
	leaves->hide();
}

void trees::show() {
	body->show();
	leaves->show();

}