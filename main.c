#include "src/observers.h"

REACT(R/W, int, some, 0)

int main(){
    some.get(&some);
    some.set(&some, 12);
}
