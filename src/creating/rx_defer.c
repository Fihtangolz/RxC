/*!
 * @file
 */
#include "rx_creating.h"

#include <stdlib.h>
#include "../rx_utility.h"

extern source_t source;

static void on_next(void* capture, va_alist arg_list){
//    captured_t* cp = capture;

//    va_start_ptr(arg_list,void*);
//    void* obj = va_arg_ptr(arg_list,void*);
//    if(cp->predicat(obj)){
//        for (source_t** curr_el = cp->self->subscribers; *curr_el!= NULL; curr_el++) {
//            (*curr_el)->on_next(obj);
//        }
//    }
}


source_t* rx_defer(){
    D_INST_OF(source,s);
//    captured_t* cp = malloc(sizeof(captured_t));

//    s->on_next = alloc_callback(on_next, cp);

    return s;
}

