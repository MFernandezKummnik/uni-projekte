#include <stdlib.h>
#include <stdio.h>
#include "struct.h"



static knoten *head = NULL; 
static knoten *tail = NULL;



void vorneEinfuegen(process daten){
knoten *neu = malloc(sizeof(knoten));
if (neu == NULL){
    return;
}
neu->daten = daten;
neu->next = head;
head = neu;
}

void alleAusgeben(void){
    knoten *akt = head;
    while (akt != NULL){
        printf("%d\n", akt->daten.pid);
        akt = akt->next;
    }
}
void myNewProcess(process a){
    knoten *neu = malloc(sizeof(knoten));
    if(neu == NULL){
        return;
    }
    neu->daten=a;
    neu->next =NULL;
    if (head==NULL) {
        head = neu;
        tail=neu;
    }
    else {
        tail->next = neu;
        tail=neu; 
    }
}
process mySchedule(int a){
    if(head ==NULL){
        process leer = {0,0};
        return leer;
    }
    if(a==0){
        process copy = head->daten;
        knoten *hilfszeiger =head;
        head = head->next;
        free(hilfszeiger);
        return copy;

    }
    else{
        knoten *akt = head;
        knoten *fastest = akt;
        knoten *vorfastest =NULL;
        int compare = akt->daten.time;
    while (akt != NULL && akt->next != NULL){
        
        if(compare > akt->next->daten.time){
            compare = akt->next->daten.time;
            fastest = akt->next;
            vorfastest = akt;
            akt =akt->next;
        }
        else{
        akt = akt->next;
        }
    }
    process copy = fastest->daten;
    if(vorfastest == NULL){
        head = head->next;
        free(fastest);
        return copy;
    }
    else if(fastest->next == NULL){
        tail = vorfastest;
        vorfastest->next =NULL;
        free(fastest);
        return copy;
    }
    else{
        vorfastest->next = fastest->next;
        free(fastest);
        return copy;
    }

    }
}