#include <stdio.h>
#include <stdlib.h>
#include <dato.h>

typedef struct abbNodo{
    Palabra plbr;
    struct abbNodo *izq, *der;
}Nodo;

//Inicia nodo ABB 
Nodo *iniciaNodo(Palabra plbr){
	Nodo *auxNodo = (Nodo *)malloc(sizeof (Nodo));
	if (auxNodo != NULL) {
		auxNodo->plbr = plbr; //Falta indentificador para palabra usada
		auxNodo->izq = NULL;
		auxNodo->der = NULL;
	}
	return(auxNodo);
} 


//Agrega una palabra al nodo
 Nodo* insertar( Nodo* raiz, char* palabra) {
    if (raiz == NULL) {
        return iniciaNodo(palabra);
    }
    if (strcmp(palabra, raiz->plbr) < 0) {
        raiz->izq = insertar(raiz->izq, palabra);
    } else if (strcmp(palabra, raiz->plbr) > 0) {
        raiz->der = insertar(raiz->der, palabra);
    }
    return raiz;
}



//Busca la hoja con el menor valor 
 Nodo* minimoValor(Nodo* nodo) {
    Nodo* actual = nodo;
    while (actual && actual->izq != NULL) {
        actual = actual->izq;
    }
    return actual;
}

void mostrar(Nodo *nodo){
    if(nodo!=NULL){
        printf("%d",nodo->plbr);
        mostrar(nodo->izq);
        mostrar(nodo->der);
    }
}



//Elimina un nodo
 Nodo* eliminar( Nodo* raiz, char* palabra) {
    if (raiz == NULL) {
        return raiz;  //No tiene hijos o estos ya han sido eliminados
    }
    if (strcmp(palabra, raiz->plbr) < 0) {
        raiz->izq = eliminar(raiz->izq, palabra);
    } else if (strcmp(palabra, raiz->plbr) > 0) {
        raiz->der = eliminar(raiz->der, palabra);
    } else {
        if (raiz->izq == NULL) {
             Nodo* temp = raiz->der;
            free(raiz);
            return temp;
        } else if (raiz->der == NULL) {
             Nodo* temp = raiz->izq;
            free(raiz);
            return temp;
        }
         Nodo* temp = minimoValor(raiz->der);
        strcpy(raiz->plbr, temp->plbr);
        raiz->der = eliminar(raiz->der, temp->plbr);
    }
    //free(raiz);
    //eliminar_nodo(raiz);
    return (raiz);
}


void eliminar_nodo(Nodo*nodo){
    free(nodo);
}



