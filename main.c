#include <printf.h>
#include <stdlib.h>
#include <memory.h>

#include "src/c_lambda.h"
#include "src/rxc_creating.h"
#include "src/reflection.h"

RT_REFLECT(test,
    int b;
    int k;
)

RT_REFLECT(test2,
    int b;
    int k;
)

int main(){
//    int a = 42;
//    int b = !42;
//    char* f = "SOME";
////    LAMBDA((int,a)(int,b)(char,f),(int c, int k),{
////
////    });
//
//    void (^fg)() = ^{
//        for (int i = 0; i < 100; i++)
//            printf("%d\n", i);
//    };
//    fg();

//    observable.timer(&(struct timespec){.tv_nsec = 12});
    typeof(test) t1;
    memcpy(&test,&t1,sizeof(test));
    if(is_instance(&test, &t1)){
        printf("YOS");
    }else{
        printf("NO");
    }
    return EXIT_SUCCESS;
}
