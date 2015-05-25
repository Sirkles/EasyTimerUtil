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
//  Sirkles_EasyTimer_Examples.java
//
//  Created by Josh Kennedy and Chad Jensen on 29 April 2015
//  Copyright (C) 2015 Sirkles LLC. All rights reserved.
//

public class Sirkles_EasyTimer_Examples {

	// Declare our Timer
	static EasyTimerUtil myTimer;

	public static void main(String[] args) {
		// Initialize timer.
		myTimer = new EasyTimerUtil();

		// A timer that counts down from 10 to 0.
		countDown();

		// A clock that displays elapsed time (we control when clock starts!).
		deltaTime();

		// An example of pausing and resuming the timer:
		pauseResume(); 

		System.exit(0);

	}

	public static void countDown(){

		// Start our timer
		myTimer.setStartTime();
		// Set how long our timer will last in seconds (10)
		myTimer.setCountDown(15);

		while(myTimer.getRemainingTime() >= 0.0) {

			// in order for our object times to update, we must call updateTimes
			myTimer.updateTimes();

			// System.out.println("Remaining time in Milliseconds: " + myTimer.getRemainingTime());
			System.out.println("Remaining time in Seconds: " + myTimer.getRemainingTime() / 1000);

		}

	}

	public static void deltaTime() {

		
		// Start our clock
		myTimer.setStartTime();
		// 
		myTimer.setCountDown(10);

		while (myTimer.getRemainingTime() >= 0.0 ) {
			// update our clock
			myTimer.updateTimes();

			// System.out.println("Elapsed Time in Milli: " + myTimer.getElapsedTime());
			System.out.print("Elapsed Time in Seconds: " + myTimer.getElapsedTime()/1000);
			// Shows the percentage of total elapsed time
			System.out.println(" (" +(myTimer.getRatioElapsed() * 100) + " %) ");
		}

	}

	// Ideally, this would display the same time after pause and resume
	// the difference in time is the call to the next method.
	public static void pauseResume() { 


		myTimer.setStartTime();
		// Set how long our timer will last in seconds (30)
		myTimer.setCountDown(30);
		myTimer.updateTimes();

		// This will be used later to show Delta Time stays Constant 
		// in between pauses and resumes.
		double startingElapsedTime = myTimer.getElapsedTime();

		// We can pause multiple times!
		for (int i = 0; i <= 2; i++) { 

			System.out.println("Number of times paused: " + (i+1));

			// Display time remaining on our timer before Pause
			System.out.println("Time Remaining before pause: " + myTimer.getRemainingTime());

			// Pause our timer
			myTimer.pause();	

			// Emulate user pause
			for (int j = 0; j < 500000000; j++){myTimer.updateTimes();}

			// Resume our timer
			myTimer.resume();

			// Display time remaining on our timer after Resume
			System.out.println("Time Remaining after pause: " + myTimer.getRemainingTime() + "\n");
		}

		// Our Timer object smartly updated our Elapsed time (It is the approximately the same)!
		System.out.println("Total elapsed time before pause (ms): " + startingElapsedTime);
		System.out.println("Total elapsed time after pause (ms): " + myTimer.getElapsedTime());

	}


}
