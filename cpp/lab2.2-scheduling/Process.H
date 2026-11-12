/*
 * Process.H
 *
 *  Created on: Dec 8, 2011
 *      Author: R. Seepold, J. Martinez Fernandez
 */

#ifndef PROCESS_H_
#define PROCESS_H_

/*
 * Each process will store three values: the process number PID
 * the next Burst time (TIME)
 * an a pointer to the next process
 */
class Process {

private:
	int pid;
	int time;
	Process *next;

public:
	Process();
	~Process();

	bool set(int pid, int time);
	/* set the pid and time varaibles of the process
	 * the next pointer will be always NULL
	 */

	void set_next(Process*);
	/* Define the next pointer as a pointer that is pointing
	 * the the element referenced in the parameter of the method
	 */

	Process* get(void);
	/*
	 * Return a pointer to the current process
	 */

	Process* get_next(void);
	/*
	 * Return a pointer to the next process in the linked list
	 */

	int get_PID(void);
	/* Return the pid-value to the caller
	 *
	 */

	int get_TIME(void);
	/*
	 * Return the time data to the calling method
	 */
};

#endif /* PROCESS_H_ */
