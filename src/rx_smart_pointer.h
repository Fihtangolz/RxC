#ifndef RXC_SMART_POINTER_H
#define RXC_SMART_POINTER_H

#include <stdlib.h>
#include "prototype/rx_prototype.h"

#define SMART_POINTER_BODY \
int counter; \

GEN_LAYOUT(smart_pointer, SMART_POINTER_BODY);

void sm_free(layout_smart_pointer_t* target);

#endif //RXC_SMART_POINTER_H
