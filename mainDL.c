#include <stdio.h>
#include <stdlib.h>

#include <dlfcn.h>

//extern int f1(int, int);
//extern int f2(int, int);

int main (int argc, char *argv[]){ //argv[1]=x, argv[2]=y, argv[3]=<func>

    void *ext_library;
    int (*dividefunc)(int x, int y);
    
    int n1,n2;
    
    //загрузка библиотеки
    ext_library = dlopen("./libdivide.so",RTLD_LAZY);
    if (!ext_library){
	//если ошибка, то вывести ее на экран
	fprintf(stderr, "dlopen() error: %s\n", dlerror());
	return 1;
    };

    dividefunc = dlsym(ext_library, argv[3]);

    //n1 = f1(atoi(argv[1]),atoi(argv[2]));
    //n2 = f2(atoi(argv[1]),atoi(argv[2]));
    
    //printf("f1() = %d\n", n1);
    //printf("f2() = %d\n", n2);

    printf("%s(%d,%d) = %d\n",argv[3],atoi(argv[1]),atoi(argv[2]),(*dividefunc)(atoi(argv[1]),atoi(argv[2])));

    dlclose(ext_library);
    
    return 0;
}