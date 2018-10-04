#include "filtering.h"
#include "../c_prototype.h"

extern source_t source;

void* filter_on_next(source_t* self, bool(*predicat)(void*)){
//    for(void* curr_el = self->on_next(self); curr_el != NULL; curr_el = self->on_next(self)){
//        if(predicat(curr_el)){
//            return curr_el;
//        }
//    }
}

void* filter_on_error(source_t* self){
//    void* error = self->on_error(self);
//    if(error != NULL){
//        return error;
//    }
}

void filter_on_completed(source_t* self){

}

source_t* filter(source_t* self, bool(*predicat)(void*)){
    D_INST_OF(source,s);
    
    return self;
}