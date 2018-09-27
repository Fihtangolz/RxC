#include <printf.h>
#include <stdlib.h>
#include <memory.h>

#include "src/c_lambda.h"
#include "src/rxc_creating.h"
#include "src/c_prototype.h"

PROTOTYPE((test)(),
 int b;
 int k;
);

PROTOTYPE((test2),
    int b;
    int k;
);

int main(){
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

    INST_OF(test, t1);
    INST_OF(test2, ff);
    printf("%s\n",rt_typeof(&test));
    printf("%s\n",t1.type);
    printf("%s\n",ff.type);
    return EXIT_SUCCESS;
}
