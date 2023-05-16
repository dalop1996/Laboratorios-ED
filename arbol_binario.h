#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dato.h>
#include <nodo.h>

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


Abb *iniciaAbb(){
	return(NULL);
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
	}else if(strcmp(plbr, ptrArbol ->plbr)) < 0 {
		return(encuentraMinAbb(ptrArbol->izq, plbr));
	}else{
		return(encuentraMaxAbb(ptrArbol->der, plbr));
	}
}

Nodo *encuentraMinAbb(Abb *ptrArbol){
	if (ptrArbol == NULL) { //el árbol está vacío
		return(NULL);
	}else if (ptrArbol->hijoIzq == NULL) { //se encontró hoja con valor minimo
		return(ptrArbol);
	}else {
		return(encuentraMinAbb(ptrArbol->hijoIzq));
	}
	
}

Nodo *encuentraMaxAbb(Abb *ptrArbol){
	if (ptrArbol == NULL) { //el árbol está vacío
		return(NULL);
	}else if (ptrArbol->hijoDer == NULL) { //se encontró hoja con valor máximo
		return(ptrArbol);
	}else {
		return(encuentraMaxAbb(ptrArbol->hijoDer));
	}	
}
//Recorrido en orden
void muestraAbb(Abb *ptrArbol){
	if (ptrArbol != NULL) {
		muestraAbb(ptrArbol->hijoIzq);
		muestraNodo(ptrArbol);
		printf("%s ",ptrArbol->data);
		muestraAbb(ptrArbol->hijoDer);		   
	}
}

void vaciaAbb(Abb *ptrArbol){
	if (ptrArbol != NULL) {
		vaciaAbb(ptrArbol->hijoIzq);
		vaciaAbb(ptrArbol->hijoDer);		   
		eliminaNodo(ptrArbol);
	}	
}

Abb *eliminaDatoAbb(Abb *ptrArbol, Dato unDato){
	Nodo *ptrAux = NULL;
	if(ptrArbol == NULL){//si ptrArbol == NULL el arbol esta vacio o el elemento no se encontro
		return(NULL);
	}
	//el elemento se ha encontrado
	//tiene dos hijos
	//reemplazar con el menor de los mayores
	else if(unDato < ptrArbol->data){
		 //ir a borrar el nodo con que se reemplazo el valor original
		ptrArbol ->hijoIzq = eliminaDatoAbb(ptrArbol->hijoIzq,unDato);

	}else if(unDato > ptrArbol->data){
		ptrArbol ->hijoDer = eliminaDatoAbb(ptrArbol->hijoDer,unDato);
	}
	// 1 o 0 hijos (raiz?)
	else{
		if (ptrArbol->hijoIzq == NULL) {
			ptrAux = ptrArbol->hijoDer;
			eliminaNodo(ptrArbol);
			return(ptrAux);
		}
		else if (ptrArbol->hijoDer == NULL) {
			ptrArbol = raiz->hijoIzq;
			eliminaNodo(ptrArbol);
			return(ptrAux);
	}
	return(ptrArbol);
}