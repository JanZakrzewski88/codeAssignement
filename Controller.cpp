/*
 * Controller.cpp
 *
 *  Created on: Jun 30, 2022
 *      Author: jan
 */

#include "Controller.h"
#include "RenderUtils.h"

namespace biosense_oop_example {

Controller::Controller(Model &m, OverlapStrategyInterface &s) : model(m), strategy(s) {

}

Controller::~Controller() = default;

bool Controller::canAddObject(const ObjectInterface *object, const Position *position) const {
	return (0 == objects.count(object)) &&
		  strategy.canPlaceObject(object, *position);
}

void Controller::addObject(const ObjectInterface *object, const Position *position) {
	if (canAddObject(object, position))
		objects[object] = position;
	RenderUtils::render(model, object, position);
}

bool Controller::canMoveObject(const ObjectInterface *object, const Position *position) const {
	auto oldPos = findOldPosition(object);
	if (oldPos) {
		return strategy.canMoveObject(object, **oldPos, *position);
	}
	return false;
}

void Controller::moveObject(const ObjectInterface *object, const Position *position) {
	if (canMoveObject(object, position)) {
		RenderUtils::unrender(model, object, objects[object]);
		objects[object] = position;
		RenderUtils::render(model, object, position);
	}
}

void Controller::removeObject(const ObjectInterface *object) {
	RenderUtils::unrender(model, object, objects[object]);
	objects.erase(object);
	selected.erase(object);
}

void Controller::selectObject(const ObjectInterface *object) {
	selected.insert(object);
}

void Controller::unselectObject(const ObjectInterface *object) {
	selected.erase(object);
}

bool Controller::canMoveSelected(const Position *diffPosition) const {
	for (const auto elem : selected) {
		auto oldPos = findOldPosition(elem);
		if (oldPos) {
			auto newPos = (*oldPos)->makeCopy();
			newPos += *diffPosition;
			if (!strategy.canMoveObject(elem, **oldPos, newPos)) {
				return false;
			}
		} else {
			return false;
		}
	}
	return true;
}

void Controller::moveSelected(const Position *diffPosition) {
	if (canMoveSelected(diffPosition)) {
		for (const auto elem : selected) {
			auto oldPos = findOldPosition(elem);
			if (oldPos) {
				auto newPos = (*oldPos)->makeCopy();
				newPos += *diffPosition;
				moveObject(elem, &newPos);
			}
		}
	}
}

void Controller::removeSelected() {
	for (const auto elem : selected) {
		removeObject(elem);
	}
}

std::optional<const Position*> Controller::findOldPosition(const ObjectInterface *object) const {
	for (const auto &elem : objects) {
		if (elem.first == object) {
			return {elem.second};
		}
	}
	return {};
}

}
