#include<stdio.h>

void fn(int* x, int* y){
    int* t = x;
    x=y;
    y=t;    

}
void newfn(int* x){
    int* t = x;
    printf("%d ", t);
}
int main(){
    int ar[5] = {1,2,3,4,5};
    int *p = ar;
    int *p1 = &ar[0];
    int *p2 = &ar[1];
   // printf("%u ", p);
    fn(p1, p2);
    newfn(p);
}