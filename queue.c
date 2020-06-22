// PROYECTO EDA

#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

void insert(book libro){
    node ptr = createNode(libro);
    if(ptr == NULL){
        printf("\n\t No se pudo crear el nodo.");
    }else{
        if(front == NULL){
            front = ptr;
            rear = ptr;
            front->next = NULL;
            rear->next = NULL;
        }else{
            rear->next = ptr;
            rear = ptr;
            rear->next = NULL;
        }
    }

}

book extract(){
    book auxBook;
    auxBook.ISBN = -1;

    if(front == NULL){
        printf("\n\t Carrito vacio.");
    }else{
        node ptr = front;
        auxBook = ptr->libro;
        front = front->next;
        free(ptr);
    }
    return auxBook;
}

void displayQ(){
    node ptr = front;
    if(front == NULL){
        printf("\n\t Carrito vacio.");
    }else{
        printf("\n\t Carrito: ");
        while(ptr != NULL){
            printf("\n");
            printBook(ptr->libro);
            printf("\n");
            ptr = ptr->next;
        }
    }
}

bool isEmptyQueue(){
    return front == NULL;
}
