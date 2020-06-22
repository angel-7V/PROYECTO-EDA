//PROYECTO EDA

#ifndef FINALEDA_TIENDA_H
#define FINALEDA_TIENDA_H

#include "cdll.h"
#include "stack.h"
#include "queue.h"


clist initTienda();


bool addBook(clist list);

int addBookQuant(clist list);

int searchMenu(clist list);

bool deleteBook(clist list);

book obtainBook(clist list);

bool addToCart(clist list);

bool stackToQueue();

void ticket(clist list);

void printBookForTicket(book libro);

bool checkAndReduce(clist list, book libro);

bool saveChanges(clist list);

#endif //FINALEDA_TIENDA_H
