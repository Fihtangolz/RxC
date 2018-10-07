#include "rx_filtering.h"

#include <stdlib.h>

#include "../prototype/rx_prototype.h"
#include "../rx_observer.h"
#include "../rx_smart_pointer.h"

extern source_t source;

typedef struct {
    source_t* self;
    void* array;
} captured_t;

static void on_next(void* capture, va_alist arg_list){
    captured_t* cp = capture;
    va_start_ptr(arg_list, void*);

}

source_t* rx_take_last(source_t* previous_source, size_t count){
    D_INST_OF(source,s);
    captured_t* cp = malloc(sizeof(captured_t));
    cp->self = s;

    s->on_next = alloc_callback(on_next, cp);
    s->on_completed = alloc_callback(default_on_completed, cp);
    s->on_error = alloc_callback(default_on_error, s);
    append_subscriber(previous_source, s);
    return s;
}