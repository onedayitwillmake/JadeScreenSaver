//
//  State.cpp
//  CircleMandala
//
//  Created by Gonzalez, Mario on 9/20/14.
//
//

#include "State.h"
#include "../Grid.h"
#include "../GridPoint.h"
namespace search {
    bool State::isEqual( State &other ) {
        return other.gridPoint == gridPoint;
    }
}