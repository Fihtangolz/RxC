#include <stdlib.h>
#include "creating.h"
#include "../observer.h"

extern source_t source;

typedef struct {
    source_t* self;
    intmax_t startValue;
    intmax_t itemsNumber;
    intmax_t step;
} captured_t ;

static void range_on_next(void* data, va_alist alist){
    captured_t* cp = data;

    printf("%d %d %d\n", cp->startValue, cp->itemsNumber, cp->step);
    while(cp->itemsNumber){
        printf("%d\n",cp->startValue);
        --cp->itemsNumber;
        cp->startValue+=cp->step;
        //assert(startValue > startValue + itemsNumber && ""); //TODO: throw error, also add step error
    }
}

source_t* observable_range(source_t* self, intmax_t  startValue, intmax_t itemsNumber, intmax_t step){
    INST_OF(source,s);
    captured_t cp = {
            .self = &s,
            .startValue = startValue,
            .itemsNumber = itemsNumber,
            .step = step
    };

    s.on_next = alloc_callback(&range_on_next, &cp);
    s.on_next();

    return &s;
}

