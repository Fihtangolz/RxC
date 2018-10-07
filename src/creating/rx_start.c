/*!
 * @file
 */
#include "rx_creating.h"

extern source_t source;

typedef struct {
    source_t* self;
    void*(*func)(source_t* self);
} captured_t;

static void on_next(void* capture, va_alist arg_list){
    captured_t* cp = capture;

    for (source_t** curr_el = cp->self->subscribers; *curr_el != NULL; curr_el++) {
        (*curr_el)->on_next(cp->func(cp->self));
    }
}

/*!
 * @brief Create producer based on user function.
 * @param func User function which provide object for chain and control producer behavior. \n
 *             When function finished producing call in func body self->on_completed(). \n
 *             For throw exception call in func body self->on_error(error). \n
 * @return Producer
 */
source_t* rx_start(void(*func)(source_t* self)){
    D_INST_OF(source, s);
    captured_t* cp = malloc(sizeof(captured_t));

    s->on_next = alloc_callback(on_next, cp);
    s->on_completed = alloc_callback(default_on_completed, s);
    s->on_error = alloc_callback(default_on_error, s);

    return s;
}