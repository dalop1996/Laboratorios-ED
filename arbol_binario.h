#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dato.h>
#include <nodo.h>
#include <time.h>

typedef Nodo Abb;


//Prototipos funciones interfaz
Abb *iniciaAbb(void);
Abb *agregaDatoAbb(Abb **ptrArbol, Palabra plbr);
Nodo *encuentraValorAbb(Abb *ptrArbol, Palabra plbr);
Nodo *encuentraMinAbb(Abb *ptrArbol);
Nodo *encuentraMaxAbb(Abb *ptrArbol);
void muestraAbb(Abb *ptrArbol);
void vaciaAbb(Abb *ptrArbol);
Abb *eliminaDatoAbb(Abb **ptrArbol, Palabra plbr);
void insertar(Abb ** raizABB, Palabra plbr, int largo )


int contador(Abb* raizABB){
	if(raizABB == NULL){
		return 0 ;
	}
	return (1 +contador( *raizABB->izq) +contador(raizABB->der));
}
Abb *nodoRandom()



//??
Abb *iniciaAbb(){
	return();
}

void insertar(Abb ** raizABB, Palabra plbr, int largo ){
	if(strlen(plbr)!=largo){
		return;
	}
	Abb* newNodo = iniciaNodo( plbr);

	if(*raizABB == NULL){
		*raizABB = newNodo;
	}else{
		Abb* actual = *raizABB;
		Abb* padre = NULL;
		while(largo){
			padre = actual;
			if(strcmp(plbr,actual->plbr)<0){
				actual = actual->izq;
				if(actual == NULL){
					padre ->izq = newNodo;
					return;
				}
			}else{
				actual = actual->der;
				if(actual == NULL){
					padre->der = newNodo;
					return;
				}
			}
		}
	}
}

/*
 Abb *agregaDatoAbb(Abb** ptrArbol, Palabra plbr){
	if (*ptrArbol == NULL) { //arbol vacio y/o lugar de inserción encontrado
		*ptrArbol = iniciaNodo(plbr);
	}else {
		if (strcmp(plbr, (*ptrArbol)->plbr) < 0 ) {//moverse a la izquierda
			*ptrArbol->izq = agregaDatoAbb(&((*ptrArbol)->izq), plbr);
		}else if (plbr > *ptrArbol->data) {//moverse a la derecha
			*ptrArbol->der = agregaDatoAbb(&((*ptrArbol)->der), plbr);
		}
		//si ya está en el arbol no hacemos nada
	}
	return(*ptrArbol);
}
*/

Nodo *encuentraValorAbb(Abb *ptrArbol, Palabra plbr){
	Nodo *ptrAux = NULL;
	if (ptrArbol == NULL) { //el árbol está vacío o el elemento no está
		return(NULL);
	}
	else if (strcmp(plbr, ptrArbol->plbr) == 0) { //se encontró hoja con valor mínimo
		return(ptrArbol);
	}else if(strcmp(plbr, ptrArbol ->plbr) < 0 ){
		return(encuentraMinAbb(ptrArbol->izq));
	}else{
		return(encuentraMaxAbb(ptrArbol->der));
	}
}

Nodo *encuentraMinAbb(Abb *ptrArbol){
	if (ptrArbol == NULL) { //el árbol está vacío
		return(NULL);
	}else if (ptrArbol->izq == NULL) { //se encontró hoja con valor minimo
		return(ptrArbol);
	}else {
		return(encuentraMinAbb(ptrArbol->izq));
	}
	
}

Nodo *encuentraMaxAbb(Abb *ptrArbol){
	if (ptrArbol == NULL) { //el árbol está vacío
		return(NULL);
	}else if (ptrArbol->der == NULL) { //se encontró hoja con valor máximo
		return(ptrArbol);
	}else {
		return(encuentraMaxAbb(ptrArbol->der));
	}	
}
//Recorrido en orden
void muestraAbb(Abb *ptrArbol){
	if (ptrArbol != NULL) {
		muestraAbb(ptrArbol->izq);
		mostrar(ptrArbol); //falta hacer
		printf("%s ",ptrArbol->plbr);
		muestraAbb(ptrArbol->der);		   
	}
}

void vaciaAbb(Abb *ptrArbol){
	if (ptrArbol != NULL) {
		vaciaAbb(ptrArbol->izq);
		vaciaAbb(ptrArbol->der);		   
		eliminar_nodo(ptrArbol);
	}	
}

Abb *eliminaDatoAbb(Abb *ptrArbol, Palabra plbr){
	Nodo *ptrAux = NULL;
	if(ptrArbol == NULL){//si ptrArbol == NULL el arbol esta vacio o el elemento no se encontro
		return(NULL);
	}
	//el elemento se ha encontrado
	//tiene dos hijos
	//reemplazar con el menor de los mayores
	else if(plbr < ptrArbol->plbr){
		 //ir a borrar el nodo con que se reemplazo el valor original
		ptrArbol ->izq = eliminaDatoAbb(ptrArbol->izq,plbr);

	}else if(plbr > ptrArbol->plbr){
		ptrArbol ->der = eliminaDatoAbb(ptrArbol->der,plbr);
	}
	// 1 o 0 hijos (raiz?)
	else{
		if (ptrArbol->izq == NULL) {
			ptrAux = ptrArbol->der;
			eliminar_nodo(ptrArbol);
			return(ptrAux);
		}
		else if (ptrArbol->der == NULL) {
			ptrAux = ptrArbol->izq;
			eliminar_nodo(ptrArbol);
			return(ptrAux);
	}
	return(ptrArbol);
}