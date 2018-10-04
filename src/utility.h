#ifndef RXC_UTILITY_H
#define RXC_UTILITY_H

#include <boost/preprocessor/seq/for_each.hpp>
#include <boost/preprocessor/variadic/to_seq.hpp>
#include <boost/preprocessor/stringize.hpp>

#define APPLY_TO_ALL(func, el, ...) \
     BOOST_PP_SEQ_FOR_EACH( \
		func, el, \
		BOOST_PP_VARIADIC_TO_SEQ(__VA_ARGS__) \
	) \

#define FUNC_DEF(ret_type, name, args) \
typedef ret_type (*func_ ## name ## _t)(args); \
ret_type name(args) \

#define CRT_ONE_FIELD(_1, _2, name) BOOST_PP_CAT(BOOST_PP_CAT(func_, name),_t) name;
#define FIELDS_CRT(...) APPLY_TO_ALL(CRT_ONE_FIELD, _, __VA_ARGS__)

//TODO рефакторинг
#define DOT =
#define INIT_ONE_FIELD(_1, _2, name) BOOST_PP_CAT(BOOST_PP_CAT(BOOST_PP_CAT(DOT,name),=),name)
#define FIELDS_INIT(...) APPLY_TO_ALL(INIT_ONE_FIELD, _, __VA_ARGS__)

#define CALL_CHAINE(...)

#endif //RXC_UTILITY_H
