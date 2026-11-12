
#include "Scheduler.H"
#include <stddef.h>
#include <iostream>
#include <stdio.h>
void Scheduler::myNewProcess(Process* a){
ProcList.insert_last(a);
}
Process* Scheduler::mySchedule(int algo){
    if(!ProcList.empty()){
        if(algo == 0){
            Process* a = ProcList.get_first();
            ProcList.remove(a);
            return a;
        }
        else{
            Process* hilfszeiger = ProcList.get_first(); 
            Process* akt = ProcList.get_first();
            int timeakt = ProcList.get_first()->get_TIME();
            while(akt != 0){
                if(timeakt > akt->get_TIME()){
                    timeakt = akt->get_TIME();
                    hilfszeiger = akt;
                }
                akt=akt->get_next();
            }
            ProcList.remove(hilfszeiger);
            return hilfszeiger;
        }
    }
    else {
        return NULL;
    }
}

