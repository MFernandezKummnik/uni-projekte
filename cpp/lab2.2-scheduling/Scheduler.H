/*
 * Scheduler.H
 *
 *  Created on: Dec 8, 2011
 *      Author: R. Seepold, J. Martinez Fernandez
 *      Version: 1.0
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "Process.H"
#include "ProcessList.H"
#include <stddef.h>

/*
 * The class contains a list with waiting processes as a private object
 *
 */
class Scheduler {
private:
	ProcessList ProcList;

public:
	void myNewProcess(Process*);
	/*
	 * The method receives a new process ready for insertation in the list
	 * The memory reservation has been done by the caller
	 */

	Process* mySchedule(int algo);
	/*
	 * This method call the scheduler function:
	 * algo=0 means the FCFS schedule simulation
	 * algo=1 means the SJF schedule algorithm
	 * The selected process will be eliminated from the
	 * list and attached as return value of the method
	 * In case the caller does not need to handle the
	 * return value, the returned object needs to
	 * be delete by the receiver of the return value
	 */
};

#endif /* SCHEDULER_H_ */
