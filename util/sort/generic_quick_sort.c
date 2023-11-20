#include "./include/generic_quick_sort.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "herbary/lib/type/generic_compare.h"
#include "herbary/lib/type/sort_order.h"
#include "herbary/lib/util/generic_swap.h"
#include "herbary/lib/util/size_swap.h"

static inline bool _generic_array_quick_sort_swap_partition(const size_t size, void *const arr, const size_t begin, const size_t end, generic_order_compare_t *const compare_fnptr, const sort_order_t order, size_t *result_ptr);

bool generic_array_quick_sort_range(const size_t size, void *const arr, size_t begin, size_t end, generic_order_compare_t *const compare_fnptr, const sort_order_t order) {
	if (!arr || size < 1) {
		return false;
	}
	if (begin == end || !compare_fnptr) {
		return true;
	}
	if (begin > end && !size_swap(&begin, &end)) {
		return false;
	}

	size_t *const stack = (size_t *)malloc(sizeof *stack * (end - begin + 4));
	if (!stack) {
		return false;
	}

	bool result = true;

	size_t p = 0;

	stack[p++] = end;
	stack[p++] = begin;

	do {
		const size_t local_begin = stack[--p];
		const size_t local_end = stack[--p];

		if (local_begin >= local_end) {
			continue;
		}

		size_t part_end = 0;
		if (!_generic_array_quick_sort_swap_partition(size, arr, local_begin, local_end, compare_fnptr, order, &part_end)) {
			result = false;
			goto cleanup;
		}

		if (!part_end) {
			continue;
		}

		stack[p++] = part_end - 1;
		stack[p++] = local_begin;
		stack[p++] = local_end;
		stack[p++] = part_end + 1;
	} while(p);

cleanup:
	free((void *)stack);

	return result;
}

bool generic_array_quick_sort_range_ascendancy(const size_t size, void *const arr, const size_t begin, const size_t end, generic_order_compare_t *const compare_fnptr) {
	return generic_array_quick_sort_range(size, arr, begin, end, compare_fnptr, SORT_ORDER_ASCENDANCY);
}

bool generic_array_quick_sort_range_descendancy(const size_t size, void *const arr, const size_t begin, const size_t end, generic_order_compare_t *const compare_fnptr) {
	return generic_array_quick_sort_range(size, arr, begin, end, compare_fnptr, SORT_ORDER_DESCENDANCY);
}

static inline bool _generic_array_quick_sort_range_recursive(const size_t size, void *const arr, const size_t begin, const size_t end, generic_order_compare_t *const compare_fnptr, const sort_order_t order);

bool generic_array_quick_sort_range_recursive(const size_t size, void *const arr, size_t begin, size_t end, generic_order_compare_t *const compare_fnptr, const sort_order_t order) {
	if (!arr || size < 1) {
		return false;
	}
	if (begin == end) {
		return true;
	}
	if (begin > end && !size_swap(&begin, &end)) {
		return false;
	}

	return _generic_array_quick_sort_range_recursive(size, arr, begin, end, compare_fnptr, order);
}

bool generic_array_quick_sort_range_recursive_ascendancy(const size_t size, void *const arr, const size_t begin, const size_t end, generic_order_compare_t *const compare_fnptr) {
	return generic_array_quick_sort_range_recursive(size, arr, begin, end, compare_fnptr, SORT_ORDER_ASCENDANCY);
}

bool generic_array_quick_sort_range_recursive_descendancy(const size_t size, void *const arr, const size_t begin, const size_t end, generic_order_compare_t *const compare_fnptr) {
	return generic_array_quick_sort_range_recursive(size, arr, begin, end, compare_fnptr, SORT_ORDER_DESCENDANCY);
}

bool generic_array_quick_sort(const size_t size, void *const arr, const size_t length, generic_order_compare_t *const compare_fnptr, const sort_order_t order) {
	if (!arr || size < 1) {
		return false;
	}
	if (length <= 1) {
		return true;
	}

	return generic_array_quick_sort_range(size, arr, 0, length - 1, compare_fnptr, order);
}

bool generic_array_quick_sort_ascendancy(const size_t size, void *const arr, const size_t length, generic_order_compare_t *const compare_fnptr) {
	return generic_array_quick_sort(size, arr, length, compare_fnptr, SORT_ORDER_ASCENDANCY);
}

bool generic_array_quick_sort_descendancy(const size_t size, void *const arr, const size_t length, generic_order_compare_t *const compare_fnptr) {
	return generic_array_quick_sort(size, arr, length, compare_fnptr, SORT_ORDER_DESCENDANCY);
}

bool generic_array_quick_sort_recursive(const size_t size, void *const arr, const size_t length, generic_order_compare_t *const compare_fnptr, const sort_order_t order) {
	if (!arr || size < 1) {
		return false;
	}
	if (length <= 1) {
		return true;
	}

	return generic_array_quick_sort_range_recursive(size, arr, 0, length - 1, compare_fnptr, order);
}

bool generic_array_quick_sort_recursive_ascendancy(const size_t size, void *const arr, const size_t length, generic_order_compare_t *const compare_fnptr) {
	return generic_array_quick_sort_recursive(size, arr, length, compare_fnptr, SORT_ORDER_ASCENDANCY);
}

bool generic_array_quick_sort_recursive_descendancy(const size_t size, void *const arr, const size_t length, generic_order_compare_t *const compare_fnptr) {
	return generic_array_quick_sort_recursive(size, arr, length, compare_fnptr, SORT_ORDER_DESCENDANCY);
}

bool _generic_array_quick_sort_range_recursive(const size_t size, void *const arr, const size_t begin, const size_t end, generic_order_compare_t *const compare_fnptr, const sort_order_t order) {
	if (begin >= end) {
		return true;
	}

	size_t part_end = 0;
	if (!_generic_array_quick_sort_swap_partition(size, arr, begin, end, compare_fnptr, order, &part_end)) {
		return false;
	}

	if (!part_end) {
		return true;
	}

	return _generic_array_quick_sort_range_recursive(size, arr, begin, part_end - 1, compare_fnptr, order)
			&& _generic_array_quick_sort_range_recursive(size, arr, part_end + 1, end, compare_fnptr, order);
}

bool _generic_array_quick_sort_swap_partition(const size_t size, void *const arr, const size_t begin, const size_t end, generic_order_compare_t *const compare_fnptr, const sort_order_t order, size_t *result_ptr) {
	void *const pivot_ptr = malloc(size);
	if (!pivot_ptr) {
		return false;
	}

	bool result = true;

	int err = memcpy_s(pivot_ptr, size, (void *)((int8_t *)arr + end * size), size);
	if (err) {
		result = false;
		goto cleanup;
	}

	size_t part_end = begin;
	for (size_t i = begin; i < end; ++i) {
		const void *const element_ptr = (void *)((int8_t *)arr + i * size);
		if ((*compare_fnptr)(element_ptr, pivot_ptr, order) > 0) {
			continue;
		}

		if (!generic_array_swap_indices(size, arr, i, part_end++)) {
			result = false;
			goto cleanup;
		}
	}
	if (!generic_array_swap_indices(size, arr, part_end, end)) {
		result = false;
		goto cleanup;
	}

	*result_ptr = part_end;

cleanup:
	free(pivot_ptr);

	return result;
}
