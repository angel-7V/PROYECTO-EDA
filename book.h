//PROYECTO EDA

#ifndef FINALEDA_BOOK_H
#define FINALEDA_BOOK_H

#define MAX 255

#include <stdbool.h>
#include "strings.h"

enum {disminuir, aumentar};

typedef struct _book{
    char titulo[MAX];
    char autor[MAX];
    char editorial[MAX];
    long long int ISBN;
    char formato[MAX];
    int cantidad;
    float precio;
}book;

book newBook();
void printBook(book libro);

bool modifyQuant(book *libro, int mode, int quantity);

#endif //FINALEDA_BOOK_H
