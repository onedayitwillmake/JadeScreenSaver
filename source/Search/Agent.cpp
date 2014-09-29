//
//  Agent.cpp
//  CircleMandala
//
//  Created by Gonzalez, Mario on 9/20/14.
//
//

#include "Agent.h"
#include "DepthFirstSearch.h"

namespace search {
    Agent::Agent( State* anInitialState, State* aGoal, Grid* grid ) {
        _initialState = anInitialState;
        _goal = aGoal;
        _worldState = grid;

        _sequence = new Sequence();
        _sequence->pushState( _initialState );
        
        searchStrategy = new DepthFirstSearch();
    }
    
    void Agent::advance() {
        // Move to whatever the current node is, and check if we're at the goal
        State* currentNode = _sequence->getLastState();
        if( isAtGoal() ) {
            return;
        }
        
        searchStrategy->advance(currentNode, _worldState, _sequence);
        searchStrategy->frontier->sort();
    }
    
    
    GridPoint* Agent::getCurrentGridPoint() {
        if( _sequence->getLastState() != NULL ) {
            return _sequence->getLastState()->gridPoint;
        }
        
        return NULL;
    }
    
    void Agent::setGoal( State* aGoal ) {
        
        _initialState = _sequence->getLastState();
        
        _sequence->clear();
        delete _sequence;
        
        _sequence = new Sequence();
        _sequence->pushState( _initialState );
        
        _goal = aGoal;
        searchStrategy->clear();
    }
}