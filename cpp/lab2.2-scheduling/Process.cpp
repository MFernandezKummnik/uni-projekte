/*
 * Process.cpp
 *
 *  Created on: Dec 8, 2011
 *      Author: R. Seepold, J. Martinez Fernandez
 */

#include "Process.H"
#include<stddef.h>

Process::Process() {
	this->pid = 0;
	this->time = 0;
	this->next = NULL;
}


Process::~Process() {
	// Nichts zu tun: Process legt selbst keinen Speicher mit new an.
    // next wird bewusst NICHT geloescht, da die Liste bzw. main
    // fuer das Freigeben der Prozesse zustaendig ist.
}

bool Process::set(int p_pid, int p_time) {
	this->pid = p_pid;
	this->time = p_time;
	this->next = NULL;
	return true;
}

void Process::set_next (Process* new_process) {
	this->next = new_process;
}


int Process::get_PID() {
	return this->pid;
}

int Process::get_TIME() {
	return this->time;
}

Process* Process::get(void) {
	return this;
}

Process* Process::get_next(void) {
	return this->next;
}
