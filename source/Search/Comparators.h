//
//  Comparators.h
//  CircleMandala
//
//  Created by Gonzalez, Mario on 9/21/14.
//
//

#ifndef CircleMandala_Comparators_h
#define CircleMandala_Comparators_h

#include "State.h"
#include "Grid.h"
#include "GridPoint.h"

namespace search {
//    struct manhattan_distance {
        /*
         public int compare(State stateA, State stateB) {
         PVector subA = PVector.sub( stateA.getSquare()._center, _goal._center );
         float distASq = subA.dot( subA );
         
         PVector subB = PVector.sub( stateB.getSquare()._center, _goal._center );
         float distBSq = subB.dot( subB );
         
         
         if( distASq < distBSq ) return 1;
         else if ( distBSq < distBSq ) return -1;
         return 0;
         }
         */
        // TODO - SET GOAL SQUARE TO RANDOM UNUSED SQUARE ACCORDING TO GRID
        bool manhattan_distance(const State* stateA, const State* stateB) {
            return stateA->gridPoint->gridPosition.x < stateB->gridPoint->gridPosition.x;
        }
}
#endif
