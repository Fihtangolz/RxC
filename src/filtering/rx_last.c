#include <stdlib.h>
#include "rx_filtering.h"

#include "../prototype/rx_prototype.h"
#include "../rx_observer.h"

extern source_t source;

typedef struct {
    source_t* self;
    void* last_el;
} captured_t;

static void on_next(void* capture, va_alist arg_list){
    captured_t* cp = capture;
    va_start_ptr(arg_list, void*);
    cp->last_el = va_arg_ptr(arg_list, void*);
    return;
}

static void on_complite(void* capture, va_alist arg_list){
    captured_t* cp = capture;

    cp->self->is_active = false;
    for (source_t** curr_el = cp->self->subscribers; *curr_el!= NULL; curr_el++) {
        (*curr_el)->on_next(cp->last_el);
    }
    for (source_t** curr_el = cp->self->subscribers; *curr_el!= NULL; curr_el++) {
        (*curr_el)->on_completed();
    }
    return;
}

source_t* last(source_t* previous_source){
    D_INST_OF(source,s);
    captured_t* cp = malloc(sizeof(captured_t));
    cp->self = s;

    s->on_next = alloc_callback(on_next, cp);
    s->on_completed = alloc_callback(on_complite, cp);
    s->on_error = alloc_callback(dummy_on_error, s);
    append_subscriber(previous_source, s);

    return s;
}