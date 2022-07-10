/*
 * ObectInterface.h
 *
 *  Created on: Jun 30, 2022
 *      Author: jan
 */
#pragma once
#include "Shapes.h"

namespace biosense_oop_example {

class ObjectInterface {
public:
	ObjectInterface();
	virtual ~ObjectInterface();
	virtual Shape getShape() const = 0;
	virtual uint32_t getColor() const = 0;

};

}
