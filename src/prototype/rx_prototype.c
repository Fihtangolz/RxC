#include "rx_prototype.h"

char* rt_typeof(void* obj){
    return LAYOUT_CAST(BASE, obj)->type;
}

bool is_same_type(void* first, ...){
    va_list args;
    va_start(args, first);

    type_t first_el_type = LAYOUT_CAST(BASE, first)->type;
    for(LAYOUT(BASE) curr_el = va_arg(args, LAYOUT(BASE)); curr_el != NULL; curr_el = va_arg(args, LAYOUT(BASE))) {
        if(first_el_type != curr_el->type){
            va_end(args);
            return false;
        }
    }

    va_end(args);
    return true;
}

bool is_instance(void* obj1, void* obj2){
    return LAYOUT_CAST(BASE, obj1)->type == LAYOUT_CAST(BASE, obj2)->type;
}