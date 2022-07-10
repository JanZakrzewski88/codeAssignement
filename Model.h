/*
 * Model.h
 *
 *  Created on: Jun 30, 2022
 *      Author: jan
 */
#pragma once

#include <cstdint>
#include <array>

namespace biosense_oop_example {

struct Model {
	static constexpr uint32_t backgroundColor = 0;
	static constexpr uint32_t xSize = 80;
	static constexpr uint32_t ySize = 80;
	std::array<std::array<uint32_t, xSize>, ySize> view;
};

}
