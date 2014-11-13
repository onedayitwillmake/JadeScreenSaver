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
        //C1_LERP_FACTOR:0.523674 C2_LERP_FACTOR:0.352308 C1_RADIUS_SCALE:0.329545 C2_RADIUS_SCALE:0.350769

//		Petal::C1_LERP_FACTOR = 0.1f;
//		Petal::C2_LERP_FACTOR = 0.75f;
//
//		Petal::C1_RADIUS_SCALE = 0.3f;
//		Petal::C2_RADIUS_SCALE = 0.25f;
//        
//    C1_LERP_FACTOR:0.464962 C2_LERP_FACTOR:0.347692 C1_RADIUS_SCALE:0.235795 C2_RADIUS_SCALE:0.378462

        Petal::C1_LERP_FACTOR = 0.464962;
        Petal::C2_LERP_FACTOR = 0.347692;
        
        Petal::C1_RADIUS_SCALE = 0.235795;
        Petal::C2_RADIUS_SCALE = 0.378462;

	}
}
