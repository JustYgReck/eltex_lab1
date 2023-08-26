#include <stdio.h>
#include <stdlib.h>

extern int f1(int, int);
extern int f2(int, int);

int main (int argc, char *argv[]){
    
    int n1,n2;
    
    n1 = f1(atoi(argv[1]),atoi(argv[2]));
    n2 = f2(atoi(argv[1]),atoi(argv[2]));
    
    printf("f1() = %d\n", n1);
    printf("f2() = %d\n", n2);
    
    return 0;
}