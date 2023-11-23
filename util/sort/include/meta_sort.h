#ifndef HERBARY_LIB_UTIL_META_SORT_H_INCLUDED
#define HERBARY_LIB_UTIL_META_SORT_H_INCLUDED

#include <stdbool.h>
#include <stddef.h>

#include "herbary/lib/type/sort_order.h"

#define _HERBARY_LIB_UTIL_DECL_IS_SORTED_FUNC(prefix, type) \
	bool prefix##_array_is_sorted_range(const size_t size, const type *const arr, size_t begin, size_t end, prefix##_order_compare_t *const compare_fnptr, const sort_order_t order); \
	bool prefix##_array_is_sorted_range_ascendancy(const size_t size, const type *const arr, const size_t begin, const size_t end, prefix##_order_compare_t *const compare_fnptr); \
	bool prefix##_array_is_sorted_range_descendancy(const size_t size, const type *const arr, const size_t begin, const size_t end, prefix##_order_compare_t *const compare_fnptr); \
	bool prefix##_array_is_sorted(const size_t size, const type *const arr, const size_t length, prefix##_order_compare_t *const compare_fnptr, const sort_order_t order); \
	bool prefix##_arary_is_sorted_ascendancy(const size_t size, const type *const arr, const size_t length, prefix##_order_compare_t *const compare_fnptr); \
	bool prefix##_array_is_sorted_descendancy(const size_t size, const type *const arr, const size_t length, prefix##_order_compare_t *const compare_fnptr);

#define _HERBARY_LIB_UTIL_DECL_IS_SORTED_NO_SIZE_PARAM_FUNC(prefix, type) \
	bool prefix##_array_is_sorted_range(const type *const arr, size_t begin, size_t end, const sort_order_t order); \
	bool prefix##_array_is_sorted_range_ascendancy(const type *const arr, const size_t begin, const size_t end); \
	bool prefix##_array_is_sorted_range_descendancy(const type *const arr, const size_t begin, const size_t end); \
	bool prefix##_array_is_sorted(const type *const arr, const size_t length, const sort_order_t order); \
	bool prefix##_array_is_sorted_ascendancy(const type *const arr, const size_t length); \
	bool prefix##_array_is_sorted_descendancy(const type *const arr, const size_t length);

#define _HERBARY_LIB_UTIL_DECL_SORT_FUNC(prefix, name, type) \
	bool prefix##_array_##name##_sort_range(const size_t size, type *const arr, size_t begin, size_t end, prefix##_order_compare_t *const compare_fnptr, const sort_order_t order); \
	bool prefix##_array_##name##_sort_range_ascendancy(const size_t size, type *const arr, const size_t begin, const size_t end, prefix##_order_compare_t *const compare_fnptr); \
	bool prefix##_array_##name##_sort_range_descendancy(const size_t size, type *const arr, const size_t begin, const size_t end, prefix##_order_compare_t *const compare_fnptr); \
	bool prefix##_array_##name##_sort_range_recursive(const size_t size, type *const arr, size_t begin, size_t end, prefix##_order_compare_t *const compare_fnptr, const sort_order_t order); \
	bool prefix##_array_##name##_sort_range_recursive_ascendancy(const size_t size, type *const arr, const size_t begin, const size_t end, prefix##_order_compare_t *const compare_fnptr); \
	bool prefix##_array_##name##_sort_range_recursive_descendancy(const size_t size, type *const arr, const size_t begin, const size_t end, prefix##_order_compare_t *const compare_fnptr); \
	bool prefix##_array_##name##_sort(const size_t size, type *const arr, const size_t length, prefix##_order_compare_t *const compare_fnptr, const sort_order_t order); \
	bool prefix##_array_##name##_sort_ascendancy(const size_t size, type *const arr, const size_t length, prefix##_order_compare_t *const compare_fnptr); \
	bool prefix##_array_##name##_sort_descendancy(const size_t size, type *const arr, const size_t length, prefix##_order_compare_t *const compare_fnptr); \
	bool prefix##_array_##name##_sort_recursive(const size_t size, type *const arr, const size_t length, prefix##_order_compare_t *const compare_fnptr, const sort_order_t order); \
	bool prefix##_array_##name##_sort_recursive_ascendancy(const size_t size, type *const arr, const size_t length, prefix##_order_compare_t *const compare_fnptr); \
	bool prefix##_array_##name##_sort_recursive_descendancy(const size_t size, type *const arr, const size_t length, prefix##_order_compare_t *const compare_fnptr);

#define _HERBARY_LIB_UTIL_DECL_SORT_NO_SIZE_PARAM_FUNC(prefix, name, type) \
	bool prefix##_array_##name##_sort_range(type *const arr, size_t begin, size_t end, const sort_order_t order); \
	bool prefix##_array_##name##_sort_range_ascendancy(type *const arr, const size_t begin, const size_t end); \
	bool prefix##_array_##name##_sort_range_descendancy(type *const arr, const size_t begin, const size_t end); \
	bool prefix##_array_##name##_sort_range_recursive(type *const arr, size_t begin, size_t end, const sort_order_t order); \
	bool prefix##_array_##name##_sort_range_recursive_ascendancy(type *const arr, const size_t begin, const size_t end); \
	bool prefix##_array_##name##_sort_range_recursive_descendancy(type *const arr, const size_t begin, const size_t end); \
	bool prefix##_array_##name##_sort(type *const arr, const size_t length, const sort_order_t order); \
	bool prefix##_array_##name##_sort_ascendancy(type *const arr, const size_t length); \
	bool prefix##_array_##name##_sort_descendancy(type *const arr, const size_t length); \
	bool prefix##_array_##name##_sort_recursive(type *const arr, const size_t length, const sort_order_t order); \
	bool prefix##_array_##name##_sort_recursive_ascendancy(type *const arr, const size_t length); \
	bool prefix##_array_##name##_sort_recursive_descendancy(type *const arr, const size_t length);

#define _HERBARY_LIB_UTIL_DEFN_IS_SORTED_NO_SIZE_PARAM_FUNC(prefix, type) \
	bool prefix##_array_is_sorted_range(const type *const arr, const size_t begin, const size_t end, const sort_order_t order) { \
		return generic_array_is_sorted_range(sizeof *arr, (const void *)arr, begin, end, &generic_##prefix##_compare, order); \
	} \
	bool prefix##_array_is_sorted_range_ascendancy(const type *const arr, const size_t begin, const size_t end) { \
		return prefix##_array_is_sorted_range(arr, begin, end, SORT_ORDER_ASCENDANCY); \
	} \
	bool prefix##_array_is_sorted_range_descendancy(const type *const arr, const size_t begin, const size_t end) { \
		return prefix##_array_is_sorted_range(arr, begin, end, SORT_ORDER_DESCENDANCY); \
	} \
	bool prefix##_array_is_sorted(const type *const arr, const size_t length, const sort_order_t order) { \
		return generic_array_is_sorted(sizeof *arr, arr, length, &generic_##prefix##_compare, order); \
	} \
	bool prefix##_array_is_sorted_ascendancy(const type *const arr, const size_t length) { \
		return prefix##_array_is_sorted(arr, length, SORT_ORDER_ASCENDANCY); \
	} \
	bool prefix##_array_is_sorted_descendancy(const type *const arr, const size_t length) { \
		return prefix##_array_is_sorted(arr, length, SORT_ORDER_DESCENDANCY); \
	}

#define _HERBARY_LIB_UTIL_DEFN_SORT_NO_SIZE_PARAM_FUNC(prefix, name, type) \
	bool prefix##_array_##name##_sort_range(type *const arr, const size_t begin, const size_t end, const sort_order_t order) { \
		return generic_array_##name##_sort_range(sizeof *arr, arr, begin, end, &generic_##prefix##_compare, order); \
	} \
	bool prefix##_array_##name##_sort_range_ascendancy(type *const arr, const size_t begin, const size_t end) { \
		return prefix##_array_##name##_sort_range(arr, begin, end, SORT_ORDER_ASCENDANCY); \
	} \
	bool prefix##_array_##name##_sort_range_descendancy(type *const arr, const size_t begin, const size_t end) { \
		return prefix##_array_##name##_sort_range(arr, begin, end, SORT_ORDER_ASCENDANCY); \
	} \
	bool prefix##_array_##name##_sort_range_recursive(type *const arr, const size_t begin, const size_t end, const sort_order_t order) { \
		return generic_array_##name##_sort_range_recursive(sizeof *arr, arr, begin, end, &generic_##prefix##_compare, order); \
	} \
	bool prefix##_array_##name##_sort_range_recursive_ascendancy(type *const arr, const size_t begin, const size_t end) { \
		return prefix##_array_##name##_sort_range_recursive(arr, begin, end, SORT_ORDER_ASCENDANCY); \
	} \
	bool prefix##_array_##name##_sort_range_recursive_descendancy(type *const arr, const size_t begin, const size_t end) { \
		return prefix##_array_##name##_sort_range_recursive(arr, begin, end, SORT_ORDER_DESCENDANCY); \
	} \
	bool prefix##_array_##name##_sort(type *const arr, const size_t length, const sort_order_t order) { \
		return generic_array_##name##_sort(sizeof *arr, (void *)arr, length, &generic_##prefix##_compare, order); \
	} \
	bool prefix##_array_##name##_sort_ascendancy(type *const arr, const size_t length) { \
		return prefix##_array_##name##_sort(arr, length, SORT_ORDER_ASCENDANCY); \
	} \
	bool prefix##_array_##name##_sort_descendancy(type *const arr, const size_t length) { \
		return prefix##_array_##name##_sort(arr, length, SORT_ORDER_DESCENDANCY); \
	} \
	bool prefix##_array_##name##_sort_recursive(type *const arr, const size_t length, const sort_order_t order) { \
		return generic_array_##name##_sort_recursive(sizeof *arr, arr, length, &generic_##prefix##_compare, order); \
	} \
	bool prefix##_array_##name##_sort_recursive_ascendancy(type *const arr, const size_t length) { \
		return prefix##_array_##name##_sort_recursive(arr, length, SORT_ORDER_ASCENDANCY); \
	} \
	bool prefix##_array_##name##_sort_recursive_descendancy(type *const arr, const size_t length) { \
		return prefix##_array_##name##_sort_recursive(arr, length, SORT_ORDER_DESCENDANCY); \
	}

#endif // HERBARY_LIB_UTIL_META_SORT_H_INCLUDED
