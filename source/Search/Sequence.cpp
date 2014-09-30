//
//  Sequence.cpp
//  CircleMandala
//
//  Created by Gonzalez, Mario on 9/20/14.
//
//

#include "Sequence.h"
#include "State.h"
#include "Comparators.h"

namespace search {
    Sequence::Sequence(){
    }
    
    Sequence::~Sequence(){
        clear();
    }
    
    bool Sequence::containsState( State* stateToCompare ) {
        for (auto& aState : _states ) {
            if( aState->isEqual(*stateToCompare) ) {
                return true;
            }
        }
        
        return false;
    }
    
    void Sequence::sort() {

        std::sort(_states.begin(), _states.end(), [&]( const State* stateA, const State* stateB) {
            int distA = (stateA->gridPoint->gridPosition - goal->gridPoint->gridPosition).lengthSquared();
            int distB = (stateB->gridPoint->gridPosition - goal->gridPoint->gridPosition).lengthSquared();
            return distA > distB;
        });
    }
    
    void Sequence::clear() {
        _states.clear();
    }
    
    
    void Sequence::pushState( State* aState ) {
        _states.push_back( aState );
    }
    
    void Sequence::insertAtHead( State* aState ) {
        _states.insert( _states.begin(), aState );
    }
    
    State*  Sequence::popState() {
        if( _states.empty() ) {
            return NULL;
        }
        
        State* lastElement = _states.back();
        _states.pop_back();
        
        return lastElement;
    }
    
    State* Sequence::getLastState() {
        if( _states.empty() ) {
            return NULL;
        }
        
        return _states.back();
    }
    
}