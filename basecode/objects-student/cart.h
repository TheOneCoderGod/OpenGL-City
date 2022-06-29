// *****************************************************************************************
// KXC354 - Computer Graphics & Animation - 2014
// Assignment 1 & 2
// 3D Engine Code
// *****************************************************************************************
//
// Author: Tony Gray
//
// cart.h
//
// This file declares the class for cart objects, based on the
// generic 3D object


#ifndef _cart_H
#define _cart_H



// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "face.h"
#include "object3d.h"
#include "texture.h"
#include "tcube.h"
#include "wheel.h"
#include "torus.h"
#include "doll.h"


// -----------------------------------------------------------------------------------------
// class declaration
// -----------------------------------------------------------------------------------------

class cart : public object3d
{
	private:
		tcube		*side1, *side2, *bottom, *back;
		wheel		*pole1, *pole2;
		torus		*wheel1, *wheel2;
		texture		*wood;
		doll        *passenger;
		extrusion   *wing1, *wing2;
		//sweep       *follower;
	public:
		cart();
		virtual void hide(); //overriding
		virtual void show(); //overriding
		void animate(float time, float positionx, float positionz);
		
};


#endif // _cart_H
