/*
 * Controller.h
 *
 *  Created on: Jun 30, 2022
 *      Author: jan
 */
#pragma once
#include <memory>
#include <utility>
#include <unordered_map>
#include <set>
#include "ControllerInterface.h"

namespace biosense_oop_example {

class Controller : public ControllerInterface {
public:
	Controller(Model &model, OverlapStrategyInterface &strategy);
	virtual ~Controller();

	virtual bool canAddObject(const ObjectInterface *object, const Position *position) const;
	virtual void addObject(const ObjectInterface *object, const Position *position);

	virtual bool canMoveObject(const ObjectInterface *object, const Position *position) const;
	virtual void moveObject(const ObjectInterface *object, const Position *position);

	virtual void removeObject(const ObjectInterface *object);

	virtual void selectObject(const ObjectInterface *object);
	virtual void unselectObject(const ObjectInterface *object);

	virtual bool canMoveSelected(const Position *diffPosition) const;
	virtual void moveSelected(const Position *diffPosition);

	virtual void removeSelected();

private:
	Model &model;
	OverlapStrategyInterface &strategy;

	std::unordered_map<const ObjectInterface*, const Position*> objects;
	std::set<const ObjectInterface*> selected;

private:
	std::optional<const Position*> findOldPosition(const ObjectInterface *object) const;

};

}
