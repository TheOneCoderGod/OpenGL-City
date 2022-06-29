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


#ifndef _environmet_H
#define _environmet_H



// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "face.h"
#include "object3d.h"
#include"person.h"
#include"cart.h"




// -----------------------------------------------------------------------------------------
// class declaration
// -----------------------------------------------------------------------------------------

class environmet : public object3d
{
	public:
						environmet();
						virtual void show();
						virtual void hide();
						void animate(float time);
private:
	person* person1, * person2, * person3, * person4, * person5, * person6;
	cart* car1, * car2, * car3, * car4, * car5, * car6;
};


#endif // _CUBE_H

