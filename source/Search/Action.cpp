//
//  Action.cpp
//  CircleMandala
//
//  Created by Gonzalez, Mario on 9/20/14.
//
//

#include "Action.h"
#include "State.h"
#include "Grid.h"

namespace search {
    State* Action::execute( State* state, Grid* grid ) {
        /*
         int column = (int)initialState.getSquare()._gridPosition.x + directionX;
         int row = (int)initialState.getSquare()._gridPosition.y + directionY;
         return new State( worldState.getSquareAtGridPosition(column, row), worldState);
         */
        return new State( grid->getGridPointNeighbor( start, direction ), grid );
    }
}