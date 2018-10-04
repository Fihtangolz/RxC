#ifndef RXC_SMART_POINTER_H
#define RXC_SMART_POINTER_H

#include <stdlib.h>
#include "prototype/c_prototype.h"

#define COUNTER_BODY int counter;

typedef struct {
    BASE_BODY
    COUNTER_BODY
} smart_pointer_t;

void sm_free(smart_pointer_t* target);

#endif //RXC_SMART_POINTER_H
