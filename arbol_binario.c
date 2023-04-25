#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct _arbol{
    int dato;
    struct _arbol *hijoizq;
    struct _arbol *hijoder;
}ABB;

struct ABB *unABB(int dato){
    size_t tamano = malloc(sizeof ABB);
    struct ABB *nodo = (struct ABB *)malloc(tamano);

    nodo -> dato = dato;
    nodo ->izq = nodo -> der = NULL;
    
}

void recorreABB(ABB * unAbb){ 
    if (unAbb!= NULL){ 
        recorreABB(unAbb -> hijoizq); 
        prntf("%d", unAbb -> dato); 
        recorreABB(unAbb -> hijoder); 
    }
        
}