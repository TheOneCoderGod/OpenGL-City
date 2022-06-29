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
#include "city.h"
//#include"trees.h"
#include"house.h"
#include"buildings.h"
#include "utility.h"



// -----------------------------------------------------------------------------------------
// globals
// -----------------------------------------------------------------------------------------
extern vector<object3d*> gShapeVector;



// -----------------------------------------------------------------------------------------
// constructor
// -----------------------------------------------------------------------------------------

city::city()
{
	// Initialise the object's state
	setName("City");

	//House front
	house1 = new house();
	house1->setPosition(-220, 0, -60);

	house2 = new house();
	house2->setPosition(40, 0, -60);

	house3 = new house();
	house3->setPosition(-20, 0, -60);

	house4 = new house();
	house4->setPosition(200, 0, -60);

	//Buildings front

	building1 = new buildings();
	building1->setScale(3);
	building1->setPosition(-290, 5, -60);

	building2 = new buildings();
	building2->setScale(3);
	building2->setPosition(-140, 5, -60);

	building3 = new buildings();
	building3->setScale(3);
	building3->setPosition(-100, 5, -60);

	building4 = new buildings();
	building4->setScale(3);
	building4->setPosition(120, 5, -60);


	//Houses Back
	house5 = new house();
	house5->setPosition(-290, 0, 90);
	house5->setRotation('y', 180);

	house6 = new house();
	house6->setPosition(-150, 0, 90);
	house6->setRotation('y', 180);

	house7 = new house();
	house7->setPosition(-90, 0, 90);
	house7->setRotation('y', 180);

	house8 = new house();
	house8->setPosition(120, 0, 90);
	house8->setRotation('y', 180);

	//Buildings back first building is the one that has the biggest x negative value
	building5 = new buildings();
	building5->setScale(3);
	building5->setPosition(-220, 5, 90);
	building5->setRotation('y', 180);

	building6 = new buildings();
	building6->setScale(3);
	building6->setPosition(40, 5, 90);
	building6->setRotation('y', 180);

	building7 = new buildings();
	building7->setScale(3);
	building7->setPosition(-20, 5, 90);
	building7->setRotation('y', 180);

	building8 = new buildings();
	building8->setScale(3);
	building8->setPosition(200, 5, 90);
	building8->setRotation('y', 180);


	//Grounds

	asphalt = new texture("street.jpg");
	side = new texture("side.jpg");
	grass = new texture("grass.jpg");

	street= new tcube();
	street->setDeformation(550, 0.1,30);
	street->setTexture(asphalt);
	street->setPosition(0.0, -3.0, 10.0);


	//Sidewalks
	side1 = new tcube(); // the side walk in front
	side1->setDeformation(550, 0.1, 45.0);
	side1->setTexture(side);
	side1->setPosition(0.0, -3.0, -65.0);
	side1->setScale(1);
	//side1->setColour(0.3, 0.5, 0.9);

	side2 = new tcube(); // the side walk in the back
	side2->setDeformation(550, 0.1, 55.0);
	side2->setTexture(side);
	side2->setPosition(0.0, -3.0, 95.0);
	side2->setScale(1);
	side2->setParent(this);
	//side2->setColour(0.3, 0.5, 0.9);

	//prevents the city to look like its flying
	//Note: Make inside faces visible
	background = new tcube();
	background->setTexture(grass);
	//background->setColour(0.13, 0.98, 0.69);
	background->setPosition(0, -54, 0); 
	background->setScale(20);
	background->setDeformation(2500, 2.4, 1500);

	//trees

	//back trees
	tree1 = new trees();
	tree1->setPosition(-60,0,90);
	tree1->setScale(2);

	tree2 = new trees();
	tree2->setPosition(90, 0, 90);

	tree3 = new trees();
	tree3->setPosition(160, 0, 90);
	tree3->setScale(3);

	tree4 = new trees();
	tree4->setPosition(-180, 0, 90);


	tree5 = new trees();
	tree5->setPosition(-260, 0, 90);
	tree5->setScale(3);

	///middle trees
	tree6 = new trees();
	tree6->setPosition(-260, 0, 10);
	tree6->setScale(3);

	tree7 = new trees();
	tree7->setPosition(0, 0, 10);
	tree7->setScale(4);

	tree8= new trees();
	tree8->setPosition(90, 0, 10);

	tree9 = new trees();
	tree9->setPosition(-120, 0, 10);
	tree9->setScale(3.5);

	tree10 = new trees();
	tree10->setPosition(180, 0, 10);
	tree10->setScale(2.5);

	//front threes
	tree11 = new trees();
	tree11->setPosition(-60, 0, -50);

	tree12 = new trees();
	tree12->setPosition(80, 0, -50);
	tree12->setScale(2);
	
	tree13 = new trees();
	tree13->setPosition(160, 0, -50);
	tree13->setScale(1.5);

	tree14 = new trees();
	tree14->setPosition(-185, 0, -50); 
	tree14->setScale(4);

	tree15 = new trees();
	tree15->setPosition(-255, 0, -50);
	tree15->setScale(3);
	
	
	gShapeVector.push_back(this);

}


void city::hide()
{
	house1->hide();
	house2->hide();
	house3->hide();
	house4->hide();
	building1->hide();
	building2->hide();
	building3->hide();
	building4->hide();

	house5->hide();
	house6->hide();
	house7->hide();
	house8->hide();
	building5->hide();
	building6->hide();
	building7->hide();
	building8->hide();

	tree1->hide();
	tree2->hide();
	tree3->hide();
	tree4->hide();
	tree5->hide();
	tree6->hide();
	tree7->hide();
	tree8->hide();
	tree9->hide();
	tree10->hide();
	tree11->hide();
	tree12->hide();
	tree13->hide();
	tree14->hide();
	tree15->hide();

	street->hide();
	side1->hide();
	side2->hide();
	background->hide();

}

void city::show()
{
	house1->show();
	house2->show();
	house3->show();
	house4->show();
	building1->show();
	building2->show();
	building3->show();
	building4->show();

	house5->show();
	house6->show();
	house7->show();
	house8->show();
	building5->show();
	building6->show();
	building7->show();
	building8->show();

	tree1->show();
	tree2->show();
	tree3->show();
	tree4->show();
	tree5->show();
	tree6->show();
	tree7->show();
	tree8->show();
	tree9->show();
	tree10->show();
	tree11->show();
	tree12->show();
	tree13->show();
	tree14->show();
	tree15->show();

	street->show();
	side1->show();
	side2->show();
	background->show();
}




