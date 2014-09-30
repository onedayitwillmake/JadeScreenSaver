//
//  Grid.cpp
//  CircleMandala
//
//  Created by Gonzalez, Mario on 8/24/14.
//
//

#include "Grid.h"
#include <utility>
#include <map>

Grid::Grid( ci::Vec2i dimensions_, ci::Vec2i spacing_ ) {
    dimensions = dimensions_;
    spacing = spacing_;
    createGrid();
};

void Grid::createGrid(){
    _points.clear();
    
    int columnCount = getColumnCount();
    int rowCount = getRowCount();
    
    for (int x = 0; x < columnCount; x++) {
        for( int y = 0; y < rowCount; y++ ) {
            float xpos = x * spacing.x;
            float ypos = y * spacing.y;
            
            auto gridPos = std::make_pair(x, y);
            GridPoint* gridPoint = new GridPoint( ci::Vec2i(x,y), ci::Vec2f(xpos, ypos) );
            _points.insert( std::make_pair(gridPos, gridPoint) );
        }
    }
}

GridPoint* Grid::getGridPointNeighbor( GridPoint* point, GRID_DIRECTION offset ) {
	ci::Vec2i pos = point->gridPosition;
	pos += getDirectionalOffset( offset );
//	std::cout << point->gridPosition << " vs " << pos << std::endl;

	return getGridPointAt(pos.x, pos.y);
}

GridPoint* Grid::getGridPointAt(int x, int y) {
    if( x < 0 || x >= getColumnCount () ) return NULL;
    if( y < 0 || y >= getRowCount() ) return NULL;
    
    auto gridPos = std::make_pair(x, y);
    auto result = _points.find( gridPos );
    
    if( result != _points.end() ) {
        return result->second;
    }
    
    return NULL;
}

ci::Vec2i Grid::getDirectionalOffset( GRID_DIRECTION cardinalDirection ) {
	ci::Vec2i offset = ci::Vec2i::zero();

	switch (cardinalDirection) {
		case GRID_DIRECTION::NORTH:         offset = ci::Vec2i( 0, -2); break;
		case GRID_DIRECTION::NORTH_EAST:    offset = ci::Vec2i( 1, -1); break;
		case GRID_DIRECTION::SOUTH_EAST:	offset = ci::Vec2i( 1, 1); break;
		case GRID_DIRECTION::SOUTH:         offset = ci::Vec2i( 0, 2); break;
        case GRID_DIRECTION::EAST:          offset = ci::Vec2i( 1, 0); break;
        case GRID_DIRECTION::WEST:          offset = ci::Vec2i( -1, 0); break;
		case GRID_DIRECTION::SOUTH_WEST:	offset = ci::Vec2i(-1, 1); break;
		case GRID_DIRECTION::NORTH_WEST:    offset = ci::Vec2i(-1, -1); break;
		default:
			break;
	}

	return offset;
}

GridPoint* Grid::getCenterGridPoint() {
    return getGridPointAt( getColumnCount()/2, getRowCount()/2 );
    
}
