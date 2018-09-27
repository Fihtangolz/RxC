#ifndef RXC_REFLECTION_H
#define RXC_REFLECTION_H

//TODO add mutation

typedef char* type_t;

typedef struct {
type_t type;
} base_t;

// TODO подумать как заменить на алиасы
// name BOOST_PP_SEQ_ELEM(0, seq)
// struct_body BOOST_PP_SEQ_ELEM(1, seq)
#define PROTOTYPE(seq,struct_body) \
struct BOOST_PP_CAT(BOOST_PP_SEQ_ELEM(0, seq), _t) { \
type_t type; \
struct_body \
} BOOST_PP_SEQ_ELEM(0, seq) = {.type = BOOST_PP_STRINGIZE(BOOST_PP_SEQ_ELEM(0, seq)) } \

#define INST_OF(prototype, instanse_name)  \
typeof(prototype) instanse_name;\
memcpy(&instanse_name,&prototype,sizeof(prototype));\

char* rt_typeof(void* obj){
    return ((base_t*)obj)->type;
}

bool is_instance(void* obj1, void* obj2){
    return ((base_t*)obj1)->type == ((base_t*)obj2)->type;
}

#endif //RXC_REFLECTION_H
