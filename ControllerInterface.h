/*
 * ControllerInterface.h
 *
 *  Created on: Jun 30, 2022
 *      Author: jan
 */
#pragma once
#include "Model.h"
#include "ObjectInterface.h"
#include "Position.h"
#include "OverlapStrategyInterface.h"


namespace biosense_oop_example {

class ControllerInterface {
public:
	ControllerInterface();
	virtual ~ControllerInterface();

	virtual bool canAddObject(const ObjectInterface *object, const Position *position) const = 0;
	virtual void addObject(const ObjectInterface *object, const Position *position) = 0;

	virtual bool canMoveObject(const ObjectInterface *object, const Position *position) const = 0;
	virtual void moveObject(const ObjectInterface *object, const Position *position) = 0;

	virtual void removeObject(const ObjectInterface *object) = 0;

	virtual void selectObject(const ObjectInterface *object) = 0;
	virtual void unselectObject(const ObjectInterface *object) = 0;

	virtual bool canMoveSelected(const Position *diffPosition) const = 0;
	virtual void moveSelected(const Position *diffPosition) = 0;

	virtual void removeSelected() = 0;
};

}

