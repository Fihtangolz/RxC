#include "creating.h"
#include "../observer.h"
#include "../utility.h"

#include <stdlib.h>

extern source_t source;

typedef struct {
    source_t* self;
    struct timespec* delay;
} captured_t;

static void on_next(void* capture, va_alist arg_list){
    captured_t* cp = capture;

    nanosleep(cp->delay, NULL);
    for (source_t** curr_el = cp->self->subscribers; *curr_el!= NULL; curr_el++) {
        (*curr_el)->on_next(NULL);
    }
    cp->self->on_completed();
}

source_t* timer(struct timespec* delay){
    D_INST_OF(source,s);
    captured_t* cp = malloc(sizeof(captured_t));
    cp->self = s;
    cp->delay = delay;

    s->on_next = alloc_callback(on_next, cp);
    s->on_completed = alloc_callback(dummy_on_completed, s);
    s->on_error = alloc_callback(dummy_on_error, s);

    return s;
}


