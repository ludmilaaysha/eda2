#include <stdio.h>

int main(){
    int n, a, soma=0;

    scanf("%d", &n);

    for (int i=0; i<n; i++){
        scanf("%d", &a);
        soma += a;
    }

    printf("%d\n", soma);

    return 0;
}