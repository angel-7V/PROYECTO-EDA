//PROYECTO EDA

#include "strings.h"
#include <stdlib.h>
#include <stdio.h>


void removeLineBreak(char arr[MAX]){
    size_t ln = strlen(arr)-1;
    if(arr[ln] == '\n')
        arr[ln] = '\0';
}

void lowercase(char arr[MAX]){
    for (int i = 0; arr[i]; ++i) {
        arr[i] = tolower(arr[i]);
    }
}

void stringDebug(char arr[MAX]){

    int l = strlen(arr);

    printf("\n\t Strlen: %d", l);

    for (int i = 0; i < l; ++i) {
        printf("\n\t [%d] : [%c] = [%d]", i, arr[i], arr[i]);
    }

    printf("\n\t String: %s", arr);

}

void removeLineBreakTXT(char arr[MAX]){
    arr[strlen(arr)-2] = '\0';
}