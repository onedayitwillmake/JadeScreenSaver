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
#include "DepthFirstSearch.h"
#include "GraphSearch.h"

namespace search {
    class Agent {
    public:
        Agent( State* anInitialState, State* aGoal, Grid* grid );
        
        GridPoint*      getCurrentGridPoint();
        void            advance();
        void            setGoal( State* aGoal );
        bool            isAtGoal();
        
        Sequence*       getSequence() { return _sequence; };
        State*          getInitialState(){ return _initialState; };
        State*          getGoal(){ return _goal; }
        GraphSearch*    getStrategy(){ return searchStrategy; };
    private:
        Sequence*   _sequence;
        Grid*       _worldState;
        State*      _initialState;
        State*      _goal;
        GraphSearch* searchStrategy;
    };
}
#endif /* defined(__CircleMandala__Agent__) */
