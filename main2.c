#include <printf.h>
#include <stdlib.h>
#include <memory.h>
#include "stdbool.h"
#include "src/observer.h"
#include "src/creating/creating.h"
#include "src/c_prototype.h"

#include <callback.h>
#include "src/creating/creating.h"

bool prdc(void* f){
    return false;
}

IMPORT(source);

struct some {
    int p1;
    int p2;
    int p3;
    int p4;
};

static void emitter_(void* data, va_alist alist) {
    struct some* d = data;
    printf("rtr %d %d %d %d\n", d->p1, d->p2, d->p3, d->p4);
    d->p1+=10;
    d->p2+=10;
    d->p3+=10;
    d->p4+=10;
    va_start_int(alist);
    int t1 = va_arg_int(alist);
    int t2 = va_arg_int(alist);
    int t3 = va_arg_int(alist);
    int t4 = va_arg_int(alist);
    printf("call %d %d %d %d\n", t1, t2, t3, t4);
}

//TODO
//    source_t source = CALL_CHAINE(
//            observable_range,(1,3,1),
//            filter,(prdc),
//            filter,(prdc),
//            map,(prdc),
//    );

int main(){

    observable_range(&source,1,3,12);

//    int in1 = 10, in2 = 20;
//
//    struct some* s = &(struct some){ 1,2,3,4 };
//
//    int (*emitter)() = alloc_callback(&emitter_, s);
//    int (*incrementer_)() = alloc_callback(&incrementer_, s);
//
//    emitter(42,43,44,45);
//    emitter(42,43,44,45);

//    free_callback(incrementer1);
//    free_callback(incrementer2);
//    free_callback(emitter1);
//    free_callback(emitter2);

    return EXIT_SUCCESS;
}

