#include "rx_filtering.h"
#include "../prototype/rx_prototype.h"
#include "../rx_observer.h"
#include <stdlib.h>

extern source_t source;

typedef struct {
    source_t* self;
    bool(*predicat)(void*);
} captured_t;

static void on_next(void* capture, va_alist arg_list){
    captured_t* cp = capture;

    va_start_ptr(arg_list,void*);
    void* obj = va_arg_ptr(arg_list,void*);
    if(cp->predicat(obj)){
        for (source_t** curr_el = cp->self->subscribers; *curr_el!= NULL; curr_el++) {
            (*curr_el)->on_next(obj);
        }
    }
}

source_t* rx_filter(source_t *previous_source, bool(*predicat)(void *)){
    D_INST_OF(source, s);
    captured_t* cp = malloc(sizeof(captured_t));
    cp->self = s;
    cp->predicat = predicat;

    append_subscriber(previous_source, s);
    s->on_next = alloc_callback(on_next, cp);
    s->on_completed = alloc_callback(dummy_on_completed, s);
    s->on_error = alloc_callback(dummy_on_error, s);

    return s;
}