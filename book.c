//PROYECTO EDA

#include "book.h"
#include <stdlib.h>
#include <stdio.h>


book newBook(){
    book temp;
    printf("\n\t Ingrese titulo del libro: ");
    fflush(stdin);
    fgets(temp.titulo, MAX, stdin);
    removeLineBreak(temp.titulo);
    printf("\n\t Ingrese autor del libro: ");
    fflush(stdin);
    fgets(temp.autor, MAX, stdin);
    removeLineBreak(temp.autor);
    printf("\n\t Ingrese editorial del libro: ");
    fflush(stdin);
    fgets(temp.editorial, MAX, stdin);
    removeLineBreak(temp.editorial);
    printf("\n\t Ingrese ISBN del libro: ");
    scanf("%lli", &temp.ISBN);
    getchar();
    printf("\n\t Ingrese formato del libro: ");
    fflush(stdin);
    fgets(temp.formato, MAX, stdin);
    removeLineBreak(temp.formato);
    printf("\n\t Ingrese cantidad en existencia del libro: ");
    scanf("%d", &temp.cantidad);
    printf("\n\t Ingrese precio del libro: ");
    scanf("%f", &temp.precio);
    return temp;
}

void printBook(book libro){
    printf("\n\t Titulo: %s", libro.titulo);
    printf("\n\t Autor: %s", libro.autor);
    printf("\n\t Editorial: %s", libro.editorial);
    printf("\n\t ISBN: %lli", libro.ISBN);
    printf("\n\t Formato: %s", libro.formato);
    printf("\n\t Cantidad en existencia: %d", libro.cantidad);
    printf("\n\t Precio: %6.2f", libro.precio);
}


bool modifyQuant(book *libro, int mode, int quantity){

    if(mode == disminuir){
        if(libro->cantidad <= 0){
            printf("\n\t No hay libros en existencia.");
            printf("\n\t No se puede disminuir esa cantidad.\n");
            return false;
        }else if(libro->cantidad - quantity < 0){
            printf("\n\t No se pueden vender esa cantidad de libros.");
            printf("\n\t Falta(n) %d libro(s) para completar la transaccion.\n", (libro->cantidad - quantity) *-1 );
            return false;
        }else{
            libro->cantidad -= quantity;
            return true;
        }
    }else if (mode == aumentar){
        libro->cantidad += quantity;
        return true;
    }
    printf("\n\t Error en funcion modifyQuant.");
    return false;
}

