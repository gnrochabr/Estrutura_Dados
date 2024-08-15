#include <stdio.h>
void incrementar(int *p);

int main(){
    int v = 0;
    int *p = &v;
    int vt[3] = {10,20,30};
    int *vtp = vt;
    printf("%d ",*(vtp+*p));
    incrementar(p);
    printf("%d ",*(vtp+*p));
    incrementar(p);
    printf("%d",*(vtp+*p));

    return 0;
}

void incrementar(int *p){
    (*p)++;
}