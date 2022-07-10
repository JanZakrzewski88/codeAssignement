/*
 * ObjectFactory.cpp
 *
 *  Created on: Jun 30, 2022
 *      Author: jan
 */

#include "ObjectFactory.h"
#include "Primitive.h"

namespace biosense_oop_example {

std::unique_ptr<ObjectInterface> createObject(Shape s, uint32_t color) {
	return std::make_unique<Primitive>(s, color);
}

}
