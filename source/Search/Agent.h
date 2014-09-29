//
//  Agent.h
//  CircleMandala
//
//  Created by Gonzalez, Mario on 9/20/14.
//
//

#ifndef __CircleMandala__Agent__
#define __CircleMandala__Agent__

#include <iostream>
#include "Sequence.h"
#include "Goal.h"
#include "Action.h"
#include "Result.h"
#include "State.h"
#include "Grid.h"

namespace search {
    class Agent {
    public:
        Agent();
        
        void Advance();
        
    private:
        Sequence*   _sequence;
        Grid*       _worldState;
        State*      _initialState;
        State*      _goal;
    };
}
#endif /* defined(__CircleMandala__Agent__) */
