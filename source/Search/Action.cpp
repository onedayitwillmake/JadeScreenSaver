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
        return new State( grid->getGridPointNeighbor( start, direction ), grid );
    }
}