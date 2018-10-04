#ifndef RXC_C_LAMBDA_H
#define RXC_C_LAMBDA_H

#include <boost/preprocessor.hpp>

#if !(defined(__GNUC__) || defined(__GNUG__) || defined(__clang__))
    #error "your's compiler not supported"
#endif

//call a function without putting anything on stack
#define JUST_CALL(func_name) ((void(*)())(func_name))()

#define LAMBDA(campture_list, args) BOOST_PP_SEQ_FOR_EACH_I(MACRO, _, campture_list)

#endif //RXC_C_LAMBDA_H
