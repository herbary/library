#include "./include/generic_swap.h"

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

bool generic_swap(const size_t size, void *const n0, void *const n1) {
	void *const temp = malloc(size);
	if (!temp) {
		return false;
	}

	memcpy(temp, n0, size);
	memcpy(n0, n1, size);
	memcpy(n1, temp, size);

	free(temp);

	return true;
}

bool generic_array_swap_indices(const size_t size, void *const arr, const size_t i0, const size_t i1) {
	return generic_swap(size, (void *)((int8_t *)arr + i0 * size), (void *)((int8_t *)arr + i1 * size));
}
