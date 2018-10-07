/*!
 * @file
 */
#include "rx_creating.h"

#include "../prototype/rx_prototype.h"
#include "../rx_observer.h"

extern source_t source;

source_t* rx_create(void(*func1)(source_t* self), void(*func2)(source_t* self), void(*func3)(source_t* self)){
    D_INST_OF(source, s);

    s->on_next = func1;
    s->on_completed = func2;
    s->on_error = func3;

    return s;
}
