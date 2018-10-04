# RxC : Reactive Extensions for C boosted by Prototype Programming 
---
Good point to start Reactive programming is 
- [http://reactivex.io/]()
- [Reactive Design Patterns by Roland Kuhn]()
- [http://qaru.site/questions/1243/what-is-functional-reactive-programming]()
- [http://conal.net/fran/tutorial.htm]()
- [https://www.webcitation.org/67lNOmS7t]()

Example: 

```c
#include <stdlib.h>
#include "src/rxc.h"

int main(){
    source_t* s1 = range(0, 15, 1); //replace step to INTMAX_MAX/10 for see throwing
    source_t* s2 = filter(s1, LAMBDA(bool,(void* f), {
        return !((*(intmax_t *)f) % 2);
    }));
    source_t* s3 = filter(s2, LAMBDA(bool,(void* f), {
        return (*(intmax_t*)f) < 10;
    }));
    source_t* s4 = last(s3);

    subscribe(s1, s3,
    LAMBDA(void,(void* obj), {
        printf("Hello react: %lli\n", *(int*)(obj));
    }),
    LAMBDA(void,(), {
        printf("I'ev completed\n");
    }),
    LAMBDA(void,(throwable_t* error), {
        printf("error: [%s] source: [%p] \n", error->description, error->source);
        free(error);
    }),
    NULL, NULL);

    return EXIT_SUCCESS;
}
```