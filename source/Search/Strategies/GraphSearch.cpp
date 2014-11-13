//
//  GraphSearch.cpp
//  CircleMandala
//
//  Created by Gonzalez, Mario on 9/30/14.
//
//

#include "GraphSearch.h"
#include "../Action.h"
#include "../../GridDirections.h"
#include <array>
#include <iterator>
#include <chrono>       // std::chrono::system_clock
#include <random>       // std::default_random_engine

namespace search {
    GraphSearch::GraphSearch(){
        _frontier = new Sequence();
    }
    
    void GraphSearch::advance( State* currentNode, Grid* gridModel, Sequence* sequence ) {
        std::array<Action, 6> frontierEdges = {
            Action(currentNode->gridPoint, GRID_DIRECTION::NORTH_WEST),
            Action(currentNode->gridPoint, GRID_DIRECTION::NORTH),
            Action(currentNode->gridPoint, GRID_DIRECTION::NORTH_EAST),
            Action(currentNode->gridPoint, GRID_DIRECTION::SOUTH_EAST),
            Action(currentNode->gridPoint, GRID_DIRECTION::SOUTH),
            Action(currentNode->gridPoint, GRID_DIRECTION::SOUTH_WEST),
//            Action(currentNode->gridPoint, GRID_DIRECTION::EAST),
//            Action(currentNode->gridPoint, GRID_DIRECTION::WEST),
        };
        
//        std::sort(frontierEdges.begin(), frontierEdges.end(), [&]( const Action* actionA, const Action* actionA) {
//            if( state)
//            int distA = (stateA->gridPoint->gridPosition - goal->gridPoint->gridPosition).lengthSquared();
//            int distB = (stateB->gridPoint->gridPosition - goal->gridPoint->gridPosition).lengthSquared();
//            return distA > distB;
//        });
        
//        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//        shuffle(frontierEdges.begin(), frontierEdges.end(), std::default_random_engine(seed));
        
//        bool hasValidState = false;
        // Pick the first action from above that is valid
        for(auto& anAction : frontierEdges) {
            
            State* aState = anAction.execute(currentNode, gridModel);
            
            if( aState->gridPoint == NULL ) continue;                                       // Invalid state
            if( _frontier->containsState( aState ) ) continue;                              // Already in frontier
            if( sequence->containsState( aState ) ) continue;                               // Already in sequence
            if( aState->gridPoint->hasEndPetalFacingDirection( anAction.direction ) ) {   // has petal there
                std::cout << "SkipA" << std::endl;
                continue;
            }
            if( aState->gridPoint->hasStartPetalFacingDirection( anAction.direction ) ) {   // has petal there
                std::cout << "SkipBa" << std::endl;
                continue;
            }

            if( !aState->gridPoint->isPermeable() ) {   // has petal there
                continue;
            }
            _frontier->pushState( aState );
        }
        
        _frontier->sort();
        
        // If we have a frontier state, remove it from the frontier and add it to the top of the sequence
        if( _frontier->getLastState() != NULL ) {
            sequence->pushState( _frontier->popState() );
        }
    }
}