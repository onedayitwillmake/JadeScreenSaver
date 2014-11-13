/*
 * Leaf.h
 *
 *  Created on: Sep 7, 2014
 *      Author: mgonzalez
 */

#ifndef LEAF_H_
#define LEAF_H_

#include "cinder/Color.h"
#include "cinder/Vector.h"
#include "cinder/cairo/Cairo.h"
#include "GridDirections.h"
#include "cinder/Timeline.h"

class GridPoint;
class Grid;

class Petal {
public:
	Petal( GridPoint* startPoint, GridPoint* endPoint, GRID_DIRECTION direction, ci::ColorA color );
	virtual ~Petal();

    void            destroy();
	void			makePath( cinder::cairo::Context &ctx );
	void			draw( cinder::cairo::Context &ctx );
	cinder::Vec2f	getEndPoint( float petalAngle );
	float			getAngle();
    ci::ColorA      getColor() { return m_color; };
    
	float 			fadeSpeed;
    float           lerpLocation;
    bool            hasTween;
private:
	GridPoint*	m_startPoint;
	GridPoint*	m_endPoint;
	GRID_DIRECTION	m_direction;
    ci::ColorA  m_color;

	// Caching
	ci::Vec2f	m_c1;
	ci::Vec2f	m_c2;
	ci::Vec2f	m_c3;
};

#endif /* LEAF_H_ */
