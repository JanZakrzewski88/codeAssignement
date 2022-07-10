/*
 * PositionInterface.h
 *
 *  Created on: Jun 30, 2022
 *      Author: jan
 */
#pragma once

#include <optional>

namespace biosense_oop_example {

class Position {
public:
	Position(int x, int y, int size);
	virtual ~Position();
	int getX() const;
	int getY() const;
	int getSize() const;
	Position makeCopy() const;
	Position& operator+=(const Position &other);

private:
	int xCoord;
	int yCoord;
	int size;
};

}
