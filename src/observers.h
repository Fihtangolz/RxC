#ifndef TEST_TASK_SESSION_HPP
#define TEST_TASK_SESSION_HPP

#include <stdint.h>
#include <assert.h>
#include <stdio.h>
#include <stdint-gcc.h>

void start(){

}

void timer(){

}

void repeat(){

}

//TODO how add static_assert??
//TODO не правильная итерация itemsNumber может быть больше
void range(intmax_t  startValue, intmax_t itemsNumber){
    assert(itemsNumber<0 || ( startValue>startValue+itemsNumber || itemsNumber>startValue+itemsNumber) );
    //static inStartValue = startValue;
    //++inStartValue
    //callListeners
    //firstEnterFlag = itemsNumber == sizeof(intmax_t)*8 - 1;
    printf("I AM\n");
}

void just(){

}

void interval(){

}

void from(){

}

void defer(){

}

void create(){

}

static struct {
  //void(*subscribe)(onNext, onError, onCompleted), //TODO return instance?
  //TODO how add static_assert??
  //TODO не правильная итерация itemsNumber может быть больше
  void(*start)();
  void(*timer)();
  void(*repeat)();
  void(*range)(intmax_t  startValue, intmax_t itemsNumber);
  void(*just)();
  void(*interval)();
  void(*from)();
  void(*defer)();
  void(*create)();
} observable = {.start = &start,
                .timer = &timer,
                .repeat = &repeat,
                .range = &range,
                .just = &just,
                .interval = &interval,
                .from = &from,
                .defer = &defer,
                .create = &create};

//struct {
//    void* buffer;
//    void(*func);
//};
//
//void s(){
//    if(!buffer){
//        (int)nuffer = 12;
//    }
//}

//#define private: private__
//#define :: __

// REACT(R/W/RW, type + name + initilizer)
#define REACT( observableProperties, type, name, initilizer ) \
typedef struct { \
    type private_Name; \
    const type*(*get)(void* self); \
    void(*set)(void* self, const type t); \
} REACT__  ## type; \
const type* get(void* self){ \
    printf("get of REACT__%s was called\n", #type );\
    return &((REACT__  ## type*)self)->private_Name; \
} \
\
void set(void* self, const type t){ \
    printf("set of REACT__%s was called\n", #type );\
    ((REACT__  ## type*)self)->private_Name = t; \
} \
REACT__ ## type (name) = {.private_Name = (initilizer), \
            .get = get, \
            .set = set}; \

//{a+b/c << k}[a,b,c,k]
#define REXPR( code , conversionPoints )
// блокировка рекурсий

#endif //TEST_TASK_SESSION_HPP
