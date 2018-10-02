#include <memory.h>
#include "rxc_filtering.h"
#include "observer.h"
#include "c_prototype.h"
#include "stdio.h"
#include <callback.h>

//struct source_t* debounce(struct source_t* self){
//    printf("debounce\n");
//    return self;
//}
//
//struct source_t* distinct(struct source_t* self){
//    printf("distinct\n");
//    return self;
//}
//
//struct source_t* element_at(struct source_t* self){
//    printf("element_at\n");
//    return self;
//}

extern struct source_t source;

void* filter_on_next(source_t* self, bool(*predicat)(void*)){
    for(void* curr_el = self->on_next(self); curr_el != NULL; curr_el = self->on_next(self)){
        if(predicat(curr_el)){
            return curr_el;
        }
    }
}

void* filter_on_error(source_t* self){
    void* error = self->on_error(self);
    if(error != NULL){
        return error;
    }
}

void filter_on_completed(source_t* self){

}

//struct source_t* filter(source_t* self, bool(*predicat)(void*)){
//    INST_OF(source,s);
//
//    return self;
//}

//struct source_t* first(struct source_t* self){
//    printf("first\n");
//    return self;
//}
//
//struct source_t* ignore_elements(struct source_t* self){
//    printf("ignore_elements\n");
//    return self;
//}
//
//struct source_t* last(struct source_t* self){
//    printf("last\n");
//    return self;
//}
//
//struct source_t* sample(struct source_t* self){
//    printf("sample\n");
//    return self;
//}
//
//struct source_t* skip(struct source_t* self){
//    printf("skip\n");
//    return self;
//}
//
//struct source_t* skip_last(struct source_t* self){
//    printf("skip_last\n");
//    return self;
//}
//
//struct source_t* take(struct source_t* self){
//    printf("take\n");
//    return self;
//}
//
//struct source_t* take_last(struct source_t* self){
//    printf("take_last\n");
//    return self;
//}
