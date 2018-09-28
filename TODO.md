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
  
  
  ////    LAMBDA((int,a)(int,b)(char,f),(int c, int k),{
  ////
  ////    });
  //
  //    void (^fg)() = ^{
  //        for (int i = 0; i < 100; i++)
  //            printf("%d\n", i);
  //    };
  //    fg();
  
  Add like test 
  //    INST_OF(test, t1);
  //    INST_OF(test2, ff);
  //    printf("%s\n",rt_typeof(&test));
  //    printf("%s\n",t1.type);
  //    printf("%s\n",ff.type);