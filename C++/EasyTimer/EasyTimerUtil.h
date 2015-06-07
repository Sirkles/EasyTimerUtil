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
//  EasyTimer.h
//
//  Created by Josh Kennedy and Chad Jensen on 23 May 2015
//  Copyright (C) 2015 Sirkles LLC. All rights reserved.
//

#ifndef SIRKLES_EASYTIMER_H_
#define SIRKLES_EASYTIMER_H_

#pragma once

#include <chrono>

/**
 * EasyTimer: A simple millisecond timer.
 * @author Josh Kennedy (C++ implementation)
 * @author Chad Jensen (Original Java implementation)
 */
class EasyTimerUtil
{
public:
	// Creates a new EasyTimerUtil instance.
	EasyTimerUtil();

	bool paused;

	// This function MUST be called each loop in order to update all values in this object.
	void updateTimes();

	// The current system time.
	void setCurTime();

	// This is when the timer starts.
	void setStartTime();

	void addTime(long long parAdd);

	void subtractTime(long long parSub);

	// This is how long the timer will last.
	// (for RemainingTime to work, this must be called)
	void setCountDown(long long parCountDown);

	// This returns the system's current time in milliseconds.
	long long getCurTime() const;

	// returns how long our timer is set for
	long long getTimerInMS() const;

	// returns the remaining time before timer ends
	long long getRemainingTime() const;

	// Returns a percentage of time remaining as a value between 0 and 1.
	double getRatioElapsed() const;

	// returns how much time has passed since beginning of timer
	long long getElapsedTime() const;

	void pause();

	void resume();

private:
	static long long curTime;
	long long countDown;
	long long elapsedTime;
	long long remainingTime;
	long long startTime;
	long long timer;
	long long addedTime;

	/* Pause Variables */
	long long pausedAtTime; // This is used to set the at which we paused at.
	long long curElapsedPauseTime; // Used for the current pause time.
	long long totElapsedPauseTime; // Used if we pause multipe times.

	void updatePauseTimes();

	// This sets the total number of Milliseconds that we're counting to/from.
	void setTimer(long long parEndTime);

	// Delta time
	void setDeltaTime();

	// this can be used for Time Remaining of the total Time alloted WITHIN the object.. 
	void setRemainingTime();

	void setElapsedTime();

	static long long currentTimeMillis();
};

#endif  /* defined(SIRKLES_EASYTIMER_H_) */
