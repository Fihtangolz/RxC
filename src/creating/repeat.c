#include "creating.h"

#include <stdlib.h>
#include "../c_prototype.h"
#include "../observer.h"

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

source_t* repeat(void* item, intmax_t step){
    D_INST_OF(source,s);
    captured_t* cp = malloc(sizeof(captured_t));
    cp->self = s;
    cp->item = item;
    cp->number = step;

    s->on_next = alloc_callback(on_next, cp);
    s->on_completed = alloc_callback(dummy_on_completed, s);
    s->on_error = alloc_callback(dummy_on_error, s);

    return s;
}
