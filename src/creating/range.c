#include "creating.h"

#include <stdlib.h>
#include "../observer.h"
#include "../rxc_error.h"

#define CHECK_ADD_OVERFLOW(arg1, arg2, result) \
_Generic((arg1), \
    default: __builtin_add_overflow, \
    int: __builtin_sadd_overflow, \
    long int: __builtin_saddl_overflow, \
    long long int: __builtin_saddll_overflow, \
    unsigned int: __builtin_uadd_overflow, \
    unsigned long int: __builtin_uaddl_overflow, \
    unsigned long long int: __builtin_uaddll_overflow \
)(arg1, arg2, result) \


extern source_t source;

typedef struct {
    source_t* self;
    intmax_t startValue;
    intmax_t itemsNumber;
    intmax_t step;
} captured_t;

static void on_next(void* capture, va_alist arg_list){
    captured_t* cp = capture;
    if(cp->itemsNumber) {
        --cp->itemsNumber;
        for (source_t** curr_el = cp->self->subscribers; *curr_el!= NULL; curr_el++) {
            (*curr_el)->on_next(&cp->startValue);
        }
        if (CHECK_ADD_OVERFLOW(cp->startValue, cp->step, &cp->startValue)) {
            throwable_t* error = malloc(sizeof(throwable_t)); //TODO malloc NULL handle
            error->source = cp->self;
            error->description = "overflow";
            cp->self->on_error(error);
        }
        return;
    }

    cp->self->on_completed();
    return;
}

source_t* range(intmax_t startValue, intmax_t itemsNumber, intmax_t step) {
    D_INST_OF(source,s);
    captured_t* cp = malloc(sizeof(captured_t));
    cp->self = s;
    cp->startValue = startValue;
    cp->itemsNumber = itemsNumber;
    cp->step = step;

    s->on_next = alloc_callback(on_next, cp);
    s->on_completed = alloc_callback(dummy_on_completed, s);
    s->on_error = alloc_callback(dummy_on_error, s);

    return s;
}

