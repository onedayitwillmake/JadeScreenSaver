//
//  GridPoint.cpp
//  CircleMandala
//
//  Created by Gonzalez, Mario on 8/24/14.
//
//

#include "GridPoint.h"
#include "Petal.h"
#include "cinder/Rand.h"

GridPoint::GridPoint(ci::Vec2i aGridPosition, ci::Vec2f aPixelPosition ):gridPosition( aGridPosition ), pixelPosition( aPixelPosition ), isBeingUsed( false ) {
    _isPermeable = ci::randFloat() < 0.75f;
}
void GridPoint::addEndPetal( GRID_DIRECTION direction, Petal* petal ) {
    ends[direction] = petal;
}

void GridPoint::addStartPetal(GRID_DIRECTION direction, Petal* petal) {
    starts[direction] = petal;
}

bool GridPoint::hasStartPetalFacingDirection(GRID_DIRECTION aDirection) {
    return starts.count( aDirection ) > 0;
}

bool GridPoint::hasEndPetalFacingDirection(GRID_DIRECTION aDirection) {
    return ends.count( aDirection ) > 0;
}

bool GridPoint::isPermeable() {
    return _isPermeable;
}