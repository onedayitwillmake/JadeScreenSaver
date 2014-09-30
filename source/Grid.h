//
//  Grid.h
//  CircleMandala
//
//  Created by Gonzalez, Mario on 8/24/14.
//
//

#ifndef __CircleMandala__Grid__
#define __CircleMandala__Grid__

#include <iostream>
#include <map>
#include "cinder/Vector.h"
#include "GridPoint.h"
#include "GridDirections.h"

class Grid {
public:
    Grid( ci::Vec2i dimensions_, ci::Vec2i spacing_ );

    void createGrid();

    GridPoint* getGridPointAt(int x, int y);
    GridPoint* getGridPointNeighbor( GridPoint* point, GRID_DIRECTION offset );
    GridPoint* getCenterGridPoint();
    
    int getColumnCount() const { return dimensions.x / spacing.x + 1; }
    int getRowCount() const { return dimensions.y / spacing.y + 1; }

    ci::Vec2i getDirectionalOffset( GRID_DIRECTION cardinalDirection );
private:
    ci::Vec2i dimensions;
    ci::Vec2i spacing;
    std::map< std::pair<int, int>, GridPoint* > _points;
};
#endif /* defined(__CircleMandala__Grid__) */
