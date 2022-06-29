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


#ifndef _trees_H
#define _trees_H



// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "face.h"
#include "object3d.h"
#include"tcube.h"
#include"tsphere.h"



// -----------------------------------------------------------------------------------------
// class declaration
// -----------------------------------------------------------------------------------------

class trees : public object3d
{
	public:
						trees();
						virtual void hide(); //overriding
						virtual void show(); //overriding
private:
	tcube* body;
	tsphere *leaves;
	texture *tronco ,*folhas;
};


#endif // _CUBE_H

