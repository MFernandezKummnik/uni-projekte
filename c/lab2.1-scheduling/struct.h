#ifndef STRUCT_H_
#define STRUCT_H_
#include "process.h"

struct knoten {
process daten;
struct knoten *next;
};
typedef struct knoten knoten;
#endif