/*
 * Constants.cpp
 *
 *  Created on: Sep 7, 2014
 *      Author: mgonzalez
 */

#include "Constants.h"
using namespace Constants;
namespace Constants {
	namespace Petal {
		float C1_LERP_FACTOR;
		float C2_LERP_FACTOR;

		float C2_RADIUS_SCALE;
		float C1_RADIUS_SCALE;
	};

	void init() {
		Petal::C1_LERP_FACTOR = 0.1f;
		Petal::C2_LERP_FACTOR = 0.75f;

		Petal::C1_RADIUS_SCALE = 0.3f;
		Petal::C2_RADIUS_SCALE = 0.25f;
	}
}
