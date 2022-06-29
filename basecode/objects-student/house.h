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


#ifndef _house_H
#define _house_H



// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "face.h"
#include "object3d.h"
#include"tcube.h"




// -----------------------------------------------------------------------------------------
// class declaration
// -----------------------------------------------------------------------------------------

class house : public object3d
{
	public:
						house();
						virtual void hide(); //overriding
						virtual void show(); //overriding
private:
	tcube* body, * window1, * window2, * door;
	tcube* roof1, * roof2;
	texture* concrete, * glass, * tiles,*wood;
};


#endif // _CUBE_H

