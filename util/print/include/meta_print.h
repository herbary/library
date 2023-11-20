#ifndef HERBARY_LIB_UTIL_META_PRINT_H_INCLUDED
#define HERBARY_LIB_UTIL_META_PRINT_H_INCLUDED

#include <stddef.h>
#include <stdio.h>

#include "herbary/lib/util/size_swap.h"

#define _DEFN_PRINT_FUNC(prefix, type) \
	void prefix##_array_print_range(const type *const arr, size_t begin, size_t end); \
	void prefix##_array_print(const type *const arr, const size_t length);

#define _DECL_PRINT_FUNC(prefix, format, type) \
	void prefix##_array_print_range(const type *const arr, size_t begin, size_t end) { \
		if (!arr) { \
			return; \
		} \
		if (begin > end && !size_swap(&begin, &end)) { \
			return; \
		} \
		printf("[" #format, arr[begin]); \
		for (size_t i = begin + 1; i <= end; ++i) { \
			printf(", " #format, arr[i]); \
		} \
		printf("]\n"); \
	} \
	void prefix##_array_print(const type *const arr, const size_t length) { \
		prefix##_array_print_range(arr, 0, length - 1); \
	}

#endif // HERBARY_LIB_UTIL_META_PRINT_H_INCLUDED
