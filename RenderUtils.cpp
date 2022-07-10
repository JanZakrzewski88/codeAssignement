/*
 * RenderUtils.cpp
 *
 *  Created on: Jun 30, 2022
 *      Author: jan
 */
#include <cstdint>
#include <iostream>
#include "RenderUtils.h"
#include "Model.h"
#include "ObjectInterface.h"
#include "Position.h"

namespace biosense_oop_example {
namespace RenderUtils {

static bool drawRectangle(Model &model, const Position* position, uint32_t color) {
	//check boundaries
	auto size = position->getSize();
	auto x = position->getX();
	auto y = position->getY();
	if (Model::xSize < x + size ||
			Model::ySize < y + size) {
		return false;
	}
	for (uint32_t xIndex = x; xIndex < x + size; xIndex++) {
		for (uint32_t yIndex = y; yIndex < y + size; yIndex++) {
			model.view[xIndex][yIndex] = color;
		}
	}
	return true;
}

static bool drawTriangle(Model &model, const Position* position, uint32_t color) {
	//not supported now
}

static bool drawCircle(Model &model, const Position* position, uint32_t color) {
	//not supported now
}

static bool checkRectangle(Model &model, const Position* position) {
	//check boundaries
	auto size = position->getSize();
	auto x = position->getX();
	auto y = position->getY();
	if (Model::xSize < x + size ||
			Model::ySize < y + size) {
		std::cout << "OUT OF BOUNDARIES" <<std::endl;
		return false;
	}
	for (uint32_t xIndex = x; xIndex < x + size; xIndex++) {
		for (uint32_t yIndex = y; yIndex < y + size; yIndex++) {
			if (model.view[xIndex][yIndex] != Model::backgroundColor) {
				std::cout << "Overlap:" << xIndex << " " << yIndex <<std::endl;
				return false;
			}
		}
	}
	return true;
}

static bool checkTriangle(Model &model, const Position* position) {
	//not supported now
}

static bool checkCircle(Model &model, const Position* position) {
	//not supported now
}

void render(Model &model, const ObjectInterface *object, const Position *position) {
	switch (object->getShape()) {
		case Shape::Rectangle:
			drawRectangle(model, position, object->getColor());
			break;
		case Shape::Triangle:
			drawTriangle(model, position, object->getColor());
			break;
		case Shape::Circle:
			drawCircle(model, position, object->getColor());
			break;
	}
}

void unrender(Model &model, const ObjectInterface *object, const Position *position) {
	switch (object->getShape()) {
		case Shape::Rectangle:
			drawRectangle(model, position, Model::backgroundColor);
			break;
		case Shape::Triangle:
			drawTriangle(model, position, Model::backgroundColor);
			break;
		case Shape::Circle:
			drawCircle(model, position, Model::backgroundColor);
			break;
	}
}

bool canRenderWithoutOverlap(Model &model, const ObjectInterface *object, const Position *position) {
	switch (object->getShape()) {
		case Shape::Rectangle:
			return checkRectangle(model, position);
		case Shape::Triangle:
			return checkTriangle(model, position);
		case Shape::Circle:
			return checkCircle(model, position);
	}
	return false;
}

}
}

