// PROYECTO EDA

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>


void push(book libro){
    node ptr = createNode(libro);
    if(ptr == NULL){
        printf("\n\t No se pudo crear el nodo.");
    }else{
        if(head == NULL){
            ptr->next = NULL;
            head = ptr;
        }else{
            ptr->next = head;
            head = ptr;
        }
    }
}

book pop(){

    book auxBook;
    auxBook.ISBN = -1;

    if(head == NULL){
        printf("\n\t Carrito vacio.");
    }else{
        auxBook = head->libro;
        node ptr = head;
        head = head->next;
        free(ptr);
        return auxBook;
    }

    return auxBook;

}

void displayS(){
    node ptr = head;

    if(ptr == NULL){
        printf("\n\t Carrito vacio. ");
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

bool isEmptyStack(){
    return head == NULL;
}
