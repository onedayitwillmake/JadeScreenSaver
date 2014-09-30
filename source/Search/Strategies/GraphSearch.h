//
//  GraphSearch.h
//  CircleMandala
//
//  Created by Gonzalez, Mario on 9/30/14.
//
//

#ifndef __CircleMandala__GraphSearch__
#define __CircleMandala__GraphSearch__

#include "State.h"
#include "Grid.h"
#include "Sequence.h"

namespace search {
    class GraphSearch {
    public:
        GraphSearch();
        ~GraphSearch(){}
        
        void advance( State* currentNode, Grid* gridModel, Sequence* sequence );
        void clear() { _frontier->clear();}
        
        Sequence* _frontier;
    };
}

#endif /* defined(__CircleMandala__GraphSearch__) */
