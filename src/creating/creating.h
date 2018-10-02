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

source_t* observable_range(source_t* self, intmax_t  startValue, intmax_t itemsNumber, intmax_t step);

#endif //OBSERVERS_HPP
