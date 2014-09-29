//
//  DepthFirstSearch.cpp
//  CircleMandala
//
//  Created by Gonzalez, Mario on 9/21/14.
//
//

#include "DepthFirstSearch.h"
#include "Action.h"
#include "GridDirections.h"
#include <Array>
#include <iterator>

namespace search {
    void DepthFirstSearch::advance( State* currentNode, Grid* gridModel, Sequence* sequence ) {
        std::array<Action, 6> frontier = {
            Action(currentNode->gridPoint, DIRECTION::NORTH_WEST),
            Action(currentNode->gridPoint, DIRECTION::NORTH),
            Action(currentNode->gridPoint, DIRECTION::NORTH_EAST),
            Action(currentNode->gridPoint, DIRECTION::SOUTH_EAST),
            Action(currentNode->gridPoint, DIRECTION::SOUTH),
            Action(currentNode->gridPoint, DIRECTION::SOUTH_WEST)
        };
        
        bool hasValidState = false;
        // Pic the first action from above that is valid
        for(auto& anAction : frontier) {
            State* aState = anAction.execute(currentNode, gridModel);
            if( aState->gridPoint == NULL ) continue;
            if( sequence->containsState( aState ) ) continue;
            if( !aState->gridPoint->hasStartPetalFacingDirection( anAction.direction ) ) continue;
            
            hasValidState = true;
            sequence->pushState( aState );
            
            break;
        }
        
        if( !hasValidState ) {
            currentNode = sequence->popState();
            sequence->insertAtHead( currentNode );
        }
    }
}