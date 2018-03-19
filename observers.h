#ifndef TEST_TASK_SESSION_HPP
#define TEST_TASK_SESSION_HPP

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
  void(*range)(intmax_t  startValue, intmax_t itemsNumber)
} observarble = {//create observarble
                 .start = &start,
                 .timer = &timer,
                 .repeat = &repeat,
                 .range = &range,
                 .just = &just,
                 .interval = &interval,
                 .from = &from,
                 .defer = &defer,
                 .create = &create};

#endif //TEST_TASK_SESSION_HPP
