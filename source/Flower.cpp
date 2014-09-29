//
//  Flower.cpp
//  CircleMandala
//
//  Created by Gonzalez, Mario on 4/14/14.
//
//

#include "Flower.h"
#include "cinder/cairo/Cairo.h"
#include "cinder/ip/Fill.h"
#include "cinder/Rand.h"
#include "cinder/Utilities.h"
#include "cinder/Color.h"
#include "cinder/Vector.h"
#include "cinder/CinderMath.h"

using namespace ci;
ci::Vec2f Flower::makePath( cairo::Context &ctx ) const {
    Vec2f endPoint = Vec2f::zero();
    
    for( int petal = 0; petal != mNumPetals; petal++ ) {
        
        float petalAngle = ( petal / (float)mNumPetals ) * 2 * M_PI + toRadians(90.0f);
        std::cerr << "Angle:" << ci::toDegrees(petalAngle) << " Petal:" << petal << std::endl;
        
        // Skip this one
        if( petal == mPetalToSkip ) {
            endPoint = getEndPoint( petalAngle );
            continue;
        }
        
        Vec2f insideCircleCenter = mLoc;
        ctx.newSubPath();
        for( int i = 0; i < 2; i++){
            int sign = i == 0 ? -1 : 1;
            float out = 20.0f;
            ctx.moveTo(insideCircleCenter);
            Vec2f c1 = mLoc + Vec2f::xAxis() * cos( petalAngle + toRadians(out) * sign ) * mRadius*0.5f + Vec2f::yAxis() * sin( petalAngle + toRadians(out)  * sign ) * mRadius*0.5f;
            Vec2f c2 = mLoc + Vec2f::xAxis() * cos( petalAngle + toRadians(out) * sign) * mRadius*0.75f + Vec2f::yAxis() * sin( petalAngle + toRadians(out)  * sign ) * mRadius*0.75f;
            Vec2f c3 = getEndPoint( petalAngle );
            ctx.curveTo(c1, c2, c3);
        }
    }
    
    return endPoint;
}

Vec2f Flower::getEndPoint( float petalAngle ) const {
    return mLoc + Vec2f::xAxis() * cos( petalAngle ) * mRadius + Vec2f::yAxis() * sin( petalAngle ) * mRadius;
}

Vec2f Flower::draw( cairo::Context &ctx ) const {
    
    // draw the petal outlines
    ctx.setSource( mColor );
    Vec2f endPoint = makePath( ctx );
    ctx.stroke();

    return endPoint;
}
