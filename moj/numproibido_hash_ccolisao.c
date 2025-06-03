#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define hashN(v,M) ((618033*(unsigned)v)%M)
#define NULLItem -1
#define MaxCol 100
#define Item unsigned
#define Null(i) (i==NULLItem)

#define N 140000

Item *ht;

void HTinit(int maxItems){
    int tamHash = 2*maxItems;
    ht = malloc(tamHash*sizeof(Item));
    for (int i=0; i<tamHash; i++) ht[i] = NULLItem;
}

Item HTsearch(Item valor){
    int i = hash(valor,tamHash);
    while (ht[i] != valor) i++;
};

//inserir tratando colisoes
void HTinsert(Item item){
    int i = hashN(item,tamHash);
    while (!Null(ht[i])) ((i+1)%tamHash);
};

int main(){
    return 0;
}