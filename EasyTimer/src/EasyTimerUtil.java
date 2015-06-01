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
//  EasyTimerUtil.java
//
//  Created by Josh Kennedy and Chad Jensen on 29 April 2015
//  Copyright (C) 2015 Sirkles LLC. All rights reserved.
//

public class EasyTimerUtil {

	private static double curTime;
	private double countDown;
	private double elapsedTime;
	private double remainingTime;
	private double startTime;
	private double timer;
	private double addedTime;

	// Pause Variables
	public boolean paused;
	double pausedAtTime; // used to set the time at which we paused the object at.
	double curElapsedPauseTime; // used for the current pause
	double totElapsedPauseTime; // variable used for if we pause multiple times




	public EasyTimerUtil(){
		paused = false;
		countDown = 0;
		curElapsedPauseTime = 0;
		totElapsedPauseTime = 0;
		addedTime = 0;
		updateTimes();
	}


	// The current system time.
	public void setCurTime(){
		curTime = System.currentTimeMillis(); 
	}

	// This is when the timer starts
	public void setStartTime(){
		startTime = System.currentTimeMillis();
		curElapsedPauseTime = 0;
		totElapsedPauseTime = 0;
		addedTime = 0;
		updateTimes();
	}

	// This is how long a timer will last
	// for RemainingTime to work, this must be set
	public void setCountDown(double parCountDown){

		countDown = parCountDown * 1000;
		setTimer(countDown);
	}

	// This sets the total number of Milliseconds that we're counting to/from.
	private void setTimer(double parEndTime){

		//endTime =  (parEndTime);
		timer =  (parEndTime) + (totElapsedPauseTime + curElapsedPauseTime);


	}

	// this can be used for Time Remaining of the total Time alloted WITHIN the object.. 
	private void setRemainingTime(){
		remainingTime = (startTime + timer + addedTime) -curTime;
	}	

	// Delta time
	private void setElapsedTime(){
		
		elapsedTime =  curTime - (totElapsedPauseTime + curElapsedPauseTime + addedTime) - startTime;
	}

	// returns the system's current time
	public double getCurTime(){
		return curTime;
	}
	// returns how long our timer is set for
	public double getTimerinMS(){
		return timer;
	}
	// returns the remaining time before timer ends
	public double getRemainingTime(){
		return remainingTime;
	}
	
	public double getRatioElapsed() {
	    return (elapsedTime / (timer - (curElapsedPauseTime+totElapsedPauseTime)));
	}
	// returns how much time has passed since beginning of timer
	public double getElapsedTime(){
		return elapsedTime;
	}
	public double getStartTime(){
		return startTime;
	}
	public void pause() {
		paused = true;
		pausedAtTime = System.currentTimeMillis();
	}
	public void resume() {
		totElapsedPauseTime = totElapsedPauseTime + curElapsedPauseTime;
		curElapsedPauseTime = 0.0;
		paused = false;

	}
	public void addTime(long parAdd) {
		addedTime += parAdd;
	}
	public void subtractTime(long parSub) {
		addedTime -= parSub;
	}
	
	// This function MUST be called each loop in order to update all values in this object.
	public void updateTimes(){

		setCurTime();
		if(paused) {
			updatePauseTimes();

		}
		
		setElapsedTime();
		setRemainingTime();

	}
	private void updatePauseTimes(){
		curElapsedPauseTime = curTime - pausedAtTime; // the elapsed time this cycle.
		setTimer(countDown); // need to update this as well, since it's only being called at instantiation.

	}

	public void debugTimes(){
		System.out.println("start time: " + startTime);
		System.out.println("countdown: " + countDown);
		System.out.println("cur time: " + curTime);
		System.out.println("remaining time:  " + remainingTime);
		System.out.println("totElapsedPauseTime:  " + totElapsedPauseTime);
		System.out.println("curElapsedPauseTime:  " + curElapsedPauseTime);
	}




}
