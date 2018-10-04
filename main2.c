#include <stdlib.h>
#include "src/rxc.h"
#include "src/observer.h"

int main(){
    source_t* s1 = range(0, 15, 1); //replace step to INTMAX_MAX/10 for see throwing
    source_t* s2 = filter(s1, LAMBDA(bool,(void* f), {
        return !(((numerical_t*)f)->value % 2);
    }));
    source_t* s3 = filter(s2, LAMBDA(bool,(void* f), {
        return (*(numerical_t*)f).value < 10;
    }));
    source_t* s4 = last(s3);

    subscribe(s1, s4,
    LAMBDA(void,(void* obj), {
        printf("Hello react: %lli\n", (*(numerical_t*)obj).value);
        sm_free(obj);
    }),
    LAMBDA(void,(), {
        printf("I'ev completed\n");
    }),
    LAMBDA(void,(throwable_t* error), {
        printf("error: [%s] source: [%p] \n", error->description, error->source);
        sm_free(error);
    }),
    NULL, NULL);

    return EXIT_SUCCESS;
}