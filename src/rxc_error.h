#ifndef RXC_ERROR_H
#define RXC_ERROR_H

typedef struct {
    struct source_t* source;
    char* description;
} throwable_t;

struct source_t* throw(struct source_t* previous_source);

#endif //RXC_ERROR_H
