#include "./include/generic_merge_sort.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "herbary/lib/type/generic_compare.h"
#include "herbary/lib/type/sort_order.h"
#include "herbary/lib/util/size_swap.h"

static inline bool _generic_array_merge_sort_merge_blocks(const size_t size, void *const arr, const size_t begin, const size_t mid, const size_t end, generic_order_compare_t *const compare_fnptr, const sort_order_t order);

bool generic_array_merge_sort_range(const size_t size, void *const arr, size_t begin, size_t end, generic_order_compare_t *const compare_fnptr, const sort_order_t order) {
	if (!arr || size < 1) {
		return false;
	}
	if (begin == end || !compare_fnptr) {
		return true;
	}
	if (begin > end && !size_swap(&begin, &end)) {
		return false;
	}

	for (size_t block_size = 1; block_size <= end; block_size *= 2) {
		for (size_t block_begin = begin; block_begin <= end; block_begin += block_size * 2) {
			const size_t block_mid = min(block_begin + block_size - 1, end);
			const size_t block_end = min(block_begin + block_size * 2 - 1, end);

			if (!_generic_array_merge_sort_merge_blocks(size, arr, block_begin, block_mid, block_end, compare_fnptr, order)) {
				return false;
			}
		}
	}

	return true;
}

bool generic_array_merge_sort_range_ascendancy(const size_t size, void *const arr, const size_t begin, const size_t end, generic_order_compare_t *const compare_fnptr) {
	return generic_array_merge_sort_range(size, arr, begin, end, compare_fnptr, SORT_ORDER_ASCENDANCY);
}

bool generic_array_merge_sort_range_descendancy(const size_t size, void *const arr, const size_t begin, const size_t end, generic_order_compare_t *const compare_fnptr) {
	return generic_array_merge_sort_range(size, arr, begin, end, compare_fnptr, SORT_ORDER_DESCENDANCY);
}

bool generic_array_merge_sort_range_recursive(const size_t size, void *const arr, size_t begin, size_t end, generic_order_compare_t *const compare_fnptr, const sort_order_t order) {
	if (!arr || size < 1) {
		return false;
	}
	if (begin == end || !compare_fnptr) {
		return true;
	}
	if (begin > end && !size_swap(&begin, &end)) {
		return false;
	}

	const size_t mid = begin + (end - begin) / 2;

	return generic_array_merge_sort_range_recursive(size, arr, begin, mid, compare_fnptr, order)
			&& generic_array_merge_sort_range_recursive(size, arr, mid + 1, end, compare_fnptr, order)
			&& _generic_array_merge_sort_merge_blocks(size, arr, begin, mid, end, compare_fnptr, order);
}

bool generic_array_merge_sort_range_recursive_ascendancy(const size_t size, void *const arr, const size_t begin, const size_t end, generic_order_compare_t *const compare_fnptr) {
	return generic_array_merge_sort_range_recursive(size, arr, begin, end, compare_fnptr, SORT_ORDER_ASCENDANCY);
}

bool generic_array_merge_sort_range_recursive_descendancy(const size_t size, void *const arr, const size_t begin, const size_t end, generic_order_compare_t *const compare_fnptr) {
	return generic_array_merge_sort_range_recursive(size, arr, begin, end, compare_fnptr, SORT_ORDER_DESCENDANCY);
}

bool generic_array_merge_sort(const size_t size, void *const arr, const size_t length, generic_order_compare_t *const compare_fnptr, const sort_order_t order) {
	if (!arr || size < 1) {
		return false;
	}
	if (length <= 1) {
		return true;
	}

	return generic_array_merge_sort_range(size, arr, 0, length - 1, compare_fnptr, order);
}

bool generic_array_merge_sort_ascendancy(const size_t size, void *const arr, const size_t length, generic_order_compare_t *const compare_fnptr) {
	return generic_array_merge_sort(size, arr, length, compare_fnptr, SORT_ORDER_ASCENDANCY);
}

bool generic_array_merge_sort_descendancy(const size_t size, void *const arr, const size_t length, generic_order_compare_t *const compare_fnptr) {
	return generic_array_merge_sort(size, arr, length, compare_fnptr, SORT_ORDER_DESCENDANCY);
}

bool generic_array_merge_sort_recursive(const size_t size, void *const arr, const size_t length, generic_order_compare_t *const compare_fnptr, const sort_order_t order) {
	if (!arr || size < 1) {
		return false;
	}
	if (length <= 1) {
		return true;
	}

	return generic_array_merge_sort_range_recursive(size, arr, 0, length - 1, compare_fnptr, order);
}

bool generic_array_merge_sort_recursive_ascendancy(const size_t size, void *const arr, const size_t length, generic_order_compare_t *const compare_fnptr) {
	return generic_array_merge_sort_recursive(size, arr, length, compare_fnptr, SORT_ORDER_ASCENDANCY);
}

bool generic_array_merge_sort_recursive_descendancy(const size_t size, void *const arr, const size_t length, generic_order_compare_t *const compare_fnptr) {
	return generic_array_merge_sort_recursive(size, arr, length, compare_fnptr, SORT_ORDER_DESCENDANCY);
}

bool _generic_array_merge_sort_merge_blocks(const size_t size, void *const arr, const size_t begin, const size_t mid, const size_t end, generic_order_compare_t *const compare_fnptr, const sort_order_t order) {
	bool result = true;

	void *left_array = NULL;
	void *right_array = NULL;

	const size_t left_length = mid - begin + 1;
	left_array = malloc(size * left_length);
	if (left_length > 0 && !left_array) {
		result = false;
		goto cleanup;
	}

	const size_t right_length = end - mid;
	right_array = malloc(size * right_length);
	if (right_length > 0 && !right_array) {
		result = false;
		goto cleanup;
	}

	for (size_t i = 0; i < left_length; ++i) {
		void *const left_element_ptr = (void *)((int8_t *)left_array + i * size);
		void *const prim_element_ptr = (void *)((int8_t *)arr + (begin + i) * size);

		int err = memcpy_s(left_element_ptr, size, prim_element_ptr, size);
		if (err) {
			result = false;
			goto cleanup;
		}
	}
	for (size_t i = 0; i < right_length; ++i) {
		void *const right_element_ptr = (void *)((int8_t *)right_array + i * size);
		void *const prim_element_ptr = (void *)((int8_t *)arr + (mid + i + 1) * size);

		int err = memcpy_s(right_element_ptr, size, prim_element_ptr, size);
		if (err) {
			result = false;
			goto cleanup;
		}
	}

	size_t i = 0, j = 0, k = begin;
	while (i < left_length && j < right_length) {
		void *const prim_element_ptr = (void *)((int8_t *)arr + k++ * size);
		void *const left_element_ptr = (void *)((int8_t *)left_array + i * size);
		void *const right_element_ptr = (void *)((int8_t *)right_array + j * size);

		int err = 0;
		if ((*compare_fnptr)(left_element_ptr, right_element_ptr, order) <= 0) {
			err = memcpy_s(prim_element_ptr, size, left_element_ptr, size);
			++i;
		} else {
			err = memcpy_s(prim_element_ptr, size, right_element_ptr, size);
			++j;
		}

		if (err) {
			result = false;
			goto cleanup;
		}
	}

	while (i < left_length) {
		void *const prim_element_ptr = (void *)((int8_t *)arr + k++ * size);
		void *const left_element_ptr = (void *)((int8_t *)left_array + i++ * size);

		int err = memcpy_s(prim_element_ptr, size, left_element_ptr, size);
		if (err) {
			result = false;
			goto cleanup;
		}
	}
	while (j < right_length) {
		void *const prim_element_ptr = (void *)((int8_t *)arr + k++ * size);
		void *const right_element_ptr = (void *)((int8_t *)right_array + j++ * size);

		int err = memcpy_s(prim_element_ptr, size, right_element_ptr, size);
		if (err) {
			result = false;
			goto cleanup;
		}
	}

cleanup:
	free(left_array);
	free(right_array);

	return result;
}
