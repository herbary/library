#ifndef HERBARY_LIB_UTIL_META_COMPARE_H_INCLUDED
#define HERBARY_LIB_UTIL_META_COMPARE_H_INCLUDED

#include <stdint.h>

#include "herbary/lib/type/sort_order.h"

#define _HERBARY_LIB_UTIL_DECL_COMPARE_NO_GENERIC_FUNC(prefix, type) \
	int8_t prefix##_compare(const type n0, const type n1, const sort_order_t order); \
	int8_t prefix##_compare_ascendancy(const type n0, const type n1); \
	int8_t prefix##_compare_descendancy(const type n0, const type n1);

#define _HERBARY_LIB_UTIL_DECL_COMPARE_GENERIC_FUNC(prefix) \
	int8_t generic_##prefix##_compare(const void *const n0, const void *const n1, const sort_order_t order); \
	int8_t generic_##prefix##_compare_ascendancy(const void *const n0, const void *const n1); \
	int8_t generic_##prefix##_compare_descendancy(const void *const n0, const void *const n1);

#define _HERBARY_LIB_UTIL_DECL_COMPARE_FUNC(prefix, type) \
	_HERBARY_LIB_UTIL_DECL_COMPARE_NO_GENERIC_FUNC(prefix, type) \
	_HERBARY_LIB_UTIL_DECL_COMPARE_GENERIC_FUNC(prefix)

#define _HERBARY_LIB_UTIL_DEFN_COMPARE_NO_GENERIC_FUNC(prefix, type) \
	int8_t prefix##_compare(const type n0, const type n1, const sort_order_t order) { \
		const int32_t modifier = 1 - order; \
		return (int8_t)(modifier * (n0 > n1 ? 1 : (n0 < n1 ? -1 : 0))); \
	} \
	int8_t prefix##_compare_ascendancy(const type n0, const type n1) { \
		return prefix##_compare(n0, n1, SORT_ORDER_ASCENDANCY); \
	} \
	int8_t prefix##_compare_descendancy(const type n0, const type n1) {\
		return prefix##_compare(n0, n1, SORT_ORDER_DESCENDANCY); \
	}

#define _HERBARY_LIB_UTIL_DEFN_COMPARE_GENERIC_FUNC(prefix, type) \
	int8_t generic_##prefix##_compare(const void *const n0, const void *const n1, const sort_order_t order) { \
		return prefix##_compare(*(const type *)n0, *(const type *)n1, order); \
	} \
	int8_t generic_##prefix##_compare_ascendancy(const void *const n0, const void *const n1) { \
		return generic_##prefix##_compare(n0, n1, SORT_ORDER_ASCENDANCY); \
	} \
	int8_t generic_##prefix##_compare_descendancy(const void *const n0, const void *const n1) { \
		return generic_##prefix##_compare(n0, n1, SORT_ORDER_DESCENDANCY); \
	} \

#define _HERBARY_LIB_UTIL_DEFN_COMPARE_FUNC(prefix, type) \
	_HERBARY_LIB_UTIL_DEFN_COMPARE_NO_GENERIC_FUNC(prefix, type) \
	_HERBARY_LIB_UTIL_DEFN_COMPARE_GENERIC_FUNC(prefix, type)

#endif // HERBARY_LIB_UTIL_META_COMPARE_H_INCLUDED
