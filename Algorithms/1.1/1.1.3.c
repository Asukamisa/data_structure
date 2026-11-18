#include <stdio.h>

int main(){
    int a, b, c;
    scanf("%d %d %d", &a,&b,&c);
    if(a==b&&b==c)
        printf("equal\n");
    else
        printf("not equal\n");
    return 0;
}