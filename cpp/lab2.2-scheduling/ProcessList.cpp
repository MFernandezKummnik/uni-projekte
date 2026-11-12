/*
 * ProcessList.cpp
 *
 *  Created on: Dec 8, 2011
 *      Author: R. Seepold, J. Martinez Fernandez
 */

#include "ProcessList.H"
#include "Process.H"
#include <stddef.h>
#include <iostream>
#include <stdio.h>

using namespace std;

ProcessList::ProcessList() {

	process_list = NULL; // this is the head of the single lined queue
	current = process_list;
	/* points to the last visited element, e.g. in case
	 *  this element is deleted it moves back to the head
	 */
}

ProcessList::~ProcessList() {
	;
}

bool ProcessList::insert_first(Process *new_process) {

	if (process_list) {
		new_process->set_next(process_list);
		process_list = new_process;
		current = process_list;
	} else {
		process_list = new_process;
		current = process_list;
	}

	return (true); // return value not really needed; might be changed to void
}


void ProcessList::show_all(void) {
	Process *tmp_process_ptr = process_list;

	while (tmp_process_ptr) {
		cout << "(" << tmp_process_ptr->get_PID() << ", "
				<< tmp_process_ptr->get_TIME() << ") ";
		tmp_process_ptr = tmp_process_ptr->get_next();
	}
	cout << endl;
}

/********************************************************************************
* INSERT YOUR CODE AFTER THIS LINE
********************************************************************************/

bool ProcessList::insert_last(Process* a){
a->set_next(NULL);
if(process_list){
	Process* akt= process_list;
	while (akt->get_next()!=NULL){
		akt=akt->get_next();
	}
	akt->set_next(a);
	}
else {
	process_list = a;
		current = process_list;

}
return true;
}

bool ProcessList::empty(void){
	if(process_list){
		return false;
	}
	else{
		return true;
	}
}

Process* ProcessList::get_first(void){
	current = process_list;
	return current;
}
Process* ProcessList::get_next(void){
	if(current == NULL){
		return NULL;
	}
	else{
		current = current->get_next();
		return current;
	}
}
Process* ProcessList::remove(Process* a){
	if (process_list){
		if(a == process_list){
			process_list = process_list->get_next();
			current = process_list;
			a->set_next(NULL);
			return a;
		}
		else{
			Process* akt = process_list;
			while (akt->get_next()!= a && akt->get_next()!=NULL){
			akt=akt->get_next();
				}
			if(akt->get_next()==NULL){
			return NULL;
			}
			else{
			akt->set_next(a->get_next());
			a->set_next(NULL);
			current = process_list;
			return a;	
			}
		}
	}
	else{
		return NULL;
	}
}