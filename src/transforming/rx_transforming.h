#ifndef RXC_RXC_TRANSFORMING_H
#define RXC_RXC_TRANSFORMING_H

#include "../rx_observer.h"
#include "stdbool.h"
#include "../rx_utility.h"

#define PACKAGE_BODY \
    SMART_POINTER_BODY \
    void* elements \

GEN_LAYOUT(PACKAGE)

source_t* rx_buffer(source_t* previous_source, size_t count);
//static void rx_flatmap(){
//
//}
//
//static void rx_groupby(){
//
//}

source_t* rx_map(source_t* previous_source, void*(*map_func)(void* obj));
//source_t* rx_scan(source_t* previous_source, void*(*map_func)(void* obj1, void* obj2));
//static void rx_window();

#endif //RXC_RXC_TRANSFORMING_H
