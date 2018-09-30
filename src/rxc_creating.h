#ifndef OBSERVERS_HPP
#define OBSERVERS_HPP

#include <stdint.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "observer.h"

static source_t start(){
    return (source_t){};
}

static source_t timer(const struct timespec* delay){
    nanosleep(delay, NULL);
    return (source_t){};
}

static source_t repeat(){
    return (source_t){};
}

static source_t range(intmax_t  startValue, intmax_t itemsNumber){
    assert(startValue > startValue + itemsNumber && ""); //TODO
    while(itemsNumber){
        printf("%li\n", startValue);
        ++startValue;
        --itemsNumber;
    }
    return (source_t){};
}

static source_t just(){
    return (source_t){};
}

static source_t interval(){
    return (source_t){};
}

static source_t from(){
    return (source_t){};
}

static source_t defer(){
    return (source_t){};
}

static source_t create(){
    return (source_t){};
}

struct {
    source_t(*start)();
    source_t(*timer)(const struct timespec* delay);
    source_t(*repeat)();
    source_t(*range)(intmax_t,intmax_t);
    source_t(*just)();
    source_t(*interval)();
    source_t(*from)();
    source_t(*defer)();
    source_t(*create)();
} observable = {
        .start = &start,
        .timer = &timer,
        .repeat = &repeat,
        .range = &range,
        .just = &just,
        .interval = &interval,
        .from = &from,
        .defer = &defer,
        .create = &create,
};

#endif //OBSERVERS_HPP
