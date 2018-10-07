#include "rx_filtering.h"

#include <stdlib.h>

#include "../prototype/rx_prototype.h"
#include "../rx_observer.h"
#include "../rx_smart_pointer.h"

extern source_t source;

typedef struct {
    source_t* self;
    void* last_el;
} captured_t;

static void on_next(void* capture, va_alist arg_list){
    captured_t* cp = capture;
    va_start_ptr(arg_list, void*);

    if(cp->last_el != NULL){
        sm_free(cp->last_el);
    }
    cp->last_el = va_arg_ptr(arg_list, void*);
    sm_hold(cp->last_el);
}

static void on_complite(void* capture, va_alist arg_list){
    captured_t* cp = capture;

    cp->self->is_active = false;
    for (source_t** curr_el = cp->self->subscribers; *curr_el!= NULL; curr_el++) {
        (*curr_el)->on_next(cp->last_el);
    }
    sm_free(cp->last_el);
    for (source_t** curr_el = cp->self->subscribers; *curr_el!= NULL; curr_el++) {
        (*curr_el)->on_completed();
    }
}

source_t* rx_last(source_t* previous_source){
    D_INST_OF(source,s);
    captured_t* cp = malloc(sizeof(captured_t));
    cp->self = s;

    s->on_next = alloc_callback(on_next, cp);
    s->on_completed = alloc_callback(on_complite, cp);
    s->on_error = alloc_callback(default_on_error, s);
    append_subscriber(previous_source, s);

    return s;
}