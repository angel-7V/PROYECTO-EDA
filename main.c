#include <stdio.h>
#include <stdlib.h>

#include "tienda.h"

#define MENUSALIR 3
#define INVENTARIOSALIR 4
#define CLIENTESALIR 8

int main() {

    clist list = initTienda();


    book auxBook;


    int menu, submenu, indice, modo, opcion;

    do{
        printf("\n\t Menu");
        printf("\n\t 1.- Manejo de inventario.");
        printf("\n\t 2.- Cliente en tienda.");
        printf("\n\t 3.- Salir.");
        printf("\n\n\t Ingrese numero de opcion y presione ENTER: ");
        scanf("%d", &menu);
        switch (menu){
            case 1:
                do{
                    printf("\n\n\t Manejo de inventario.");
                    printf("\n\t 1.- Agregar libros a la venta.");
                    printf("\n\t 2.- Dar de baja un libro.");
                    printf("\n\t 3.- Agregar existencias de un libro.");
                    printf("\n\t 4.- Regresar al menu principal.");
                    printf("\n\n\t Ingrese numero de opcion y presione ENTER: ");
                    scanf("%d", &submenu);
                    switch (submenu){
                        case 1:
                            addBook(list);
                            break;
                        case 2:
                            if(deleteBook(list)){
                                printf("\n\n\t Libro eliminado exitosamente. \n");
                            }else{
                                printf("\n\t Error :(");
                            }
                            break;
                        case 3:
                            if((indice = addBookQuant(list)) != -1){
                                printf("\n\n\t Cantidad agregada exitosamente. \n");
                                printByIndex(list, indice);
                            }else{
                                printf("\n\t Error :(");
                            }
                            break;
                        case INVENTARIOSALIR:
                            break;
                        default:
                            printf("\n\t Opcion no valida.");
                            break;
                    }
                }while (submenu != INVENTARIOSALIR);
                break;
            case 2:

                do{
                    printf("\n\n\t Libreria EDA");
                    printf("\n\n\t Menu cliente");
                    printf("\n\t 1.- Mostrar lista de libros.");
                    printf("\n\t 2.- Recorrer libros individualmente.");
                    printf("\n\t 3.- Busqueda de libros.");
                    printf("\n\t 4.- Agregar libros al carrito.");
                    printf("\n\t 5.- Sacar libro del carrito.");
                    printf("\n\t 6.- Ver carrito.");
                    printf("\n\t 7.- Confirmar compra.");
                    printf("\n\t 8.- Regresar al menu principal.");
                    printf("\n\n\t Ingrese numero de opcion y presione ENTER: ");
                    scanf("%d", &submenu);
                    switch (submenu){
                        case 1:
                            printf("\n\n\t Opciones: ");
                            printf("\n\t 1.- Imprimir hacia adelante.");
                            printf("\n\t 2.- Imprimir hacia atras.");
                            printf("\n\n\t Ingrese numero de opcion y presione ENTER: ");
                            scanf("%d", &opcion);
                            printClist(list, opcion);
                            break;
                        case 2:
                            traverseBooks(list);
                            break;
                        case 3:
                            indice = searchMenu(list);
                            break;
                        case 4:
                            if(addToCart(list)){
                                displayS();
                            }else{
                                printf("\n\t Error :(");
                            }
                            break;
                        case 5:
                            auxBook = pop();
                            if(auxBook.ISBN != -1){
                                printf("\n\t Libro sacado del carrito: \n");
                                printBook(auxBook);
                            }else{
                                printf("\n\t Error :(");
                            }
                            break;
                        case 6:
                            displayS();
                            break;
                        case 7:
                            if(!stackToQueue()){
                                printf("\n\t Error :( ");
                            }else{
                                printf("\n\t Informacion de las compras: ");
                                displayQ();
                                printf("\n\t Imprimiendo ticket...");
                                printf("\n\n\n");
                                ticket(list);
                            }
                            break;
                        case CLIENTESALIR:
                            break;
                        default:
                            printf("\n\t Opcion no valida.");
                            break;
                    }
                }while(submenu != CLIENTESALIR);
                while (!isEmptyStack()){
                    auxBook = pop();
                }
                break;
            case MENUSALIR:
                if(saveChanges(list)){
                    printf("\n\t Cambios guardados con exito.");
                }
                printf("\n\t ADIOS! :)");
                break;
            default:
                printf("\n\t Opcion no valida.");
                break;
        }

    }while (menu != MENUSALIR);

    return 0;
}