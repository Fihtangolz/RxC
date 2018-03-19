#include <stdint.h>
#include <assert.h>
#include <glob.h>
#include <stdio.h>

typedef struct {
    size_t size;
    void* this;
    int(*f)(const char *__restrict __format, ...);
} r;

//new();
//delete
void add(int d){
    printf("asdasd %d", d);
}
void(*ret(int u))(){
    add(u);
    return &add;
}

void* ret2(void* d){
    return d;
}

#define inlinecallback(c_) ({ c_ _;})

//range(int,int,Scheduler)
void func(int r, void(*d)(int v)) {
  d(r);
}
// int main(){
//
//     func(4, inlinecallback(void _(int v) {
//       printf("%d\n", v);
//     }));
//
//     r d;
//     d.f = &printf;
//
//     ret(22)(12);
//
//     ((r*)ret2(&d))->f("sssss");
// }

int main(int argc, char const *argv[]) {
  observarble.range(0,1);
  return 0;
}
