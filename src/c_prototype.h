#ifndef RXC_REFLECTION_H
#define RXC_REFLECTION_H

#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/variadic/to_seq.hpp>
#include "ulimit.h"

//TODO add mutation
//descending mutation
//ascending mutation
//shift down

typedef char* type_t;

#define BASE_BODY \
type_t type; \

typedef struct {
    BASE_BODY
} base_t;

// TODO подумать как заменить на алиасы
// name BOOST_PP_SEQ_ELEM(0, seq)
// mutation BOOST_PP_SEQ_ELEM(1, seq)
#define PROTOTYPE(seq,struct_body) \
    struct BOOST_PP_CAT(BOOST_PP_SEQ_ELEM(0, seq), _t) { \
        BASE_BODY \
        struct_body \
    } BOOST_PP_SEQ_ELEM(0, seq) = {.type = BOOST_PP_STRINGIZE(BOOST_PP_SEQ_ELEM(0, seq)) } \

/* INST_OF */
#define CRT_ONE_INST(_, prototype, instance_name) \
    typeof(prototype) instance_name; \
    memcpy(&instance_name, &prototype, sizeof(prototype)); \

#define INST_OF(prototype, ...) APPLY_TO_ALL(CRT_ONE_INST, prototype, __VA_ARGS__)

char* rt_typeof(void* obj){
    return ((base_t*)obj)->type;
}

bool is_same_type(void* first, ...){
    va_list args;
    va_start(args, first);

    type_t first_el_type = ((base_t*)first)->type;
    for(base_t* curr_el = va_arg(args, base_t*); curr_el != NULL; curr_el = va_arg(args, base_t*)) {
        if(first_el_type != curr_el->type){
            va_end(args);
            return false;
        }
    }

    va_end(args);
    return true;
}

//BUG: сравнивая два прототипа мы получим тру, что не верное!
bool is_instance(void* obj1, void* obj2){
    return ((base_t*)obj1)->type == ((base_t*)obj2)->type;
}

#endif //RXC_REFLECTION_H
