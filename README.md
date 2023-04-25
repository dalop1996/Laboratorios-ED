# Laboratorios-ED
Estructura de Datos 2023 Primer Semestre


*Laboratorio 25/04/2023

 !)Arbol Binario de Busqueda:
  -Crea ABB ---> *ABB
  -Elimina ABB ---> *ABB ---> int
  -Agregar Numero ABB ---> *ABB , numero ---> *ABB
  -Buscar Numero ABB ---> *ABB, numero ---> int pos
  -Eliminar Numero ABB ---> *ABB, numero ---> *ABB, int
  
  Tipo de estructura:
    typedef struct _abb{
      int dato;
      struct _abb* hijoizq;
      struct _abb* hijoder;
      }ABB;
  
  
  Ejemplo de recorreABB:
    void recorreABB(ABB * unAbb){
      if (unAbb!= NULL){
        recorreABB(unAbb -> hijoizq);
        prntf("%d", unAbb -> dato);
        recorreABB(unAbb -> hijoder);
       }
      }
