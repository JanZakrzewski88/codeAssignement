/*
 * ControllerFactory.h
 *
 *  Created on: Jun 30, 2022
 *      Author: jan
 */
#pragma once

#include "ControllerFactory.h"
#include "Controller.h"

namespace biosense_oop_example {

namespace ControllerFactory {

std::unique_ptr<ControllerInterface> createController(Model &model, OverlapStrategyInterface &strategy) {
	return std::make_unique<Controller>(model, strategy);
}

}
}
