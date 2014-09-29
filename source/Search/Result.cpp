//
//  Result.cpp
//  CircleMandala
//
//  Created by Gonzalez, Mario on 9/20/14.
//
//

#include "Result.h"
#include "State.h"
#include "Action.h"
#include "Grid.h"
#include "GridPoint.h"

namespace search{
    State* Result::execute(){
        return inAction->execute(inState, grid);
    }
}
