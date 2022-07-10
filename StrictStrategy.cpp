/*
 * StrictStrategy.cpp
 *
 *  Created on: Jun 30, 2022
 *      Author: jan
 */

#include "StrictStrategy.h"
#include "RenderUtils.h"

namespace biosense_oop_example {

StrictStrategy::StrictStrategy(Model &m) : model(m) {

}

StrictStrategy::~StrictStrategy() = default;

bool StrictStrategy::canPlaceObject(const ObjectInterface *object, const Position &position) const {
	return RenderUtils::canRenderWithoutOverlap(model, object, &position);
}


bool StrictStrategy::canMoveObject(const ObjectInterface *object, const Position &oldPosition, const Position &newPosition) const {
	RenderUtils::unrender(model, object, &oldPosition);
	auto ret = RenderUtils::canRenderWithoutOverlap(model, object, &newPosition);
	RenderUtils::render(model, object, &oldPosition);
	return ret;
}

}

