#include "rx_filtering.h"

#include <memory.h>

#include <stdio.h>

#include "../prototype/rx_prototype.h"
#include "../rx_observer.h"
#include "../rx_smart_pointer.h"
#include "../rxc.h"

extern source_t source;

typedef struct {
    source_t* self;
    size_t count;
} captured_t;

static void on_next(void* capture, va_alist arg_list){
    captured_t* cp = capture;

    va_start_ptr(arg_list, void*);
    void* obj = va_arg_ptr(arg_list, void*);
    if(cp->count){
        cp->count--;
        for (source_t** curr_el = cp->self->subscribers; *curr_el!= NULL; curr_el++) {
            (*curr_el)->on_next(obj);
        }
    }
}

source_t* rx_take(source_t* previous_source, size_t count){
    D_INST_OF(source, s);
    captured_t* cp = malloc(sizeof(captured_t));
    cp->self = s;
    cp->count = count;

    append_subscriber(previous_source, s);
    s->on_next = alloc_callback(on_next, cp);
    s->on_completed = alloc_callback(default_on_completed, s);
    s->on_error = alloc_callback(default_on_error, s);

    return s;
}