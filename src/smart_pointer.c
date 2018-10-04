#include "smart_pointer.h"
#include "rxc.h"

void sm_free(smart_pointer_t* target){
    if(!target->counter){
        free(target);
    }
}
