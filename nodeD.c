// PROYECTO EDA

#include "nodeD.h"
#include <stdlib.h>
#include <stdio.h>

nodeD createNodeD(book libro){
    nodeD p = (nodeD) malloc(sizeof(struct _nodeD));
    p->next = NULL;
    p->prev = NULL;
    p->libro = libro;
    p->index = -1;
    return p;
}

node createNode(book libro){
    node p = (node) malloc(sizeof(struct _node));
    p->libro = libro;
    return p;
}
