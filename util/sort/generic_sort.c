#include "./include/generic_sort.h"

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#include "herbary/lib/type/generic_compare.h"
#include "herbary/lib/type/sort_order.h"
#include "herbary/lib/util/size_swap.h"

bool generic_array_is_sorted_range(const size_t size, const void *const arr, size_t begin, size_t end, generic_order_compare_t *const compare_fnptr, const sort_order_t order) {
	if (!arr || size < 1) {
		return false;
	}
	if (begin == end || !compare_fnptr) {
		return true;
	}
	if (begin > end && !size_swap(&begin, &end)) {
		return false;
	}

	for (size_t i = begin + 1; i <= end; ++i) {
		const void *const prev_element = (const void *)((const int8_t *)arr + (i - 1) * size);
		const void *const curr_element = (const void *)((const int8_t *)arr + i * size);

		if ((*compare_fnptr)(prev_element, curr_element, order) > 0) {
			return false;
		}
	}

	return true;
}

bool generic_array_is_sorted_range_ascendancy(const size_t size, const void *const arr, const size_t begin, const size_t end, generic_order_compare_t *const compare_fnptr) {
	return generic_array_is_sorted_range(size, arr, begin, end, compare_fnptr, SORT_ORDER_ASCENDANCY);
}

bool generic_array_is_sorted_range_descendancy(const size_t size, const void *const arr, const size_t begin, const size_t end, generic_order_compare_t *const compare_fnptr) {
	return generic_array_is_sorted_range(size, arr, begin, end, compare_fnptr, SORT_ORDER_DESCENDANCY);
}

bool generic_array_is_sorted(const size_t size, const void *const arr, const size_t length, generic_order_compare_t *const compare_fnptr, const sort_order_t order) {
	if (!arr || size < 1) {
		return false;
	}
	if (length <= 1) {
		return true;
	}

	return generic_array_is_sorted_range(size, arr, 0, length - 1, compare_fnptr, order);
}

bool generic_arary_is_sorted_ascendancy(const size_t size, const void *const arr, const size_t length, generic_order_compare_t *const compare_fnptr) {
	return generic_array_is_sorted(size, arr, length, compare_fnptr, SORT_ORDER_ASCENDANCY);
}

bool generic_array_is_sorted_descendancy(const size_t size, const void *const arr, const size_t length, generic_order_compare_t *const compare_fnptr) {
	return generic_array_is_sorted(size, arr, length, compare_fnptr, SORT_ORDER_DESCENDANCY);
}
