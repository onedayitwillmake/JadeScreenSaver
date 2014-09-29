//
//  GridPoint.cpp
//  CircleMandala
//
//  Created by Gonzalez, Mario on 8/24/14.
//
//

#include "GridPoint.h"
#include "Petal.h"

void GridPoint::addEndPetal( DIRECTION direction, Petal* petal ) {
    ends[direction] = petal;
}

void GridPoint::addStartPetal(DIRECTION direction, Petal* petal) {
    starts[direction] = petal;
}

bool GridPoint::hasStartPetalFacingDirection(DIRECTION aDirection) {
    return starts.count( aDirection ) > 0;
}

bool GridPoint::hasEndPetalFacingDirection(DIRECTION aDirection) {
    return ends.count( aDirection ) > 0;
}