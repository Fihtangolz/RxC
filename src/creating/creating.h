#ifndef OBSERVERS_HPP
#define OBSERVERS_HPP

#include "../observer.h"
#include <callback.h>
#include <stdint.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "../c_prototype.h"
#include <memory.h>

source_t* create();
source_t* defer();
source_t* from();
source_t* interval();
source_t* just(void* item);
source_t* range(intmax_t startValue, intmax_t itemsNumber, intmax_t step);
source_t* repeat(void* item, intmax_t step);
source_t* start();
source_t* timer(struct timespec* delay);

#endif //OBSERVERS_HPP
