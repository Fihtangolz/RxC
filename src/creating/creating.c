#include "creating.h"

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

static source_t just(){
    return (source_t){};
}

static source_t interval(){
    return (source_t){};
}

static source_t from(){
    return (source_t){};
}

static source_t create(){
    return (source_t){};
}


