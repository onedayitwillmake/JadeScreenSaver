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

class GridPoint;
class Grid;

namespace search {
    class State {
    public:
        State( GridPoint* aGridPoint, Grid* aGrid):gridPoint(aGridPoint), grid(aGrid) {}
        
        GridPoint*  gridPoint;
        Grid*       grid;
        
        BOOL        operator==( const State &other ) const;
        BOOL        operator!=( const State &other ) const;
    };
}
#endif /* defined(__CircleMandala__State__) */
