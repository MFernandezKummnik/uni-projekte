/*
 * ProcessList.H
 *
 *  Created on: Dec 8, 2011
 *      Author: R. Seepold, J. Martinez Fernandez
 */

#ifndef PROCESSLIST_H_
#define PROCESSLIST_H_

#include "Process.H"
#include <stddef.h>

class ProcessList {
private:
	Process* process_list; // space to store a Process instance
	Process* current; // pointer to the next process in the list

public:

	ProcessList();
	/*
	 * The list structure does not create or delete and dynamic memory element
	 * It is up to the user to create elements before storing them in the list
	 */

	~ProcessList();

	bool insert_first(Process*);
	/*
	 * This function gets a new process element end inserts this
	 * element at the beginning of the process list
	 */

	bool insert_last(Process*);
	/*
	 * This function gets a new process element end inserts this
	 * element at the end of the process list
	 */

	Process* remove(Process*);
	/*
	 * Takes the given element out of the list and returns
	 * this element as the result.
	 * The list remains with one element less.
	 */

	void show_all(void);
	/*
	 * Test function to flush the contents of the process list
	 */

	Process* get_first(void);
	/*
	 * Returns a pointer to the first element of the list
	 */
	Process* get_next(void);
	/*
	 * Return a pointer to the next element of the list, NULL in case there is no next element
	 */

	bool empty(void);
	/*
	 * Check whether the list is empty
	 */
};

#endif /* PROCESSLIST_H_ */
