/*
 * RenderUtils.h
 *
 *  Created on: Jun 30, 2022
 *      Author: jan
 */
#pragma once
#include "Model.h"

namespace biosense_oop_example {
class ObjectInterface;
class Position;
class Model;

namespace RenderUtils {

void render(Model &model, const ObjectInterface *object, const Position *position);
void unrender(Model &model, const ObjectInterface *object, const Position *position);
bool canRenderWithoutOverlap(Model &model, const ObjectInterface *object, const Position *position);

}
}
