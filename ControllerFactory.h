/*
 * ControllerFactory.h
 *
 *  Created on: Jun 30, 2022
 *      Author: jan
 */
#pragma once

#include <memory>

#include "ControllerInterface.h"

namespace biosense_oop_example {
namespace ControllerFactory {

std::unique_ptr<ControllerInterface> createController(Model &model, OverlapStrategyInterface &strategy);

}
}
