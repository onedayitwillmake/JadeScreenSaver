//
//  Flower.h
//  CircleMandala
//
//  Created by Gonzalez, Mario on 4/14/14.
//
//

#ifndef __CircleMandala__Flower__
#define __CircleMandala__Flower__


#include "Flower.h"
#include "cinder/cairo/Cairo.h"
#include "cinder/ip/Fill.h"
#include "cinder/Rand.h"
#include "cinder/Utilities.h"
#include "cinder/Color.h"
#include "cinder/Vector.h"

using namespace ci;

class Flower {
public:
	Flower( Vec2f loc, float radius, int numPetals, int petalToSkip, ColorA color ):
    mLoc( loc ),
    mRadius( radius ),
    mNumPetals( numPetals ),
    mPetalToSkip( petalToSkip),
    mColor( color ){}
    
    Vec2f   mEndPoint;
    
	Vec2f makePath( cairo::Context &ctx ) const;
	Vec2f draw( cairo::Context &ctx ) const;
    Vec2f getEndPoint( float petalAngle ) const;
	
private:
	Vec2f		mLoc;
	float		mRadius;
    float       mPetalOutsideRadius;
    float       mPetalInsideRadius;
    int         mPetalToSkip;
	int			mNumPetals;
	ColorA		mColor;
};

#endif /* defined(__CircleMandala__Flower__) */
