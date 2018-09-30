#ifndef RXC_OBSERVER_H
#define RXC_OBSERVER_H

#include "rxc_filtering.h"
#include "utility.h"

typedef struct source_t {
    void(*on_next)(void*);
    void(*on_completed)();
    void(*on_error)(void*); //TODO
    void(*on_subscribe)();
    void(*on_unsubscribe)();

    FIELDS_CRT(
        debounce,
        distinct,
        element_at,
        filter,
        first,
        ignore_elements,
        last,
        sample,
        skip,
        skip_last,
        take,
        take_last
    );

} source_t;

source_t source = {
        .debounce = debounce,
        .distinct = distinct,
        .element_at = element_at,
        .filter = filter,
        .first = first,
        .ignore_elements = ignore_elements,
        .last = last,
        .sample = sample,
        .skip = skip,
        .skip_last = skip_last,
        .take = take,
        .take_last = take_last,
};
#endif //RXC_OBSERVER_H
