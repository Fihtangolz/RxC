#ifndef RXC_OBSERVER_H
#define RXC_OBSERVER_H

#include <stdlib.h>
#include <callback.h>
#include <stdbool.h>
#include "rxc_error.h"

#define subscribers_t_size 8*5
typedef struct source_t* subscribers_t[subscribers_t_size];

typedef struct {
    bool is_active;
    subscribers_t subscribers;
    void(*on_next)(void* obj);
    void(*on_completed)();
    void(*on_error)(struct throwable_t* error);
    void(*on_subscribe)(struct source_t* target, struct source_t* subscriber);
    void(*on_unsubscribe)(struct source_t* target, struct source_t* subscriber);

} source_t;

void dummy_on_next(void* capture, va_alist arg_list);
void dummy_on_completed(void* capture, va_alist arg_list);
void dummy_on_error(void* capture, va_alist arg_list);

void append_subscriber(source_t* target, source_t* subscriber);
void func_on_next(source_t* el, void* passed_argument);
void apply_for_all_subscriber(source_t* target, void* passed_argument, void(*func)(source_t* el, void* arg));

source_t*  subscribe(
    source_t* producer,
    source_t* operator,
    void(*on_next)(void* obj),
    void(*on_completed)(),
    void(*on_error)(throwable_t* error),
    void(*on_subscribe)(struct source_t* target, source_t* subscriber),
    void(*on_unsubscribe)(struct source_t* target, source_t* subscriber)
);

void* unsubscribe(source_t* target, source_t* subscriber);

#endif //RXC_OBSERVER_H
