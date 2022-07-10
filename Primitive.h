/*
 * Primitive.h
 *
 *  Created on: Jul 1, 2022
 *      Author: jan
 */
#pragma once
#include "ObjectInterface.h"

namespace biosense_oop_example {

class Primitive : public ObjectInterface {
public:
	Primitive(Shape shape, uint32_t color);
	virtual ~Primitive();
	virtual Shape getShape() const;
	virtual uint32_t getColor() const;

private:
	Shape shape;
	uint32_t color;
};

}
