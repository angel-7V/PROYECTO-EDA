// PROYECTO EDA

#ifndef FINALEDA_QUEUE_H
#define FINALEDA_QUEUE_H

#include "nodeD.h"

node front, rear;

void insert(book libro);
book extract();
void displayQ();

bool isEmptyQueue();

#endif //FINALEDA_QUEUE_H
