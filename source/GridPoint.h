//
//  GridPoint.h
//  CircleMandala
//
//  Created by Gonzalez, Mario on 8/24/14.
//
//

#ifndef __CircleMandala__GridPoint__
#define __CircleMandala__GridPoint__

#include <iostream>
#include "cinder/Vector.h"
#include "GridDirections.h"

class Petal;
class GridPoint {
public:
    GridPoint( ci::Vec2i aGridPosition, ci::Vec2f aPixelPosition ):
    gridPosition( aGridPosition ), pixelPosition( aPixelPosition ), isBeingUsed( false ) {}
    
    // Properties
    bool        isBeingUsed;
    ci::Vec2i   gridPosition;
    ci::Vec2f   pixelPosition;
    
    
    void    addStartPetal(  DIRECTION direction, Petal* petal );
    bool    hasStartPetalFacingDirection(DIRECTION aDirection);
    
    void    addEndPetal(  DIRECTION direction, Petal* petal );
    bool    hasEndPetalFacingDirection(DIRECTION aDirection);
private:
    std::map<DIRECTION, Petal*> starts;
    std::map<DIRECTION, Petal*> ends;
};
#endif /* defined(__CircleMandala__GridPoint__) */
