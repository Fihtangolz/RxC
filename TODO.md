//Хранить ли старое значение
// REACT(R/W/RW, type + name + initilizer)
#if REACT_int
    #pragma message "asdasd"
#endif

//горячие холодные коннектабельные
//subscriber / unsubscribe

#define REACT( observableProperties, type, name, initializer ) \
typedef struct { \
    type private_Name; \
    const type*(*get)(void* self); \
    void(*set)(void* self, const type t); \
} REACT__  ## type; \
\
const type* get__ ## type(void* self){ \
    printf("get of REACT__%s was called\n", #type );\
    return &((REACT__ ## type*)self)->private_Name; \
} \
\
void set__ ## set(void* self, const type t){ \
    printf("set of REACT__%s was called\n", #type );\
    ((REACT__ ## type*)self)->private_Name = t; \
} \
\
REACT__ ## type (name) = {.private_Name = (initializer), \
                          .get = get__ ## type, \
                          .set = set__ ## set}; \

//{a+b/c << k}[a,b,c,k]
#define REXPR( code , conversionPoints )

// блокировка рекурсий

//struct {
//    void* buffer;
//    void(*func);
//};
//
//void s(){
//    if(!buffer){
//        (int)nuffer = 12;
//    }
//}



?????????????????????????//

//subscribe;
//unsubscribe;
//request;

static struct observable {
  void(*start)();
  void(*timer)(int);
  void(*repeat)();
  void(*range)(intmax_t,intmax_t);
  void(*just)();
  void(*interval)();
  void(*from)();