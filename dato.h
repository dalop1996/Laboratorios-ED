#include <stdio.h>
#include <stdlib.h>

typedef char *Palabra;

int muestraPalabra(Palabra plbr);

int muestraPalabra(Palabra plbr){
    return(printf("%s",plbr));
}
