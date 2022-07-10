/*
 * Shapes.hpp
 *
 *  Created on: Jun 30, 2022
 *      Author: jan
 */
#pragma once
#include <cstdint>
namespace biosense_oop_example {

enum class Shape: uint32_t {
	Rectangle = 0,
	Circle = 1,
	Triangle = 2,
	Guard //should always be last
};

}
