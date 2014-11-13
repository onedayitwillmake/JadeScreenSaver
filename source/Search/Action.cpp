//
//  Action.cpp
//  CircleMandala
//
//  Created by Gonzalez, Mario on 9/20/14.
//
//

#include "Action.h"
#include "State.h"
#include "../Grid.h"

namespace search {
    State* Action::execute( State* state, Grid* grid ) {
        State* newState = new State( grid->getGridPointNeighbor( start, direction ), grid );
        newState->direction = direction;
        
        return newState;
    }
}