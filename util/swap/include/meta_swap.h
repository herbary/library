#ifndef HERBARY_LIB_UTIL_META_SWAP_H_INCLUDED
#define HERBARY_LIB_UTIL_META_SWAP_H_INCLUDED

#include <stdbool.h>
#include <stddef.h>

#define _HERBARY_LIB_UTIL_DECL_SWAP_FUNC(prefix, type) \
	bool prefix##_swap(const size_t size, type *const n0, type *const n1); \
	bool prefix##_array_swap_indices(const size_t size, type *const arr, const size_t i0, const size_t i1);

#define _HERBARY_LIB_UTIL_DECL_SWAP_NO_SIZE_PARAM_FUNC(prefix, type) \
	bool prefix##_swap(type *const n0, type *const n1); \
	bool prefix##_array_swap_indices(type *const arr, const size_t i0, const size_t i1);

#define _HERBARY_LIB_UTIL_DEFN_SWAP_NO_SIZE_PARAM_FUNC(prefix, type) \
	bool prefix##_swap(type *const n0, type *const n1) { \
		return generic_swap(sizeof *n0, (void *)n0, (void *)n1); \
	} \
	bool prefix##_array_swap_indices(type *const arr, const size_t i0, const size_t i1) { \
		return generic_array_swap_indices(sizeof *arr, arr, i0, i1); \
	}

#endif // HERBARY_LIB_UTIL_META_SWAP_H_INCLUDED
