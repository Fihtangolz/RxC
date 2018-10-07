#ifndef RXC_SMART_POINTER_H
#define RXC_SMART_POINTER_H

#include <stdlib.h>
#include "prototype/rx_prototype.h"

#define SMART_POINTER_BODY \
BASE_BODY \
int counter; \

GEN_LAYOUT(SMART_POINTER)

void sm_free(LAYOUT(SMART_POINTER) target);
void sm_hold(LAYOUT(SMART_POINTER) target);

#endif //RXC_SMART_POINTER_H
