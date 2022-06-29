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


#ifndef _buildings_H
#define _buildings_H



// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "face.h"
#include "object3d.h"
#include"tcube.h"



// -----------------------------------------------------------------------------------------
// class declaration
// -----------------------------------------------------------------------------------------

class buildings : public object3d
{
	public:
						buildings();
						virtual void hide(); //overriding
						virtual void show(); //overriding

private:
	tcube* body,* window1, *window2, *window3, *window4, * window5, * window6, *door;
	texture* concrete, * wood, * glass;
};


#endif // _CUBE_H

