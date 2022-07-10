/*
 * OverlapStrategyInterface.h
 *
 *  Created on: Jun 30, 2022
 *      Author: jan
 */

#pragma once

#include "Model.h"
#include "ObjectInterface.h"
#include "Position.h"

namespace biosense_oop_example {

class OverlapStrategyInterface {
public:
	OverlapStrategyInterface();
	virtual ~OverlapStrategyInterface();
	virtual bool canPlaceObject(const ObjectInterface *object, const Position &position) const = 0;
	virtual bool canMoveObject(const ObjectInterface *object, const Position &oldPosition, const Position &newPosition) const = 0;

};

}
