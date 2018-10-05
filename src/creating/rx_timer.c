/*!
 * @file
 */
#include "rx_creating.h"

#include "../rx_observer.h"
#include "../rx_utility.h"
#include <stdlib.h>

extern source_t source;

typedef struct {
    source_t* self;
    struct timespec* delay;
} captured_t;

static void on_next(void* capture, va_alist arg_list){
    captured_t* cp = capture;

    nanosleep(cp->delay, NULL);
    layout_notify_t* copy = malloc(sizeof(layout_notify_t));
    for (source_t** curr_el = cp->self->subscribers; *curr_el!= NULL; curr_el++) {
        (*curr_el)->on_next(copy);
    }
    cp->self->on_completed();
}

/*!
 * Create producer that emit single item(layout_notify_t) after delay
 * @param delay Waiting time before emit item
 * @return Producer
 */
source_t* rx_timer(struct timespec* delay){
    D_INST_OF(source,s);
    captured_t* cp = malloc(sizeof(captured_t));
    cp->self = s;
    cp->delay = delay;

    s->on_next = alloc_callback(on_next, cp);
    s->on_completed = alloc_callback(dummy_on_completed, s);
    s->on_error = alloc_callback(dummy_on_error, s);

    return s;
}


