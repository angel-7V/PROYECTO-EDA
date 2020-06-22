// PROYECTO EDA

#ifndef FINALEDA_NODED_H
#define FINALEDA_NODED_H

#include "book.h"

typedef struct _nodeD *nodeD;

struct _nodeD{
    book libro;
    nodeD prev;
    nodeD next;
    int index;
};

typedef struct _node *node;

struct _node{
    book libro;
    node next;
};

nodeD createNodeD(book libro);

node createNode(book libro);

#endif //FINALEDA_NODED_H
