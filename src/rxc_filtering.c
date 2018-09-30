#include "rxc_filtering.h"
#include <stdio.h>

func_debounce_t debounce(struct source_t* self){
    printf("debounce\n");
    return self;
}

func_distinct_t distinct(struct source_t* self){
    printf("distinct\n");
    return self;
}

func_element_at_t element_at(struct source_t* self){
    printf("element_at\n");
    return self;
}

func_filter_t filter(struct source_t* self){
    printf("filter\n");
    return self;
}

func_filter_t first(struct source_t* self){
    printf("first\n");
    return self;
}

func_ignore_elements_t ignore_elements(struct source_t* self){
    printf("ignore_elements\n");
    return self;
}

func_last_t last(struct source_t* self){
    printf("last\n");
    return self;
}

func_sample_t sample(struct source_t* self){
    printf("sample\n");
    return self;
}

func_skip_t skip(struct source_t* self){
    printf("skip\n");
    return self;
}

func_skip_last_t skip_last(struct source_t* self){
    printf("skip_last\n");
    return self;
}

func_take_t take(struct source_t* self){
    printf("take\n");
    return self;
}

func_take_last_t take_last(struct source_t* self){
    printf("take_last\n");
    return self;
}
