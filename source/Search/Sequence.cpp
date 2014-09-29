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
        for (auto& aState : _stateSequences ) {
            if( aState == stateToCompare ) {
                return true;
            }
        }
        
        return false;
    }
    
    void Sequence::sort() {
        std::sort( _stateSequences.begin(), _stateSequences.end(), manhattan_distance );
    }
    
    void Sequence::clear() {
        _stateSequences.clear();
    }
    
    
    void Sequence::pushState( State* aState ) {
        _stateSequences.push_back( aState );
    }
    
    void Sequence::insertAtHead( State* aState ) {
        _stateSequences.insert( _stateSequences.begin(), aState );
    }
    
    State*  Sequence::popState() {
        if( _stateSequences.empty() ) {
            return NULL;
        }
        
        State* lastElement = _stateSequences.back();
        _stateSequences.pop_back();
        
        return lastElement;
    }
    
    State* Sequence::getLastState() {
        if( _stateSequences.empty() ) {
            return NULL;
        }
        
        return _stateSequences.back();
    }
    
}