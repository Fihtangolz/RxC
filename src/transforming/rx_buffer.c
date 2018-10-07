#include "rx_transforming.h"

#include <memory.h>

#include "../prototype/rx_prototype.h"
#include "../rx_observer.h"

extern source_t source;

typedef struct {
    source_t* self;
    size_t count;
    void* array;
} captured_t;

static void on_next(void* capture, va_alist arg_list){
    captured_t* cp = capture;

    va_start_ptr(arg_list,void*);
    void* obj = va_arg_ptr(arg_list,void*);
    sm_hold(obj);

//    for (source_t** curr_el = cp->self->subscribers; *curr_el!= NULL; curr_el++) {
//        (*curr_el)->on_next();
//    }
}

source_t* rx_buffer(source_t* previous_source, size_t count){
    D_INST_OF(source, s);
    captured_t* cp = malloc(sizeof(captured_t));
    cp->self = s;
    cp->count = count;
    cp->array = NULL;

    s->on_next = alloc_callback(on_next, cp);
    s->on_completed = alloc_callback(default_on_completed, s);
    s->on_error = alloc_callback(default_on_error, s);

    append_subscriber(previous_source, s);
    return s;
}
