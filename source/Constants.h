/*
 * Constants.h
 *
 *  Created on: Sep 25, 2011
 *      Author: onedayitwillmake
 */
#pragma once
#ifndef CONSTANTS_H_
#define CONSTANTS_H_
#include "cinder/Perlin.h"
#include "cinder/Vector.h"

namespace Constants {
	struct Instances {
		static ci::Perlin* PERLIN_NOISE() {
			static ci::Perlin noise = ci::Perlin(4,2);
			return &noise;
		}
	};

	namespace Petal {
		extern float C1_LERP_FACTOR;
		extern float C2_LERP_FACTOR;

		extern float C2_RADIUS_SCALE;
		extern float C1_RADIUS_SCALE;
	};
	void init();
}
#endif /* CONSTANTS_H_ */
