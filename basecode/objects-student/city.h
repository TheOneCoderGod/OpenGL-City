// *****************************************************************************************
// KXC354 - Computer Graphics & Animation - 2014
// Assignment 1 & 2
// 3D Engine Code
// *****************************************************************************************
//
// Author: Tony Gray
//
// cube.h
//
// This file declares the class for cube objects, based on the
// generic 3D object


#ifndef _CITY_H
#define _CITY_H



// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "face.h"
#include "object3d.h"
#include"cube.h"
#include"house.h"
#include"buildings.h"
#include"tcube.h"
#include"texture.h"
#include"trees.h"





// -----------------------------------------------------------------------------------------
// class declaration
// -----------------------------------------------------------------------------------------

class city : public object3d
{
public:
			city();
			virtual void hide(); //overriding
			virtual void show(); //overriding
private:
	house *house1, *house2, *house3, *house4, * house5, * house6, * house7, * house8;
	trees *tree1, *tree2,* tree3, * tree4, * tree5;
	trees *tree6, * tree7, * tree8, * tree9, * tree10;
	trees * tree11, * tree12, * tree13, * tree14, * tree15;
	buildings * building1, *building2, *building3, * building4,*building5, *building6, * building7, * building8;
	tcube *street, *side1, *side2;
	texture* asphalt, * side, *grass;
	tcube * background;

};


#endif // _CITY_H

