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
    GridPoint( ci::Vec2i aGridPosition, ci::Vec2f aPixelPosition );
    // Properties
    bool        isBeingUsed;
    ci::Vec2i   gridPosition;
    ci::Vec2f   pixelPosition;
    
    
    void    addStartPetal(  GRID_DIRECTION direction, Petal* petal );
    bool    hasStartPetalFacingDirection(GRID_DIRECTION aDirection);
    
    void    addEndPetal(  GRID_DIRECTION direction, Petal* petal );
    bool    hasEndPetalFacingDirection(GRID_DIRECTION aDirection);
    
    bool    isPermeable();
private:
    std::map<GRID_DIRECTION, Petal*> starts;
    std::map<GRID_DIRECTION, Petal*> ends;
    bool        _isPermeable;
};
#endif /* defined(__CircleMandala__GridPoint__) */
