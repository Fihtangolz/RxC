#ifndef OBSERVERS_HPP
#define OBSERVERS_HPP

#include <stdint.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "observer.h"

static source start(){
    return (source){};
}

static source timer(const struct timespec* delay){
    nanosleep(delay, NULL);
    return (source){};
}

static source repeat(){
    return (source){};
}

static source range(intmax_t  startValue, intmax_t itemsNumber){
    assert(startValue > startValue + itemsNumber && ""); //TODO
    while(itemsNumber){
        printf("%li\n", startValue);
        ++startValue;
        --itemsNumber;
    }
    return (source){};
}

static source just(){
    return (source){};
}

static source interval(){
    return (source){};
}

static source from(){
    return (source){};
}

static source defer(){
    return (source){};
}

static source create(){
    return (source){};
}

struct observable {
    source(*start)();
    source(*timer)(const struct timespec* delay);
    source(*repeat)();
    source(*range)(intmax_t,intmax_t);
    source(*just)();
    source(*interval)();
    source(*from)();
    source(*defer)();
    source(*create)();
} observable = {.start = &start,
        .timer = &timer,
        .repeat = &repeat,
        .range = &range,
        .just = &just,
        .interval = &interval,
        .from = &from,
        .defer = &defer,
        .create = &create};

#endif //OBSERVERS_HPP
