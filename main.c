#include <printf.h>
#include <stdlib.h>
#include <memory.h>

#include "src/c_lambda.h"
#include "src/rxc_creating.h"
#include "src/c_prototype.h"

PROTOTYPE((test),
  int b;
  int k;
);

PROTOTYPE((test2)(test),
  int b;
  int k;
);

int main(){
    INST_OF(test,t1,t2,t3);
//    printf("%d %d \n", sizeof(&test), sizeof(&t1));
//    printf("%s\n",rt_typeof(&t1));
//    printf("%s\n",rt_typeof(&t2));
//    printf("%s\n",rt_typeof(&t3));
//
//    if(is_same_type(&t1,&t2,&t3,NULL)){
//        printf("TRUE");
//    }else{
//        printf("FALSE");
//    }

    return EXIT_SUCCESS;
}
