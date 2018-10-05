#include "rx_smart_pointer.h"
#include "rxc.h"

void sm_free(layout_smart_pointer_t* target){
    if(!target->counter){
        free(target);
    }
}
