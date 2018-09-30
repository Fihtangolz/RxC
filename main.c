#include <printf.h>
#include <stdlib.h>
#include <memory.h>

#include "src/observer.h"

//
//PROTOTYPE((test),
//  int b;
//  int k;
//);
//
//PROTOTYPE((test2)(test),
//  int b;
//  int k;
//);

int main(){
//    INST_OF(test,t1,t2,t3);
//    source_t pl1 = observable.timer(&(struct timespec){.tv_sec = 60});
//    source_t pl2 = observable.timer(&(struct timespec){.tv_sec = 60});

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

    source.debounce(&source)
        ->distinct(&source)
        ->element_at(&source)
        ->filter(&source)
        ->first(&source)
        ->ignore_elements(&source)
        ->last(&source)
        ->sample(&source)
        ->skip(&source)
        ->skip_last(&source)
        ->take(&source)
        ->take_last(&source);


    source_t* s = source.debounce(
                        source.distinct(
                                source.element_at(
                                        source.filter(&source)
                                )));

    return EXIT_SUCCESS;
}
