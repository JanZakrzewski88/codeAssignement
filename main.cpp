/*
 * main.cpp
 *
 *  Created on: Jun 30, 2022
 *      Author: jan
 */
#include <iostream>
#include "Model.h"
#include "ControllerFactory.h"
#include "OverlapStrategyFactory.h"
#include "ObjectFactory.h"
#include "Position.h"


int main() {
	// The best approach to solve given problem is to utilize Model-View-Controller
	biosense_oop_example::Model simpleModel;
	auto strategy = biosense_oop_example::StrategyFactory::createStrategy(simpleModel);

	std::unique_ptr<biosense_oop_example::ControllerInterface> controller
					= biosense_oop_example::ControllerFactory::createController(simpleModel, *strategy);

	auto resetModel = [](biosense_oop_example::Model& model) {
		for (uint32_t x = 0; x < biosense_oop_example::Model::xSize; x++) {
			for (uint32_t y = 0; y < biosense_oop_example::Model::ySize; y++) {
				model.view[x][y] = biosense_oop_example::Model::backgroundColor;
			}
		}
	};

	auto printModel = [](biosense_oop_example::Model& model) {
		for (uint32_t x = 0; x < biosense_oop_example::Model::xSize; x++) {
			for (uint32_t y = 0; y < biosense_oop_example::Model::ySize; y++) {
				std::cout << model.view[x][y] << " ";
			}
			std::cout << std::endl;
		}
	};

	resetModel(simpleModel);
	printModel(simpleModel);
	std::cout << "<<<<<<<<<<<<<<>>>>>>>>>>>>>" <<std::endl;
	auto rect = biosense_oop_example::createObject(biosense_oop_example::Shape::Rectangle, 1u);
	auto rect2 = biosense_oop_example::createObject(biosense_oop_example::Shape::Rectangle, 2u);
	biosense_oop_example::Position pos(10, 10, 30);

	if (controller->canAddObject(rect.get(), &pos)) {
		controller->addObject(rect.get(), &pos);
	} else {
		std::cout << "CANT" <<std::endl;
	}
	printModel(simpleModel);

	if (controller->canAddObject(rect.get(), &pos)) {
		controller->addObject(rect.get(), &pos);
	} else {
		std::cout << "CANT #2" <<std::endl;
	}

	controller->removeObject(rect.get());
	std::cout << "<<<<<<<<<<<<<<>>>>>>>>>>>>>" <<std::endl;
	printModel(simpleModel);

	if (controller->canAddObject(rect.get(), &pos)) {
		controller->addObject(rect.get(), &pos);
	} else {
		std::cout << "CANT #3" <<std::endl;
	}
	std::cout << "<<<<<<<<<<<<<<>>>>>>>>>>>>>" <<std::endl;
	printModel(simpleModel);

	biosense_oop_example::Position pos2(40, 40, 30);
	if (controller->canAddObject(rect2.get(), &pos2)) {
		controller->addObject(rect2.get(), &pos2);
	} else {
		std::cout << "CANT #4" <<std::endl;
	}
	std::cout << "<<<<<<<<<<<<<<>>>>>>>>>>>>>" <<std::endl;
	printModel(simpleModel);

	biosense_oop_example::Position pos3(60, 60, 10);
	if (controller->canAddObject(rect2.get(), &pos3)) {
		controller->addObject(rect2.get(), &pos3);
	} else {
		std::cout << "CANT #5" <<std::endl;
	}
	std::cout << "<<<<<<<<<<<<<<>>>>>>>>>>>>>" <<std::endl;
	printModel(simpleModel);
}



