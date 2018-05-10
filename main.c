#include <zconf.h>

#include "src/rxc_creating.h"
#include "src/rxc_combining.h"

REACT(R/W, int, some, 0)

source* fun1(source* s...){
    va_list args;
}

int main(){
    source s1;
    rx_combining_zip(fun1,&s1);
}
