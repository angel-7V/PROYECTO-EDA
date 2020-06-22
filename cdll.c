//PROYECTO EDA

#include "cdll.h"
#include <stdio.h>
#include <stdlib.h>

clist createClist(){ 
    clist c;
    c = (clist) malloc(sizeof(struct _cdll));
    c->head = NULL;
    c->num = 0;
    return c;
}

bool addInitClist(clist list, book libro){
    nodeD ptr = createNodeD(libro);
    nodeD temp;

    if(list->head == NULL){//Lista vacia
        list->head = ptr;
        ptr->next = list->head;
        ptr->prev = list->head;
        list->head->index = 1;
        return true;
    }else{
        temp = list->head;
        while (temp->next != list->head){
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
        list->head->prev = ptr;
        ptr->next = list->head;
        ptr->index = list->head->index;
        list->head = ptr;
        list->head->index = list->head->index +1;
        return true;
    }
    return false;
}

bool loadBooks(clist list){

    book aux;

    FILE *ptr;

    if(( ptr = fopen("libros.txt", "r")) == NULL){
        printf("\n\t Error al abrir el archivo.");
        return false;
    }

    while (fgets(aux.titulo, MAX, ptr) != NULL){
        removeLineBreak(aux.titulo);
        fgets(aux.autor, MAX, ptr);
        removeLineBreak(aux.autor);
        fgets(aux.editorial, MAX, ptr);
        removeLineBreak(aux.editorial);
        fscanf(ptr, "%lli\n", &aux.ISBN);
        fgets(aux.formato, MAX, ptr);
        removeLineBreak(aux.formato);
        fscanf(ptr, "%d\n", &aux.cantidad);
        fscanf(ptr, "%f\n", &aux.precio);

        addInitClist(list, aux);

    }

    fclose(ptr);
    return true;

}

void printClist(clist list, int mode){

    nodeD temp = list->head;

    printf("\n");

    if (mode == forward){
        while (temp->next != list->head){
            printBook(temp->libro);
            printf("\n\t Index: %d \n", temp->index);
            temp = temp->next;
        }
        printBook(temp->libro);
        printf("\n\t Index: %d \n", temp->index);
    }else if(mode == backward){
        while (temp->prev != list->head){
            temp = temp->prev;
             printBook(temp->libro);
            printf("\n\t Index: %d \n", temp->index);
        }
        temp = temp->prev;
        printBook(temp->libro);
        printf("\n\t Index: %d", temp->index);
    }
}

void traverseBooks(clist list){

    nodeD ptr = list->head;
    int menu;

    printf("\n\t Libro actual: ");
    printBook(ptr->libro);

    do{
        printf("\n\n\t 1.- Ver libro anterior.");
        printf("\n\t 2.- Ver libro siguiente.");
        printf("\n\t 3.- Salir.");
        printf("\n\n\t Ingrese numero de opcion y presione ENTER: ");
        scanf("%d", &menu);
        //menu++;
        switch (menu){
            case backward:
                ptr = ptr->prev;
                printBook(ptr->libro);
                break;
            case forward:
                ptr = ptr->next;
                printBook(ptr->libro);
                break;
            case exittraverse:
                break;
            default:
                printf("\n\t Opcion no valida.");
                break;
        }
    }while (menu != 3);

}

int searchBook(clist list, int mode){

    int index = -1;
    long long int ISBN;
    char aux1[MAX], aux2[MAX];
    book auxBook;

   // printf("Modo: %d", mode);

    nodeD temp = list->head;

    getchar();

    switch (mode){
        case porTitulo:  //Busqueda por Libro 
            printf("\n\t Ingrese titulo del libro a buscar: ");
            fflush(stdin);
            fgets(aux1, MAX, stdin);
            removeLineBreak(aux1);
            lowercase(aux1);
            printf("\n\t %s", aux1);
            while (temp->next != list->head){
                auxBook = temp->libro;
                strcpy(aux2, auxBook.titulo);
                lowercase(aux2);
                if(strcmp(aux1, aux2) == 0){
                    return temp->index;
                }
                temp = temp->next;
            }
            auxBook = temp->libro;
            strcpy(aux2, auxBook.titulo);
            lowercase(aux2);
            if(strcmp(aux1, aux2) == 0){
                return temp->index;
            }
            break;
        case porAutor:  //Busqueda por Autor
            printf("\n\t Ingrese autor del libro a buscar: ");
            fflush(stdin);
            fgets(aux1, MAX, stdin);
            removeLineBreak(aux1);
            lowercase(aux1);
            while (temp->next != list->head){
                auxBook = temp->libro;
                strcpy(aux2, auxBook.autor);
                lowercase(aux2);
                if(strcmp(aux1, aux2) == 0){
                    return temp->index;
                }
                temp = temp->next;
            }
            auxBook = temp->libro;
            strcpy(aux2, auxBook.autor);
            lowercase(aux2);
            if(strcmp(aux1, aux2) == 0){
                return temp->index;
            }
            break;
        case porISBN: //Busqueda por ISBN
            printf("\n\t Ingrese ISBN del libro a buscar: ");
            scanf("%lli", &ISBN);
            while (temp->next != list->head){
                if(ISBN == temp->libro.ISBN){
                    return temp->index;
                }
                temp = temp->next;
            }
            if(ISBN == temp->libro.ISBN){
                return temp->index;
            }
            break;
        default:
            printf("\n\t Opcion no valida.");
            index = -1;
            break;
    }

    return index;

}

void printByIndex(clist list, int index){

    nodeD temp = list->head;

    while (temp->next != list->head){
        if(temp->index == index){
            printBook(temp->libro);
            return;
        }
        temp = temp->next;
    }
    if(temp->index == index){
        printBook(temp->libro);
        return;
    }
}