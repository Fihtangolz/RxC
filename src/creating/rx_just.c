/*!
 * @file
 */
#include "rx_creating.h"

#include <stdlib.h>
#include "../rx_observer.h"
#include "../rx_utility.h"

extern source_t source;

typedef struct {
    source_t* self;
    void* item;
} captured_t;

static void on_next(void* capture, va_alist arg_list){
    captured_t* cp = capture;

    for (source_t** curr_el = cp->self->subscribers; *curr_el != NULL; curr_el++) {
        (*curr_el)->on_next(cp->item);
    }

    cp->self->on_completed();
}

/*!
 *
 * @param item
 * @return
 */
source_t* rx_just(void *item) {
    D_INST_OF(source,s);
    captured_t* cp = malloc(sizeof(captured_t));
    cp->self = s;
    cp->item = item;

    s->on_next = alloc_callback(on_next, cp);
    s->on_completed = alloc_callback(dummy_on_completed, s);
    s->on_error = alloc_callback(dummy_on_error, s);

    return s;
}

