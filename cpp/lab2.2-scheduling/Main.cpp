//============================================================================
// Name        : main.cpp
// Author      : R. Seepold, J. Martinez Fernandez
// Version     : 1.0
// Copyright   : HTWG KOnstanz
// Description : Task 2.2: Scheduling Simulator in C++
//============================================================================

#include <stddef.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>
#include "Process.H"
#include "Scheduler.H"

using namespace std;

int main() {

	Process p1, p2, p3, p4, p5, p6, p7, p8, p9, p10;
	Process *new_process;
	Process *scheduledProcess;
	Scheduler myScheduler;
	int sw, sw2 = 0;

	// indicate test errors
	// error=1 means some tests failed
	// error=0 means execution without errors
	long error = 0;

	// seed for the random number generator
	srand(2011);

	// start time for runtime test
	clock_t startTime;

	// Index variable
	int i;

	// Create some processes for tests
	p1.set(1, 13);
	p2.set(2, 7);
	p3.set(3, 31);
	p4.set(4, 6);
	p5.set(5, 1);
	p6.set(6, 34);
	p7.set(7, 11);
	p8.set(8, 2);
	p9.set(9, 8);
	p10.set(10, 4);


	// 1. First test

	cout << "Test" << endl;

	myScheduler.myNewProcess(&p1);
	myScheduler.myNewProcess(&p2);
	myScheduler.myNewProcess(&p3);
	scheduledProcess = myScheduler.mySchedule(1);
	myScheduler.myNewProcess(&p4);
	if ((scheduledProcess->get_PID() == 2)
			&& (scheduledProcess->get_TIME() == 7))
		cout << "Test 1: passed" << endl;
	else {
		cout << "Test 1: failed" << endl;
		error = 1;

	}

	/*
	 * BE SURE THAT WE PASSING FURTHER ON THERE IS NO (!) STATIC VARIABLE IN THE REMAINING LIST
	 * LIKE FOR EXAMPLE THE TEST PROCESSES p1, p2, ...p10
	 * OTHERWISE THE DELETE WILL RESULTM IN A ERROR AND PROGRAM CRASH
	 *
	 */
	// 2. Second test
	scheduledProcess = myScheduler.mySchedule(0);
	if ((scheduledProcess->get_PID() == 1)
			&& (scheduledProcess->get_TIME() == 13)) {
		scheduledProcess = myScheduler.mySchedule(0);
		if ((scheduledProcess->get_PID() == 3)
				&& (scheduledProcess->get_TIME() == 31)) {
			scheduledProcess = myScheduler.mySchedule(0);
			if ((scheduledProcess->get_PID() == 4)
					&& (scheduledProcess->get_TIME() == 6)) {
				scheduledProcess = myScheduler.mySchedule(0);
				if (!scheduledProcess)
					sw = 1;
			}
		}
	}

	if (sw)
		cout << "Test 2: passed" << endl;
	else {
		cout << "Test 2: failed" << endl;
		error = 2;

	}

	// 3. Third test

	scheduledProcess = myScheduler.mySchedule(1);
	if (!scheduledProcess)
		cout << "Test 3: passed" << endl;
	else {
		cout << "Test 2: failed" << endl;
		error = 3;
	}

	// 4. Fourth test

	myScheduler.myNewProcess(&p1);
	myScheduler.myNewProcess(&p2);
	myScheduler.myNewProcess(&p3);
	scheduledProcess = myScheduler.mySchedule(1);
	myScheduler.myNewProcess(&p4);
	scheduledProcess = myScheduler.mySchedule(1);
	if ((scheduledProcess->get_PID() == 4)
			&& (scheduledProcess->get_TIME() == 6)) {
		scheduledProcess = myScheduler.mySchedule(1);
		if ((scheduledProcess->get_PID() == 1)
				&& (scheduledProcess->get_TIME() == 13)) {
			scheduledProcess = myScheduler.mySchedule(1);
			if ((scheduledProcess->get_PID() == 3)
					&& (scheduledProcess->get_TIME() == 31)) {
				scheduledProcess = myScheduler.mySchedule(1);
				if (!scheduledProcess)
					sw2 = 1;
			}
		}
	}

	if (sw2)
		cout << "Test 4: passed" << endl;
	else {
		cout << "Test 4: failed" << endl;
		error = 4;

	}

	// Stress test
	// Starting point for CPU usage measure
	startTime = clock();

	// Simulation of 300000 operations (process schedule o new process created)

	for (i = 0; i < 30000; i++) {
		// the CPU time request of the process
		// is random between 1 and MAX_T
		new_process = new (Process);
		new_process->set(i + 1, (rand() % INT_MAX - 1));

		myScheduler.myNewProcess(new_process);

	} // end of for loop

	for (i = 0; i < 30000; i++) {

		scheduledProcess = myScheduler.mySchedule(0);
		delete scheduledProcess;
	} // end of for loop*/

	// End point for CPU usage measure
	startTime = clock() - startTime;

	if (error == 0) {
		cout << "All Test passed" << endl;
	}

	cout << "CPU time= " << startTime << endl;

	return 0;
}
