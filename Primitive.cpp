/*
 * Primitive.cpp
 *
 *  Created on: Jul 1, 2022
 *      Author: jan
 */

#include "Primitive.h"

namespace biosense_oop_example {

Primitive::Primitive(Shape s, uint32_t c) : shape(s), color(c)
{

}

Primitive::~Primitive() = default;

Shape Primitive::getShape() const {
	return shape;
}

uint32_t Primitive::getColor() const {
	return color;
}

}

