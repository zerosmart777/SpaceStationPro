// SpaceStationPro.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>
#include "SpaceStation.hpp"
#include "Robot.hpp"

int main()
{
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	std::cout << "Space Station base 1" << std::endl;
	std::shared_ptr<SpaceStation> spaceStationInput = std::make_shared<SpaceStation>();
	spaceStationInput->init();
	spaceStationInput->printStatus();
	spaceStationInput->setPositionX(30);
	spaceStationInput->setPositionY(40);
	spaceStationInput->setPositionZ(50);

	auto aRobot = spaceStationInput->getRobot();
	if (!aRobot.expired())
	{
		int roId = 0;
		while (roId<20) {
			aRobot.lock()->at(roId).talk();
			aRobot.lock()->at(roId).checkSpaceStation();
			roId++;
		}

	}

	std::cout << "\n--------------------------------" << std::endl;
	std::cout << "Space Station base 2" << std::endl;
	std::shared_ptr<SpaceStation> spaceStationInput2 = spaceStationInput;
	spaceStationInput2->init();
	spaceStationInput2->printStatus();

	auto aRobot2 = spaceStationInput2->getRobot();
	if (!aRobot2.expired())
	{
		int roId2 = 0;
		while (roId2 < 20) {
			aRobot2.lock()->at(roId2).talk();
			aRobot2.lock()->at(roId2).checkSpaceStation();
			roId2++;
		}
	}

	std::cout << "\n--------------------------------" << std::endl;

	spaceStationInput->setPositionX(60);
	spaceStationInput->setPositionY(70);
	spaceStationInput->setPositionZ(80);
	std::cout << "Space Station base 1" << std::endl;
	spaceStationInput->printStatus();
	std::cout << "Space Station base 2" << std::endl;
	spaceStationInput2->printStatus();

	std::cout << "\n--------------------------------" << std::endl;


	getchar();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
