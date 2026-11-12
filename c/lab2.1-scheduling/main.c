/*
 * Real-time Operating Systems and Distributed Systems
 * Lab 2.1: Process Scheduling
 *
 * File: main.c
 * Version: 2.0
 *
 *  Created on: Dec 5, 2011
 *      Author: Javier Martinez
 *      		Ralf Seepold
 *
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include"MySchedule.h"

int main(int argc, char *argv[]) {

	process p1, p2, p3, p4, p5, p6, p7, p8, p9, p10;

	// the process selected for running in the CPU
	process scheduledProcess;

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

	// Switches to detect possible fails in the tests
	int sw, sw2 = 0;

	// Create some processes for tests
	p1.pid = 1;
	p1.time = 13;

	p2.pid = 2;
	p2.time = 7;

	p3.pid = 3;
	p3.time = 31;

	p4.pid = 4;
	p4.time = 6;

	p5.pid = 5;
	p5.time = 1;

	p6.pid = 6;
	p6.time = 34;

	p7.pid = 7;
	p7.time = 11;

	p8.pid = 8;
	p8.time = 2;

	p9.pid = 9;
	p9.time = 8;

	p10.pid = 10;
	p10.time = 4;

	// 1. First test  --> Required to have well done the creation process of the list and the scheduler without special cases
	myNewProcess(p1);
	myNewProcess(p2);
	myNewProcess(p3);
	scheduledProcess = mySchedule(1);
	myNewProcess(p4);
	if ((scheduledProcess.pid == 2) && (scheduledProcess.time == 7))
		printf("\nTest 1: passed");
	else {
		printf("\nTest 1: failed");
		error = 1;

	}

	// 2. Second test --> Required to have well done the creation process of the list and the scheduler (FCFS) with special cases (first, last, middle, null)

	scheduledProcess = mySchedule(0);
	if ((scheduledProcess.pid == 1) && (scheduledProcess.time == 13)) {
		scheduledProcess = mySchedule(0);
		if ((scheduledProcess.pid == 3) && (scheduledProcess.time == 31)) {
			scheduledProcess = mySchedule(0);
			if ((scheduledProcess.pid == 4) && (scheduledProcess.time == 6)) {
				scheduledProcess = mySchedule(0);
				if ((scheduledProcess.pid == 0) && (scheduledProcess.time == 0))
					sw = 1;
			}
		}
	}

	if (sw)
		printf("\nTest 2: passed");
	else {
		printf("\nTest 2: failed");
		error = 2;

	}

	// 3. Third test --> Calling the scheduler without processes waiting

	scheduledProcess = mySchedule(1);
	if ((scheduledProcess.pid == 0) && (scheduledProcess.time == 0))
		printf("\nTest 3: passed");
	else {
		printf("\nTest 3: failed");
		error = 3;

	}

	// 4. Fourth test --> Required to have well done the creation process of the list and the scheduler (SJF) with special cases (first, last, middle, null)

	myNewProcess(p1);
	myNewProcess(p2);
	myNewProcess(p3);
	scheduledProcess = mySchedule(1);
	myNewProcess(p4);
	scheduledProcess = mySchedule(1);
	if ((scheduledProcess.pid == 4) && (scheduledProcess.time == 6)) {
		scheduledProcess = mySchedule(1);
		if ((scheduledProcess.pid == 1) && (scheduledProcess.time == 13)) {
			scheduledProcess = mySchedule(1);
			if ((scheduledProcess.pid == 3) && (scheduledProcess.time == 31)) {
				scheduledProcess = mySchedule(1);
				if ((scheduledProcess.pid == 0) && (scheduledProcess.time == 0))
					sw2 = 1;
			}
		}
	}

	if (sw2)
		printf("\nTest 4: passed");
	else {
		printf("\nTest 4: failed");
		error = 4;
	}

    // Stress test

	// Starting point for CPU usage measure
	startTime = clock();

	/* First we create 10000 processes */
	for (i = 0; i < 10000; i++) {
		p1.pid = i + 1;
		/* the CPU time request of the process
		 is random between 1 and MAX_T */
		p1.time = rand() % INT_MAX - 1;
		myNewProcess(p1);
	}

	// Simulation of 5000 operations (process schedule o new process created) --> Depends on the computer could be more than 20 seconds of processing
	for (i = 0; i < 5000; i++) {
		scheduledProcess = mySchedule(1);
		myNewProcess(p5);
		scheduledProcess = mySchedule(0);
		scheduledProcess = mySchedule(1);
		myNewProcess(p6);
		myNewProcess(p7);
		myNewProcess(p8);
		myNewProcess(p9);
		scheduledProcess = mySchedule(0);
		myNewProcess(p10);
	}

	// End point for CPU usage measure
	startTime = clock() - startTime;

	if (error == 0) {
		printf("\nAll tests passed\n\n");
	}

	printf("\nCPU time= %ld\n\n", startTime);

	return 0;
}


