#include "OverlapStrategyFactory.h"
#include "StrictStrategy.h"

namespace biosense_oop_example {
namespace StrategyFactory {

std::unique_ptr<OverlapStrategyInterface> createStrategy(Model &model, strategyType type) {
	//now only one strategy is supported
	return std::make_unique<StrictStrategy>(model);
}

}
}
