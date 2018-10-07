#include "rx_transforming.h"

#include <memory.h>

#include "../prototype/rx_prototype.h"
#include "../rx_observer.h"

extern source_t source;

typedef struct {
    source_t* self;
    void*(*map_func)(void*);
} captured_t;

static void on_next(void* capture, va_alist arg_list){
    captured_t* cp = capture;

    va_start_ptr(arg_list,void*);
    void* obj = va_arg_ptr(arg_list,void*);
    for (source_t** curr_el = cp->self->subscribers; *curr_el!= NULL; curr_el++) {
        (*curr_el)->on_next(cp->map_func(obj));
    }
}

source_t* rx_map(source_t* previous_source, void*(*func)(void* obj)){
    D_INST_OF(source, s);

    captured_t* cp = malloc(sizeof(captured_t));
    cp->self = s;
    cp->map_func = func;


    s->on_next = alloc_callback(on_next, cp);
    s->on_completed = alloc_callback(default_on_completed, s);
    s->on_error = alloc_callback(default_on_error, s);

    append_subscriber(previous_source, s);
    return s;
}