#ifndef RXC_ERROR_H
#define RXC_ERROR_H

#include "prototype/rx_prototype.h"
#include "rx_smart_pointer.h"

#define THOWABLE_BODY \
SMART_POINTER_BODY \
struct source_t* source; \
char* description; \

GEN_LAYOUT(THOWABLE)

struct source_t* throw(struct source_t* previous_source);

#endif //RXC_ERROR_H
