// *****************************************************************************************
// KXC354 - Computer Graphics & Animation - 2014
// Assignment 1 & 2
// 3D Engine Code
// *****************************************************************************************
//
// Author: Tony Gray
//
// doll.h
//
// This file declares the class for letterU objects, based on the
// generic 3D object


#ifndef _doll_H
#define _doll_H



// -----------------------------------------------------------------------------------------
// includes
// -----------------------------------------------------------------------------------------
#include "face.h"
#include "object3d.h"
#include "wheel.h"
#include"sweep.h"
#include"cube.h"
#include"sphere.h"
#include"extrusion.h"
#include"torus.h"





// -----------------------------------------------------------------------------------------
// class declaration
// -----------------------------------------------------------------------------------------

class doll : public object3d
{
private:
	wheel* roda;
	sweep* leftLeg;
	sweep* rightLeg;
	sweep* rightArm;
	sweep* leftArm;
	cube* neck;
	sphere *head,*leftEye,*rightEye, *mouth;
	extrusion* tail;
	torus * hat;
	sphere * hat2;

public:
	doll();
	virtual void hide(void);
	virtual void show(void);
	void animate(float time);

};


#endif // _doll_H

