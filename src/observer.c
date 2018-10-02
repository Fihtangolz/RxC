#include "observer.h"
#include "rxc_filtering.h"

void dummy_func(){}

source_t source = {
        // TODO заглушить варнинги
        .on_next = dummy_func,
        .on_completed = dummy_func,
        .on_next = dummy_func,
//        .on_subscribe = dummy_func,
//        .on_unsubscribe = dummy_func,
        //
//        .debounce = debounce,
//        .distinct = distinct,
//        .element_at = element_at,
//        .filter = filter,
//        .first = first,
//        .ignore_elements = ignore_elements,
//        .last = last,
//        .sample = sample,
//        .skip = skip,
//        .skip_last = skip_last,
//        .take = take,
//        .take_last = take_last,
};