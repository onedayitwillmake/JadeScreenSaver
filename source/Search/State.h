//
//  State.h
//  CircleMandala
//
//  Created by Gonzalez, Mario on 9/20/14.
//
//

#ifndef __CircleMandala__State__
#define __CircleMandala__State__

#include <iostream>
#include "GridDirections.h"

class GridPoint;
class Grid;

namespace search {
    class State {
    public:
        State( GridPoint* aGridPoint, Grid* aGrid):gridPoint(aGridPoint), grid(aGrid) {}
        
        GridPoint*  gridPoint;
        Grid*       grid;
        GRID_DIRECTION direction;
        
        BOOL        isEqual( State &other );
        BOOL        operator!=( const State &other ) const;
    };
}
#endif /* defined(__CircleMandala__State__) */
