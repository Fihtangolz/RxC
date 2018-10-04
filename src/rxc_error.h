#ifndef RXC_ERROR_H
#define RXC_ERROR_H

#include "prototype/c_prototype.h"
#include "smart_pointer.h"

#define THOWABLE_BODY \
SMART_POINTER_BODY \ 
struct source_t* source; \
char* description; \

typedef struct {
    THOWABLE_BODY
} layout_throwable_t;

struct source_t* throw(struct source_t* previous_source);

#endif //RXC_ERROR_H
