/*
 * PositionInterface.cpp
 *
 *  Created on: Jun 30, 2022
 *      Author: jan
 */
#include "Position.h"

namespace biosense_oop_example {

Position::Position(int x, int y, int s) :
		xCoord(x), yCoord(y), size(s) {

}

Position::~Position() = default;

int Position::getX() const {
	return xCoord;
}

int Position::getY() const {
	return yCoord;
}

int Position::getSize() const {
	return size;
}

Position Position::makeCopy() const {
	Position copy(xCoord, yCoord, size);
	return copy;
}

Position& Position::operator+=(const Position &other) {
	xCoord += other.xCoord;
	yCoord += other.yCoord;
	size += other.size;
	return *this;
}

}

