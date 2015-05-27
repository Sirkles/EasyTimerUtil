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
//  EasyTimer.cpp
//
//  Created by Josh Kennedy and Chad Jensen on 23 May 2015
//  Copyright (C) 2015 Sirkles LLC. All rights reserved.
//

#include "EasyTimerUtil.h"

long long EasyTimerUtil::curTime = 0;

EasyTimerUtil::EasyTimerUtil() {
	paused = false;

	countDown = 0;
	curElapsedPauseTime = 0;
	totElapsedPauseTime = 0;

	updateTimes();
}

void EasyTimerUtil::updateTimes() {
	setCurTime();

	if (paused) {
		updatePauseTimes();
	}

	setDeltaTime();
	setRemainingTime();
}

void EasyTimerUtil::setCurTime() {
	curTime = currentTimeMillis();
}

void EasyTimerUtil::setStartTime() {
	startTime = currentTimeMillis();

	curElapsedPauseTime = 0;
	totElapsedPauseTime = 0;

	updateTimes();
}

void EasyTimerUtil::setCountDown(long long parCountDown) {
	countDown = parCountDown * 1000;
	setTimer(countDown);
}

long long EasyTimerUtil::getCurTime() const {
	return curTime;
}

long long EasyTimerUtil::getTimerInMS() const {
	return timer;
}

long long EasyTimerUtil::getRemainingTime() const {
	return remainingTime;
}

double EasyTimerUtil::getRatioElapsed() const {
	return (elapsedTime / (double)(timer - (curElapsedPauseTime + totElapsedPauseTime)));
}

long long EasyTimerUtil::getElapsedTime() const {
	return elapsedTime;
}

void EasyTimerUtil::pause() {
	paused = true;

	pausedAtTime = currentTimeMillis();
}

void EasyTimerUtil::resume() {
	totElapsedPauseTime += curElapsedPauseTime;
	curElapsedPauseTime = 0;

	paused = false;
}

void EasyTimerUtil::updatePauseTimes() {
	curElapsedPauseTime = curTime - pausedAtTime;
	setTimer(countDown);
}

void EasyTimerUtil::setTimer(long long parEndTime) {
	timer = parEndTime + (totElapsedPauseTime + curElapsedPauseTime);
}

void EasyTimerUtil::setDeltaTime() {
	elapsedTime = curTime - (totElapsedPauseTime + curElapsedPauseTime) - startTime;
}

void EasyTimerUtil::setRemainingTime() {
	remainingTime = (startTime + countDown + (totElapsedPauseTime + curElapsedPauseTime)) - curTime;
}

void EasyTimerUtil::setElapsedTime() {
	elapsedTime = curTime - (totElapsedPauseTime + curElapsedPauseTime) - startTime;
}

long long EasyTimerUtil::currentTimeMillis() {
	// time() returns seconds, and this returns milliseconds
	return std::chrono::duration_cast<std::chrono::milliseconds>(
		std::chrono::system_clock::now().time_since_epoch()).count();
}
