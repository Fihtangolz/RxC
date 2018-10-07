/*!
 * @file
 */
#include "rx_creating.h"

#include <stdlib.h>
#include "../prototype/rx_prototype.h"
#include "../rx_observer.h"
#include "../rx_utility.h"

extern source_t source;

typedef struct {
    source_t* self;
    void* item;
    intmax_t number;
} captured_t;

static void on_next(void* capture, va_alist arg_list){
    captured_t* cp = capture;
    for(;cp->number; --cp->number){
        for (source_t** curr_el = cp->self->subscribers; *curr_el != NULL; curr_el++) {
            (*curr_el)->on_next(cp->item);
        }
    }

    cp->self->on_completed();
}

/*!
 * Create Create producer that emit repeatedly single item
 * @param item Emitted item
 * @param item_number Number of items
 * @return Producer
 */
source_t* rx_repeat(void *item, intmax_t item_number){
    D_INST_OF(source, s);
    captured_t* cp = malloc(sizeof(captured_t));
    cp->self = s;
    cp->item = item;
    cp->number = item_number;

    s->on_next = alloc_callback(on_next, cp);
    s->on_completed = alloc_callback(default_on_completed, s);
    s->on_error = alloc_callback(default_on_error, s);

    return s;
}
