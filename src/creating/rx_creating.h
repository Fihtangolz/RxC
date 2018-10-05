#ifndef RXC_CREATING_H
#define RXC_CREATING_H

#include "../observer.h"
#include <callback.h>
#include <stdint.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "../prototype/c_prototype.h"
#include <memory.h>
#include "../utility.h"
#include "../rxc.h"
#include "../smart_pointer.h"

source_t* create();
source_t* defer();
source_t* from();
source_t* interval();
source_t* just(void* item);

#define NUMERICAL_BODY \
SMART_POINTER_BODY \
intmax_t value; \

GEN_LAYOUT(numerical, NUMERICAL_BODY)

source_t* range(intmax_t startValue, intmax_t itemsNumber, intmax_t step);

source_t* repeat(void* item, intmax_t step);
source_t* start();
source_t* timer(struct timespec* delay);

#endif //RXC_CREATING_H
