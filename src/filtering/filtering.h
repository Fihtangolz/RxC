#ifndef RXC_FILTERING_H
#define RXC_FILTERING_H

#include "../observer.h"
#include "stdbool.h"
#include "../utility.h"

source_t* debounce(source_t* previous_source);
source_t* distinct(source_t* previous_source);
source_t* element_at(source_t* previous_source);
source_t* filter(source_t* previous_source, bool(*predicat)(void*));
source_t* first(source_t* previous_source);
source_t* ignore_elements(source_t* previous_source);
source_t* last(source_t* previous_source);
source_t* sample(source_t* previous_source);
source_t* skip(source_t* previous_source);
source_t* skip_last(source_t* previous_source);
source_t* take(source_t* previous_source);
source_t* take_last(source_t* previous_source);

#endif //RXC_OPERATORS_H
