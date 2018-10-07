/*!
 * @file
 */
#include "rx_creating.h"

#include <stdlib.h>

extern source_t source;

typedef struct {
    source_t* self;
    void* item;
    intmax_t number;
} captured_t;


source_t* rx_from_char(){
    D_INST_OF(source, s);

    return s;
}
