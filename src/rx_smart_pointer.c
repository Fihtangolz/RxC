#include "rx_smart_pointer.h"
#include "rxc.h"

void* sm_malloc(size_t size){
    void* obj = malloc(size);
    assert(obj == NULL);
    //TODO: ....
    return obj;
}

void sm_free(LAYOUT(SMART_POINTER) target){
    target->counter--;
    if(!target->counter){
//        printf("free %p\n", target);
        free(target);
    }
}

void sm_hold(LAYOUT(SMART_POINTER) target){
    target->counter++;
}

void is_exist(){

}