/*
 * ObjectFactory.h
 *
 *  Created on: Jun 30, 2022
 *      Author: jan
 */
#pragma once

#include <memory>

#include "Shapes.h"
#include "ObjectInterface.h"

namespace biosense_oop_example {

std::unique_ptr<ObjectInterface> createObject(Shape s, uint32_t color);

}
