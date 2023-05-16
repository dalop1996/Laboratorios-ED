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
		auxNodo->plbr = plbr;
		auxNodo->izq = NULL;
		auxNodo->der = NULL;
	}
	return(auxNodo);
} 

/*
//Agrega una palabra al nodo
struct Nodo* insertar(struct Nodo* raiz, char* palabra) {
    if (raiz == NULL) {
        return crearNodo(palabra);
    }
    if (strcmp(palabra, raiz->palabra) < 0) {
        raiz->izq = insertar(raiz->izq, palabra);
    } else if (strcmp(palabra, raiz->palabra) > 0) {
        raiz->der = insertar(raiz->der, palabra);
    }
    return raiz;
}
*/


//Busca la hoja con el menor valor 
 Nodo* minimoValor(Nodo* nodo) {
    Nodo* actual = nodo;
    while (actual && actual->izq != NULL) {
        actual = actual->izq;
    }
    return actual;
}


/*
//Elimina un nodo
struct Nodo* eliminar(struct Nodo* raiz, char* palabra) {
    if (raiz == NULL) {
        return raiz;//No tiene hijos o estos ya han sido eliminados
    }
    if (strcmp(palabra, raiz->palabra) < 0) {
        raiz->izq = eliminar(raiz->izq, palabra);
    } else if (strcmp(palabra, raiz->palabra) > 0) {
        raiz->der = eliminar(raiz->der, palabra);
    } else {
        if (raiz->izq == NULL) {
            struct Nodo* temp = raiz->der;
            free(raiz);
            return temp;
        } else if (raiz->der == NULL) {
            struct Nodo* temp = raiz->izq;
            free(raiz);
            return temp;
        }
        struct Nodo* temp = minimoValor(raiz->der);
        strcpy(raiz->palabra, temp->palabra);
        raiz->der = eliminar(raiz->der, temp->palabra);
    }
    return raiz;
}
*/





