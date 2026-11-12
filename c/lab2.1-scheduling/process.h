/*
 * process.h
 *
 *  Created on: Dec 5, 2011
 *      Author: Javier Martinez
 *      		Ralf Seepold
 *
 */

#ifndef PROCESS_H_
#define PROCESS_H_

/* The process data type is used to represent the information
 * of a process that the operating system would keep.
 * In our case, this information is simplified and consists
 * only of the process identifier (pid) and the CPU time
 * required by the process (this data is needed to be able
 * to do the planning using Shortest-Job-First).
 */

struct process {
	int pid; /* Process identifier */
	int time; /* time units required */
};

typedef struct process process;

#endif /* PROCESS_H_ */
