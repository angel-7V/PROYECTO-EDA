// PROYECTO EDA

#ifndef FINALEDA_CDLL_H
#define FINALEDA_CDLL_H

#include "nodeD.h"

enum {nill, backward, forward, exittraverse};
enum {nill2, porTitulo, porAutor, porISBN};

typedef struct _cdll *clist;

struct _cdll{
    nodeD head;
    int num;//Puede no requerirse
};

clist createClist();

bool addInitClist(clist list, book libro);

bool loadBooks(clist list);

void printClist(clist list, int mode);

void traverseBooks(clist list);

int searchBook(clist list, int mode);

void printByIndex(clist list, int index);

#endif //FINALEDA_CDLL_H
