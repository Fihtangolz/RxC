#ifndef RXC_REFLECTION_H
#define RXC_REFLECTION_H

#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/variadic/to_seq.hpp>
#include "ulimit.h"
#include "stdarg.h"
#include "stddef.h"
#include "stdbool.h"

typedef char* type_t;

#define BASE_BODY \
type_t type; \

typedef struct {
    BASE_BODY
} base_t;

#define PROTOTYPE(seq, struct_body) \
    struct BOOST_PP_CAT(BOOST_PP_SEQ_ELEM(0, seq), _proto_t) { \
        BASE_BODY \
        struct_body \
    } BOOST_PP_SEQ_ELEM(0, seq) = {.type = BOOST_PP_STRINGIZE(BOOST_PP_SEQ_ELEM(0, seq))}; \

// name BOOST_PP_SEQ_ELEM(0, seq)
// mutation BOOST_PP_SEQ_ELEM(1, seq)
#define IMPORT(lib_name) BOOST_PP_CAT(lib_name, _t) lib_name

/* INST_OF */
#define CRT_ONE_S_INST(_, prototype, instance_name) \
    typeof(prototype) instance_name; \
    memcpy(&instance_name, &prototype, sizeof(prototype)); \

#define CRT_ONE_D_INST(_, prototype, instance_name) \
    typeof(prototype)* instance_name = malloc(sizeof(prototype)); \
    memcpy(instance_name, &prototype, sizeof(prototype)); \

#define S_INST_OF(prototype, ...) APPLY_TO_ALL(CRT_ONE_S_INST, prototype, __VA_ARGS__)
#define D_INST_OF(prototype, ...) APPLY_TO_ALL(CRT_ONE_D_INST, prototype, __VA_ARGS__)

char* rt_typeof(void* obj);

bool is_same_type(void* first, ...);
//BUG: сравнивая два прототипа мы получим тру, что не верное!
bool is_instance(void* obj1, void* obj2);

#endif //RXC_REFLECTION_H
