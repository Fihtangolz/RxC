#include "rx_prototype.h"

char* rt_typeof(void* obj){
    return ((layout_base_t*)obj)->type;
}

bool is_same_type(void* first, ...){
    va_list args;
    va_start(args, first);

    type_t first_el_type = ((layout_base_t*)first)->type;
    for(layout_base_t* curr_el = va_arg(args, layout_base_t*); curr_el != NULL; curr_el = va_arg(args, layout_base_t*)) {
        if(first_el_type != curr_el->type){
            va_end(args);
            return false;
        }
    }

    va_end(args);
    return true;
}

bool is_instance(void* obj1, void* obj2){
    return ((layout_base_t*)obj1)->type == ((layout_base_t*)obj2)->type;
}