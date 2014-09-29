//
//  Result.h
//  CircleMandala
//
//  Created by Gonzalez, Mario on 9/20/14.
//
//

#ifndef __CircleMandala__Result__
#define __CircleMandala__Result__

#include <iostream>
class Grid;

namespace search {
    class State;
    class Action;
    
    class Result {
    public:
        Result(State* anInState, Action* anInAction, Grid* aGrid)
        :inState( anInState ), inAction( anInAction ), grid( aGrid ) { }
        
        State* inState;
        Action* inAction;
        Grid*   grid;
        
        State* execute();
    };
}
#endif /* defined(__CircleMandala__Result__) */
