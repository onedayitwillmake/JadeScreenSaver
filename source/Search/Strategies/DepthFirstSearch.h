//
//  DepthFirstSearch.h
//  CircleMandala
//
//  Created by Gonzalez, Mario on 9/21/14.
//
//

#ifndef __CircleMandala__DepthFirstSearch__
#define __CircleMandala__DepthFirstSearch__

#include <iostream>
#include "State.h"
#include "Grid.h"
#include "Sequence.h"

namespace search {
    class DepthFirstSearch {
    public:
        DepthFirstSearch(){
            frontier = new Sequence();
        }
        ~DepthFirstSearch(){}
        
        void advance( State* currentNode, Grid* gridModel, Sequence* sequence );
        void clear() { frontier->clear(); }
        
        Sequence* frontier;
    };
}
#endif /* defined(__CircleMandala__DepthFirstSearch__) */
