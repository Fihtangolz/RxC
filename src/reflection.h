#ifndef RXC_REFLECTION_H
#define RXC_REFLECTION_H

typedef int type_t;

typedef struct {
type_t type;
} base;

#define RT_REFLECT(name, struct_body) \
struct name ## _t { \
type_t type;\
struct_body \
} name = {.type = __COUNTER__}; \

char* rt_typeof(void* obj){
    ((base*)obj)->type;
}

bool is_instance(void* obj1, void* obj2){
    return ((base*)obj1)->type == ((base*)obj2)->type;
}

#endif //RXC_REFLECTION_H
