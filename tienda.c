//PROYECTO EDA

#include "tienda.h"
#include <stdlib.h>
#include <stdio.h>

clist initTienda(){
    clist list = createClist();
    if(loadBooks(list)){
        printf("\n\t Archivos cargados con exito.");
        return list;
    }else{
        printf("\n\t Error al cargar archivo.");
        return false;
    }
}

bool addBook(clist list){
    getchar(); 
    book libro = newBook();
    if(addInitClist(list, libro)){
        printf("\n\t Libro agregado con exito");
        return true;
    }else{
        return false;
    }
}


int addBookQuant(clist list) {

    int index;
    int cant;

    nodeD temp = list->head;

    printf("\n\t Busqueda para agregar existencias al respectivo libro.");

    index = searchMenu(list);

    
    if(index != -1){

        printf("\n\n\t Ingrese la cantidad de libros a agregar: ");
        scanf("%d", &cant);

        while (temp->next != list->head){
            if(temp->index == index){
               // printf("\n\t Test");
               // printBook(temp->libro);//Comentar despues de probar
                modifyQuant(&temp->libro, aumentar, cant);
               // printBook(temp->libro);//Comentar despues de probar
               // printByIndex(list, index);//Comentar despues de probar
                return index;
            }
            temp = temp->next;
//            if(temp->index == index){
//                modifyQuant(&temp->libro, aumentar, cant);
//                return index;
//            }
        }
        if(temp->index == index){
            modifyQuant(&temp->libro, aumentar, cant);
            return index;
        }
    }

        printf("\n\t Error.");
        return -1;


}


bool deleteBook(clist list){
    int index;
    nodeD temp = list->head;

    printf("\n\t Busqueda para eliminar libro respectivo.");

    index = searchMenu(list);


    if(index != -1){
        while(temp->next != list->head){
            if(temp->index == index){
                nodeD prevNode = temp->prev;
                nodeD nextNode = temp->next;
                prevNode->next = temp->next;
                nextNode->prev = temp->prev;
                prevNode->index--;
                free(temp);
                return true;
            }
            temp = temp->next;
        }
        if(temp->index == index){
            nodeD prevNode = temp->prev;
            nodeD nextNode = temp->next;
            prevNode->next = temp->next;
            nextNode->prev = temp->prev;
            prevNode->index--;
            free(temp);
            return true;
        }
    }
    printf("\n\t Error.");
    return false;
}

book obtainBook(clist list){
    int index;
    nodeD temp = list->head;
    book auxBook;
    auxBook.ISBN = -1;

    printf("\n\t Busqueda de libro para agregar al carrito.");

    index = searchMenu(list);

    if(index != -1){
        while(temp->next != list->head){
            if(temp->index == index){
                auxBook = temp->libro;
                return auxBook;
            }
            temp = temp->next;
        }
        if(temp->index == index){
            auxBook = temp->libro;
            return auxBook;
        }
    }

    return auxBook;

    printf("\n\t Error.");

}



int searchMenu(clist list){

    int index, modo;

    printf("\n\n\t Menu de busqueda: ");
    printf("\n\t 1.- Busqueda por titulo.");
    printf("\n\t 2.- Busqueda por autor.");
    printf("\n\t 3.- Busqueda por ISBN.");
    printf("\n\n\t Ingrese numero de opcion y presione ENTER: ");
    scanf("%d", &modo);

    index = searchBook(list, modo);

    if(index != -1){
        printByIndex(list, index);
    }else{
        printf("\n\t Error en busqueda");
    }


    return index;


}

bool addToCart(clist list){

    book auxBook = obtainBook(list);

    if(auxBook.ISBN != -1){
        push(auxBook);
        printf("\n\t Libro agregado al carrito. \n");
        return true;
    }else{
        return false;
    }

}

bool stackToQueue(){

    if(isEmptyStack()){
        printf("\n\t Carrito vacio.");
        return false;
    }

    while (!isEmptyStack()){
        insert(pop());
    }

    while (!isEmptyQueue()){
        push(extract());
    }

    while (!isEmptyStack()){
        insert(pop());
    }

    return true;
}

void ticket(clist list){
    float total=0;
    book auxBook;
    printf("\n\t Libreria EDA");
    printf("\n\t -----------------------------------");
    while (!isEmptyQueue()){
        auxBook=extract();

        if(checkAndReduce(list, auxBook)){
            printBookForTicket(auxBook);
            total += auxBook.precio;
        }else{
            printf("\n\t No hay existencias del libro: ");
            printBookForTicket(auxBook);
        }
    }
    printf("\n\n\t Total de compra: %6.2f", total);
    printf("\n\n\t Muchas gracias por su visita!");
}

void printBookForTicket(book libro){

    printf("\n\n\t Titulo: %s", libro.titulo);
    printf("\n\t Autor: %s", libro.autor);
    printf("\n\t Editorial: %s", libro.editorial);
    printf("\n\t ISBN: %lli", libro.ISBN);
    printf("\n\n\t Precio: $%6.2f \n", libro.precio);
    printf("\n\t -----------------------------------");

}

bool checkAndReduce(clist list, book libro){

    nodeD temp = list->head;

    while(temp->next != list->head){
        if(libro.ISBN == temp->libro.ISBN){
            if(temp->libro.cantidad > 0){
                temp->libro.cantidad--;
                return true;
            }
        }
        temp = temp->next;
    }
    if(libro.ISBN == temp->libro.ISBN){
        if(temp->libro.cantidad > 0){
            temp->libro.cantidad--;
            return true;
        }
    }

    return false;


}

bool saveChanges(clist list){

    book auxBook;
    nodeD temp = list->head;

    FILE *ptr;

    if((ptr = fopen("libros.txt", "w")) == NULL){
        printf("\n\n\t Error en la actualizacion del archivo.");
        return false;
    }


    while (temp->next != list->head){

        auxBook = temp->libro;

        fprintf(ptr, "%s\n", auxBook.titulo);
        fprintf(ptr, "%s\n", auxBook.autor);
        fprintf(ptr, "%s\n", auxBook.editorial);
        fprintf(ptr, "%lli\n", auxBook.ISBN);
        fprintf(ptr, "%s\n", auxBook.formato);
        fprintf(ptr, "%d\n", auxBook.cantidad);
        fprintf(ptr, "%f\n", auxBook.precio);

        temp = temp->next;

    }
    auxBook = temp->libro;

    fprintf(ptr, "%s\n", auxBook.titulo);
    fprintf(ptr, "%s\n", auxBook.autor);
    fprintf(ptr, "%s\n", auxBook.editorial);
    fprintf(ptr, "%lli\n", auxBook.ISBN);
    fprintf(ptr, "%s\n", auxBook.formato);
    fprintf(ptr, "%d\n", auxBook.cantidad);
    fprintf(ptr, "%f\n", auxBook.precio);

    fclose(ptr);

    return true;

}