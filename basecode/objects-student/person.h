// *****************************************************************************************
// KXC354 - Computer Graphics & Animation - 2014
// Assignment 1 & 2
// 3D Engine Code
// *****************************************************************************************
//
// Author: Tony Gray
//
// person.h
//
// This file declares the class for person objects, based on the
// generic 3D object


#ifndef _person_H
#define _person_H



// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "face.h"
#include "object3d.h"
#include "person.h"
#include "sphere.h"
#include "cube.h"



// -----------------------------------------------------------------------------------------
// class declaration
// -----------------------------------------------------------------------------------------

class person : public object3d
{
	public:
		person();
		virtual void show();
		virtual void hide();
		void animate(float time, float positionx, float positionz);

	private:
		sphere *head, * rightsShoulder, * leftShoulder;
		cube *rightArm, *leftArm, * body, * leftLeg, * rightLeg;

};


#endif // _person_H

