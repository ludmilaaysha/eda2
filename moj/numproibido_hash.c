#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 140000

int primo[N];

unsigned int hashN(unsigned int num, unsigned int mod){
    return num % mod;
}

void crivo(){
    for (int i=0; i<N; i++){
        primo[i] = 1;
    }

    primo[0] = primo[1] = 0;

    for (int p = 2; p * p <= N; p++) {
        if (primo[p]) {
            for (int multiple = p * p; multiple <= N; multiple += p) {
                primo[multiple] = 0;
            }
        }
    }
}

int buscaHash(unsigned int numero, int tam, unsigned int *arr){
    if (arr[hashN(numero, tam)] == numero){
        return 1;
    }

    return 0;
};


int main(){
    crivo();
    int i=0, t, b;
    unsigned int a;

    scanf("%d", &t);
    t = (t<<2) - 1;
    if (!primo[t]){
        while (primo[t] != 1 && t < N) t+=1;
    }

    unsigned int *v = malloc(t*sizeof(int));

    for (int i=0; i<t; i++) v[i] = -1;

    for (int i=0; i<t; i++){
        scanf("%u", &a);
        v[hashN(a, t)] = a;
    }

    while ((scanf("%u", &b)) == 1){
        if (buscaHash(b, t, v)) printf("sim\n");
        else if (!buscaHash(b, t, v)) printf("não\n");
        else printf("colisão!\n");
    };

    return 0;
}