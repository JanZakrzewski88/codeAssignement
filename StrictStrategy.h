/*
 * StrictStrategy.h
 *
 *  Created on: Jun 30, 2022
 *      Author: jan
 */
#pragma once
#include "OverlapStrategyInterface.h"

namespace biosense_oop_example {

class StrictStrategy : public OverlapStrategyInterface {
public:
	StrictStrategy(Model &model);
	virtual ~StrictStrategy();

	virtual bool canPlaceObject(const ObjectInterface *object, const Position &position) const;
	virtual bool canMoveObject(const ObjectInterface *object, const Position &oldPosition, const Position &newPosition) const;

private:
	Model &model;
};

}
