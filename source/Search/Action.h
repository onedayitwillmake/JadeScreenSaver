//
//  Action.h
//  CircleMandala
//
//  Created by Gonzalez, Mario on 9/20/14.
//
//

#ifndef __CircleMandala__Action__
#define __CircleMandala__Action__

#include <iostream>
#include "../GridDirections.h"

class GridPoint;
class Grid;

namespace search {
    class State;
    
    class Action {
    public:
        Action( GridPoint* aStart, GRID_DIRECTION aDirection ):direction(aDirection), start(aStart){ };
        
        GRID_DIRECTION direction;
        GridPoint* start;
        
        State* execute( State* state, Grid* grid );
    private:
    };
}
#endif /* defined(__CircleMandala__Action__) */
