/*
 * Leaf.cpp
 *
 *  Created on: Sep 7, 2014
 *      Author: mgonzalez
 */


#include "Petal.h"
#include "cinder/cairo/Cairo.h"
#include "cinder/ip/Fill.h"
#include "cinder/Rand.h"
#include "cinder/Utilities.h"
#include "cinder/Color.h"
#include "cinder/Vector.h"
#include "cinder/CinderMath.h"
#include "GridPoint.h"
#include "Constants.h"

float mRadius = 50.0f;

Petal::Petal( GridPoint* startPoint, GridPoint* endPoint, GRID_DIRECTION direction, ci::ColorA color ) {
	m_endPoint = endPoint;
	m_startPoint = startPoint;
	m_direction = direction;
	m_color = color;

	fadeSpeed = ci::Rand::randFloat(0.98f, 0.995f);

}

Petal::~Petal() {
	// TODO Auto-generated destructor stub
}

void Petal::destroy() {
    m_endPoint = NULL;
    m_startPoint = NULL;
}
void Petal::makePath( ci::cairo::Context &ctx ) {
	using namespace Constants::Petal;

	ci::Vec2f start = m_startPoint->pixelPosition;
	ci::Vec2f end = m_endPoint->pixelPosition;;
	ci::Vec2f delta = (m_endPoint->pixelPosition-m_startPoint->pixelPosition) * 0.5f;
	ci::Vec2f center = start+delta;

	float deltaRadius = start.distance( m_endPoint->pixelPosition );


	float petalAngle = ci::math<float>::atan2(start.y - m_endPoint->pixelPosition.y, start.x - m_endPoint->pixelPosition.x );

//    std::cout << "Petal\t" << "Angle: " << ci::toDegrees(petalAngle) << " Petal: " << (int)m_direction << std::endl;


	ctx.newSubPath();
	static float out = 90.0f;
	for( int i = 0; i < 2; i++){
		int sign = i == 0 ? -1 : 1;
		ctx.moveTo(start);
		ci::Vec2f c1Center = start.lerp( C1_LERP_FACTOR, end);
		m_c1 = ci::Vec2f(
					(c1Center.x) + ci::math<float>::cos( petalAngle + ci::toRadians(out) * sign ) * deltaRadius * C1_RADIUS_SCALE,
					(c1Center.y) + ci::math<float>::sin( petalAngle + ci::toRadians(out) * sign ) * deltaRadius * C1_RADIUS_SCALE
				);

		ci::Vec2f c2Center = start.lerp( C2_LERP_FACTOR, end);
		m_c2 = ci::Vec2f(
					(c2Center.x) + ci::math<float>::cos( petalAngle + ci::toRadians(out) * sign ) * deltaRadius * C2_RADIUS_SCALE,
					(c2Center.y) + ci::math<float>::sin( petalAngle + ci::toRadians(out) * sign ) * deltaRadius * C2_RADIUS_SCALE
				);
		m_c3 = m_endPoint->pixelPosition; //getEndPoint( petalAngle );

//		m_c1 = start;
//		m_c2 = start + delta;

		ctx.curveTo(m_c1, m_c2, m_c3);
	}
}

void Petal::draw( ci::cairo::Context &ctx ) {
//	m_color.a *= fadeSpeed;

	ctx.setSource( m_color );
	makePath( ctx );
	ctx.stroke();

	ci::Vec2f start = m_startPoint->pixelPosition;
		ci::Vec2f delta = (m_endPoint->pixelPosition-m_startPoint->pixelPosition) * 0.5f;
		ci::Vec2f center = start+delta;

	ctx.newPath();
	ctx.setSource( m_color * 0.5f );
	ctx.circle( m_startPoint->pixelPosition, 1.0f );
	ctx.circle( m_c1, 1.0f );
	ctx.circle( center, 1.0f );
	ctx.circle( m_c2, 1.0f );
	ctx.circle( m_endPoint->pixelPosition, 1.0f );
	ctx.fill();

}
ci::Vec2f Petal::getEndPoint( float petalAngle ) {
    return m_startPoint->pixelPosition + ci::Vec2f::xAxis() * cos( petalAngle ) * mRadius + ci::Vec2f::yAxis() * sin( petalAngle ) * mRadius;
}

float Petal::getAngle() {

    return ( (float)m_direction / ((float)GRID_DIRECTION::SOUTH_WEST+1) ) * 2 * M_PI + ci::toRadians(90.0f);
}



