// *****************************************************************************************
// KXC354 - Computer Graphics & Animation - 2014
// Assignment 1 & 2
// 3D Engine Code
// *****************************************************************************************
//
// Author: Tony Gray
//
// cart.cpp
//
// This file defines the class for cart objects



// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "prefix.h"
#include "cart.h"
#include "utility.h"


// -----------------------------------------------------------------------------------------
// globals
// -----------------------------------------------------------------------------------------
extern vector<object3d*> gShapeVector;



// -----------------------------------------------------------------------------------------
// constructor
// -----------------------------------------------------------------------------------------

cart::cart()
{
	// Initialise the object's state
	setName("Cart");

	wood = new texture("boxtex.jpg");

	bottom = new tcube();
	bottom->setDeformation(3.0, 0.1, 1.5);
	bottom->setTexture(wood);
	bottom->setParent(this);
	bottom->setPosition(-5.0, 0.0,0.0);

	side1 = new tcube();
	side1->setTexture(wood);
	side1->setParent(bottom);
	side1->setPosition(0.0, 1.1, 1.40);
	side1->setDeformation(0.1, 1.0, 3.0);
	side1->setRotation('y', 90);

	side2 = new tcube();
	side2->setTexture(wood);
	side2->setParent(bottom);
	side2->setPosition(0.0, 1.1, -1.40);
	side2->setDeformation(0.1, 1.0, 3.0);
	side2->setRotation('y', 90);

	back = new tcube();
	back->setTexture(wood);
	back->setParent(bottom);
	back->setPosition(2.9, 1.1, 0.0);
	back->setDeformation(0.1, 1.0, 1.5);

	pole1 = new wheel(200);
	pole1->setTexture(wood);
	pole1->setParent(bottom);
	pole1->setPosition(-4.4, 0.0, 1.4);
	pole1->setDeformation(0.1, 1.5, 0.1);
	pole1->setRotation('z', 90);

	pole2 = new wheel(200);
	pole2->setTexture(wood);
	pole2->setParent(bottom);
	pole2->setPosition(-4.4, 0.0, -1.4);
	pole2->setDeformation(0.1, 1.5, 0.1);
	pole2->setRotation('z', 90);

	wheel1 = new torus(200, 10, 1.0, 0.1);
	wheel1->setParent(side1);
	wheel1->setPosition(-0.2, -1.0, 0.0);
	wheel1->setRotation('z', 90);
	wheel1->setColour(0.1, 0.6, 0.9);

	wheel2 = new torus(200, 10, 1.0, 0.1);
	wheel2->setParent(side2);
	wheel2->setPosition(0.2, -1.0, 0.0);
	wheel2->setRotation('z', 90);
	wheel2->setColour(0.1, 0.0, 0.9);

	//Passenger
	passenger = new doll();
	passenger->setParent(bottom);
	passenger->setScale(0.5);
	passenger->setPosition(0.0, 1.5, 0.0);
	passenger->setRotation('y', 90);

	//wings
	wing1 = new extrusion("star.txt", "path.txt");
	wing1->setRotation('x', -50,'y',-10);
	wing1->setPosition(2, 1, 2);
	wing1->setScale(0.4);
	wing1->setParent(bottom);

	wing2= new extrusion("star.txt", "path.txt");
	wing2->setRotation('x', -220, 'z',180,'y', 10);
	wing2->setPosition(2, 1, -2);
	wing2->setScale(0.4);
	wing2->setParent(bottom);
	wing2->setColour(0.6,0.8,0.3);

	/*follower = new sweep("jar.txt",200);
	follower->setScale(0.5);
	follower->setParent(bottom);
	follower->setColour(0.2,0.9,0);
	follower->setPosition(-4.8,0,0);
	follower->setScale(0.3);*/

	// put the shape onto the shapeVector so it gets draw messages
	gShapeVector.push_back(this);
}

void cart::hide()
{
	side1->hide();
	side2->hide();
	bottom->hide();
	back->hide();
	pole1->hide();
	pole2->hide();
	wheel1->hide();
	wheel2->hide();
	passenger->hide();
	wing1->hide();
	wing2->hide();
	//follower->hide();
}

void cart::show()
{
	side1->show();
	side2->show();
	bottom->show();
	back->show();
	pole1->show();
	pole2->show();
	wheel1->show();
	wheel2->show();
	passenger->show();
	wing1->show();
	wing2->show();
	//follower->show();
}

void cart::animate(float time, float positionx, float positionz) {
	this->setPosition(positionx + (2 * 3.14 * 0.5 * 360/360 * +time), -2, positionz);
	wheel1->setRotation('z', 90, 'x', +time * 90);
	wheel2->setRotation('z', 90, 'x', +time * 90);
	wing1->setRotation('z', +time * 90);
	wing2->setRotation('x', 180, 'z', +time * 90);
	//follower->setPosition(-4, sin_d(time * 180),0.0);
	passenger->animate(time);
	if (positionz <= 0) {
		this->setRotation('y', 180);
	}
}