#ifndef RXC_C_LAMBDA_H
#define RXC_C_LAMBDA_H

#include <boost/preprocessor.hpp>

//call a function without putting anything on stack
#define JUST_CALL(func_name) ((void(*)())(func_name))()

#define LAMBDA(l_ret_type, l_arguments, l_body)         \
  ({                                                    \
    l_ret_type l_anonymous_functions_name l_arguments   \
      l_body                                            \
    &l_anonymous_functions_name;                        \
  })

#endif //RXC_C_LAMBDA_H
