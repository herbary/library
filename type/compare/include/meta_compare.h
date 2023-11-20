#ifndef HERBARY_LIB_TYPE_META_COMPARE_H_INCLUDED
#define HERBARY_LIB_TYPE_META_COMPARE_H_INCLUDED

#include <stdint.h>

#include "herbary/lib/type/sort_order.h"

#define _HERBARY_LIB_TYPE_DEFN_COMPARE_NO_GENERIC_FUNC_TYPE(prefix, type) \
	typedef int8_t (prefix##_order_compare_t)(const type, const type, const sort_order_t); \
	typedef int8_t (prefix##_compare_t)(const type, const type);

#define _HERBARY_LIB_TYPE_DEFN_COMPARE_GENERIC_FUNC_TYPE(prefix) \
	typedef int8_t (generic_##prefix##_order_compare_t)(const void *const, const void* const, const sort_order_t); \
	typedef int8_t (generic_##prefix##_compare_t)(const void *const, const void *const);

#define _HERBARY_LIB_TYPE_DEFN_COMPARE_FUNC_TYPE(prefix, type) \
	_HERBARY_LIB_TYPE_DEFN_COMPARE_NO_GENERIC_FUNC_TYPE(prefix, type) \
	_HERBARY_LIB_TYPE_DEFN_COMPARE_GENERIC_FUNC_TYPE(prefix)

#endif // HERBARY_LIB_TYPE_META_COMPARE_H_INCLUDED
