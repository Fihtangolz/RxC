#ifndef RXC_OBSERVER_H
#define RXC_OBSERVER_H

#include "utility.h"
#include "rxc_filtering.h"

typedef struct {
    void*(*on_next)();
    void(*on_completed)(struct source_t* self);
    void*(*on_error)(struct source_t* self);
//    void(*on_subscribe)();
//    void(*on_unsubscribe)();

//    FIELDS_CRT(filter);
//        debounce,
//        distinct,
//        element_at,
//        filter,
//        first,
//        ignore_elements,
//        last,
//        sample,
//        skip,
//        skip_last,
//        take,
//        take_last
//    ); //TODO extra ;

} source_t;

#endif //RXC_OBSERVER_H
