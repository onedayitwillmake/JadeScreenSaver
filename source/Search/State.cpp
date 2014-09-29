//
//  State.cpp
//  CircleMandala
//
//  Created by Gonzalez, Mario on 9/20/14.
//
//

#include "State.h"
#include "Grid.h"
#include "GridPoint.h"
namespace search {
    BOOL State::operator==( const State &other ) const {
        return other.gridPoint == gridPoint;
    }
    
    BOOL State::operator!=( const State &other ) const {
        return !(*this == other);
    }
}