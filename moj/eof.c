#include <stdio.h>

int main(){
    int i = 0, a;

    // scanf("%d", &a);

    while (scanf("%d", &a) != EOF){
        i += 1;
    };

    printf("%d\n", i);

    return 0;
}