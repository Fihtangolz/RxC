/*!
 * @file
 */
#include "rx_creating.h"

#include <stdlib.h>
#include "../rx_observer.h"
#include "../rx_error.h"
#include "../prototype/rx_prototype.h"
#include "../rx_utility.h"
#include "../rx_smart_pointer.h"
#include "../rxc.h"

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
    intmax_t start_value;
    intmax_t items_number;
    intmax_t step;
} captured_t;

static void on_next(void* capture, va_alist arg_list){
    captured_t* cp = capture;
    if(cp->items_number) {
        --cp->items_number;

        LAYOUT(NUMERICAL) copy = malloc(sizeof(LAYOUT(NUMERICAL)));
        copy->value = cp->start_value;
        sm_hold(copy);
        for (source_t** curr_el = cp->self->subscribers; *curr_el!= NULL; curr_el++) {
            (*curr_el)->on_next(copy);
        }
        sm_free(copy);
        if (CHECK_ADD_OVERFLOW(cp->start_value, cp->step, &cp->start_value)) {
            LAYOUT(THOWABLE) error = malloc(sizeof(LAYOUT(THOWABLE)));
            error->source = cp->self;
            error->description = "overflow";
            cp->self->on_error(error);
        }
        return;
    }

    cp->self->on_completed();
    return;
}

/*!
 * Create producer that emits a particular range of sequential integers
 * @param start_value The first element of the sequence
 * @param items_number Numbers of element in the sequence
 * @param step Step of sequence
 * @return Producer
 */
source_t* rx_range(intmax_t start_value, intmax_t items_number, intmax_t step) {
    D_INST_OF(source,s);
    captured_t* cp = malloc(sizeof(captured_t));
    cp->self = s;
    cp->start_value = start_value;
    cp->items_number = items_number;
    cp->step = step;

    s->on_next = alloc_callback(on_next, cp);
    s->on_completed = alloc_callback(default_on_completed, s);
    s->on_error = alloc_callback(default_on_error, s);

    return s;
}

