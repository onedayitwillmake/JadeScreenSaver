//
//  Sequence.h
//  CircleMandala
//
//  Created by Gonzalez, Mario on 9/20/14.
//
//

#ifndef __CircleMandala__Sequence__
#define __CircleMandala__Sequence__

#include <iostream>
#include <vector>

namespace search {
    class State;
    
    class Sequence {
    public:
        Sequence();
        ~Sequence();
        
        bool containsState( State* stateToCompare );
        void sort();
        void clear();
        
        void    pushState( State* aState );
        void    insertAtHead( State* aState );
        State*  popState();
        State*  getLastState();
        
        State*  goal;
        std::vector<State*> _states;
    };
}
#endif /* defined(__CircleMandala__Sequence__) */
