#ifndef RXC_OBSERVER_H
#define RXC_OBSERVER_H

//Объект в сушности передаваемый
typedef struct {
} throwable;

typedef struct {
    void(*on_next)(void*);
    void(*on_completed)();
    void(*on_error)(throwable*);
    void(*on_subscribe)();
    void(*on_unsubscribe)();
} source;

#endif //RXC_OBSERVER_H
