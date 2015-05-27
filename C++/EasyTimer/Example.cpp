/*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation, either version 2.1 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

//
//  Example.cpp
//
//  Created by Josh Kennedy and Chad Jensen on 23 May 2015
//  Copyright (C) 2015 Sirkles LLC. All rights reserved.
//

#include "EasyTimerUtil.h"

#include <iostream>

class Examples
{
public:
	static Examples* getInstance() {
		if (!Examples::instance) {
			Examples::instance = new Examples();
		}

		return Examples::instance;
	}

	int run() {
		std::cout << "EasyTimer from Sirkles with love <3\n" << std::endl;

		countDown();

		deltaTime();

		pauseResume();

		return 0;
	}

private:
	EasyTimerUtil* myTimer;

	Examples() {
		this->myTimer = new EasyTimerUtil();
	}

	void countDown() {
		myTimer->setStartTime();

		myTimer->setCountDown(15);

		while (myTimer->getRemainingTime() >= 0.0) {
			myTimer->updateTimes();

			std::cout << "Remaining time in Seconds: " << 
				(double)(myTimer->getRemainingTime() / 1000.0) << std::endl;
		}
	}

	void deltaTime() {
		myTimer->setStartTime();

		myTimer->setCountDown(10);

		while (myTimer->getRemainingTime() >= 0.0) {
			myTimer->updateTimes();

			std::cout << "Remaining time in Seconds: " <<
				(double)(myTimer->getRemainingTime() / 1000.0) << ' ';

			std::cout << "(" << (myTimer->getRatioElapsed() * 100) << "%)" <<
				std::endl;
		}
	}

	void pauseResume() {
		myTimer->setStartTime();

		myTimer->setCountDown(30);
		myTimer->updateTimes();

		long long startingElapsedTime = myTimer->getElapsedTime();

		for (int i = 0; i <= 2; ++i) {
			std::cout << "Number of times paused: " << (i + 1) << std::endl;

			std::cout << "Time Remaining before pause: " <<
				myTimer->getRemainingTime() << std::endl;

			myTimer->pause();

			std::cout << "counting to 5000000 . . . ";
			for (int j = 0; j < 5000000; j++) {
				myTimer->updateTimes(); 
			}

			std::cout << "\n" << std::endl;

			myTimer->resume();

			std::cout << "Time Remaining after pause: " << 
				myTimer->getRemainingTime() << "\n" << std::endl;
		}

		std::cout << "Total time elapsed before pause (ms)" << 
			startingElapsedTime << std::endl;

		std::cout << "Total time elapsed after pause (ms)" <<
			myTimer->getElapsedTime() << std::endl;
	}

	static Examples* instance;
};

Examples* Examples::instance = nullptr;

int main(int argc, char* argv[]) {
	return Examples::getInstance()->run();
}
