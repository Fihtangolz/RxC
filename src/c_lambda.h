#ifndef RXC_C_LAMBDA_H
#define RXC_C_LAMBDA_H

#include <boost/preprocessor.hpp>

#if !(defined(__GNUC__) || defined(__GNUG__) || defined(__clang__))
    #warning "work on your compiler is not guaranteed"
#endif

//__auto_type

#define MACRO(r, data, i, elem) BOOST_PP_CAT(elem, BOOST_PP_CAT(data, i))
#define LAMBDA(campture_list, args) BOOST_PP_SEQ_FOR_EACH_I(MACRO, _, campture_list)

#endif //RXC_C_LAMBDA_H
