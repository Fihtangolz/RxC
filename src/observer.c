#include "observer.h"
#include "rxc_error.h"
#include "prototype/c_prototype.h"
#include "utility.h"
#include "functional/c_functional.h"
#include <stdlib.h>

void dummy_on_next(void* capture, va_alist arg_list){
    source_t* self = capture;

    va_start_ptr(arg_list,void*);
    void* obj = va_arg_ptr(arg_list,void*);
    for (source_t** curr_el = self->subscribers; *curr_el != NULL; curr_el++) {
        (*curr_el)->on_next(obj);
    }
    self->on_completed();
    return;
}

void dummy_on_completed(void* capture, va_alist arg_list){
    source_t* self = capture;

    va_start_ptr(arg_list,void*);
    void* obj = va_arg_ptr(arg_list,void*);

    self->is_active = false;
    for (source_t** curr_el = self->subscribers; *curr_el != NULL; curr_el++) {
        (*curr_el)->on_completed();
    }
    return;
}

void dummy_on_error(void* capture, va_alist arg_list){
    source_t* self = capture;

    va_start_ptr(arg_list, throwable_t*);
    throwable_t* obj = va_arg_ptr(arg_list, throwable_t*);

    self->is_active = false;
    for (source_t** curr_el = self->subscribers; *curr_el != NULL; curr_el++) {
        (*curr_el)->on_error(obj);
    }
}

source_t source = {
    .is_active = false,
    .subscribers = {NULL},
};

void append_subscriber(source_t* target, source_t* subscriber){
    for(source_t** curr_el = target->subscribers; ;curr_el++){
        if(*curr_el == NULL){
            *curr_el = subscriber;
            curr_el++;
            *curr_el = NULL;
            return;
        }
    }
}

void func_on_next(source_t* el, void* passed_argument){
    el->on_next(passed_argument);
}

void apply_for_all_subscriber(source_t* target, void* passed_argument, void(*func)(source_t* el, void* arg)){
    for (source_t** curr_el = target->subscribers; *curr_el != NULL; curr_el++) {
        func(*curr_el, passed_argument);
    }
}

void dummy_func(){}

source_t*  subscribe(
    source_t* producer,
    source_t* operator,
    void(*on_next)(void* obj),
    void(*on_completed)(),
    void(*on_error)(throwable_t* error),
    void(*on_subscribe)(struct source_t* target, source_t* subscriber),
    void(*on_unsubscribe)(struct source_t* target, source_t* subscriber)
){
    D_INST_OF(source,s);

    s->on_next = (on_next == NULL) ? dummy_func : on_next;
    s->on_error = (on_error == NULL) ? dummy_func : on_error;
    s->on_completed = (on_completed == NULL) ? dummy_func : on_completed;
    s->on_subscribe = (on_subscribe == NULL) ? dummy_func : subscribe;
    s->on_unsubscribe = (on_unsubscribe == NULL) ? dummy_func : on_unsubscribe;
    append_subscriber(operator,s);

    if(!producer->is_active){
        producer->is_active = true;
        while(producer->is_active){
            JUST_CALL(producer->on_next);
        }
    }

    return 1;
}

void* unsubscribe(source_t* producer, source_t* subscriber){

}
