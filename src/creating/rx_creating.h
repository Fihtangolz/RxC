#ifndef RXC_CREATING_H
#define RXC_CREATING_H

#include "../rx_observer.h"
#include <callback.h>
#include <stdint.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "../prototype/rx_prototype.h"
#include <memory.h>
#include "../rx_utility.h"
#include "../rxc.h"
#include "../rx_smart_pointer.h"

source_t* rx_create();
source_t* defer();
source_t* rx_from();
source_t* rx_interval();
source_t* rx_just(void *item);

/// PROTOTYPE ////////////////////////
#define NUMERICAL_BODY \
        BASE_BODY \
        SMART_POINTER_BODY \
        intmax_t value; \
//////////////////////////////////////
GEN_LAYOUT(numerical, NUMERICAL_BODY)
//////////////////////////////////////

source_t* rx_range(intmax_t start_value, intmax_t items_number, intmax_t step);

source_t* rx_repeat(void *item, intmax_t item_number);

source_t* rx_start(void(*func)(source_t* self));

/// PROTOTYPE ////////////////////////
#define NOTIFY_BODY \
        BASE_BODY \
        SMART_POINTER_BODY \
//////////////////////////////////////
GEN_LAYOUT(notify, NOTIFY_BODY)
//////////////////////////////////////

source_t* rx_timer(struct timespec *delay);

#endif //RXC_CREATING_H
