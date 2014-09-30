//
//  Agent.cpp
//  CircleMandala
//
//  Created by Gonzalez, Mario on 9/20/14.
//
//

#include "Agent.h"
#include "DepthFirstSearch.h"
#include "GraphSearch.h"

namespace search {
    Agent::Agent( State* anInitialState, State* aGoal, Grid* grid ) {
        _initialState = anInitialState;
        _goal = aGoal;
        _worldState = grid;

        _sequence = new Sequence();
        _sequence->pushState( _initialState );
        
        _sequence->goal = aGoal;
        searchStrategy = new GraphSearch();
        searchStrategy->_frontier->goal = aGoal;
    }
    
    void Agent::advance() {
        // Move to whatever the current node is, and check if we're at the goal
        State* currentNode = _sequence->getLastState();
        if( isAtGoal() ) {
            return;
        }
        
        searchStrategy->advance(currentNode, _worldState, _sequence);
//        searchStrategy->_frontier->sort();
//        _sequence->sort();
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
        
        _goal = aGoal;
        
        _sequence = new Sequence();
        _sequence->pushState( _initialState );
        _sequence->goal = aGoal;
        
        searchStrategy->clear();
        searchStrategy->_frontier->goal = aGoal;
    }
    
    bool Agent::isAtGoal(){
        int distA = (_sequence->getLastState()->gridPoint->gridPosition - _goal->gridPoint->gridPosition).lengthSquared();
        std::cout << "Distance:" << distA << std::endl;
        
//        return distA <= 1;
        
        return _goal->isEqual( *_sequence->getLastState() );
    }
}