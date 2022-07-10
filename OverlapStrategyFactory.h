/*
 * ControllerFactory.h
 *
 *  Created on: Jun 30, 2022
 *      Author: jan
 */
#pragma once

#include <memory>
#include "OverlapStrategyInterface.h"

namespace biosense_oop_example {
namespace StrategyFactory {

enum class strategyType : uint32_t {
	relaxed = 0,
	strict = 1,
	quard //should always be last on list
};

std::unique_ptr<OverlapStrategyInterface> createStrategy(Model &model, strategyType type = strategyType::strict);

}
}
