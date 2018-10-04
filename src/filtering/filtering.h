#ifndef RXC_FILTERING_H
#define RXC_FILTERING_H

#include "../observer.h"
#include "stdbool.h"

//FUNC_DEF(struct source_t*, debounce, struct source_t* self);
//FUNC_DEF(struct source_t*, distinct, struct source_t* self);
//FUNC_DEF(struct source_t*, element_at, struct source_t* self);

//FUNC_DEF(struct source_t*, filter, struct source_t* self);

//typedef struct source_t*(*func_filter_t)(struct source_t* self, bool(*predicat)(void*));
source_t* filter(source_t* self, bool(*predicat)(void*));

//FUNC_DEF(struct source_t*, first, struct source_t* self);
//FUNC_DEF(struct source_t*, ignore_elements, struct source_t* self);
//FUNC_DEF(struct source_t*, last, struct source_t* self);
//FUNC_DEF(struct source_t*, sample, struct source_t* self);
//FUNC_DEF(struct source_t*, skip, struct source_t* self);
//FUNC_DEF(struct source_t*, skip_last, struct source_t* self);
//FUNC_DEF(struct source_t*, take, struct source_t* self);
//FUNC_DEF(struct source_t*, take_last, struct source_t* self);

#endif //RXC_OPERATORS_H
