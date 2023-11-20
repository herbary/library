#ifndef HERBARY_LIB_UTIL_SORT_H_INCLUDED
#define HERBARY_LIB_UTIL_SORT_H_INCLUDED

#include <stddef.h>
#include <stdint.h>

#include "herbary/lib/type/float.h"
#include "herbary/lib/type/sort_order.h"

#include "./int_sort.h"
#include "./float_sort.h"

#ifndef HERBARY_LIB_UTIL_SORT_H_NO_FUNCTION_MACROS
#define array_is_sorted_range(arr, begin, end, order) \
	_Generic((void (*)(__typeof__(arr), __typeof__(begin), __typeof__(end), __typeof__(order)))NULL, \
		void (*)(int8_t *, size_t, size_t, sort_order_t): int8_array_is_sorted_range, \
		void (*)(int16_t *, size_t, size_t, sort_order_t): int16_array_is_sorted_range, \
		void (*)(int32_t *, size_t, size_t, sort_order_t): int32_array_is_sorted_range, \
		void (*)(int64_t *, size_t, size_t, sort_order_t): int64_array_is_sorted_range, \
		void (*)(uint8_t *, size_t, size_t, sort_order_t): uint8_array_is_sorted_range, \
		void (*)(uint16_t *, size_t, size_t, sort_order_t): uint16_array_is_sorted_range, \
		void (*)(uint32_t *, size_t, size_t, sort_order_t): uint32_array_is_sorted_range, \
		void (*)(uint64_t *, size_t, size_t, sort_order_t): uint64_array_is_sorted_range, \
		void (*)(float32_t *, size_t, size_t, sort_order_t): float32_array_is_sorted_range, \
		void (*)(float64_t *, size_t, size_t, sort_order_t): float64_array_is_sorted_range, \
		void (*)(float128_t *, size_t, size_t, sort_order_t): float128_array_is_sorted_range \
	)(arr, begin, end, order)

#define array_is_sorted_range_ascendancy(arr, begin, end) \
	_Generic((void (*)(__typeof__(arr), __typeof__(begin), __typeof__(end)))NULL, \
		void (*)(int8_t *, size_t, size_t): int8_array_is_sorted_range_ascendancy, \
		void (*)(int16_t *, size_t, size_t): int16_array_is_sorted_range_ascendancy, \
		void (*)(int32_t *, size_t, size_t): int32_array_is_sorted_range_ascendancy, \
		void (*)(int64_t *, size_t, size_t): int64_array_is_sorted_range_ascendancy, \
		void (*)(uint8_t *, size_t, size_t): uint8_array_is_sorted_range_ascendancy, \
		void (*)(uint16_t *, size_t, size_t): uint16_array_is_sorted_range_ascendancy, \
		void (*)(uint32_t *, size_t, size_t): uint32_array_is_sorted_range_ascendancy, \
		void (*)(uint64_t *, size_t, size_t): uint64_array_is_sorted_range_ascendancy, \
		void (*)(float32_t *, size_t, size_t): float32_array_is_sorted_range_ascendancy, \
		void (*)(float64_t *, size_t, size_t): float64_array_is_sorted_range_ascendancy, \
		void (*)(float128_t *, size_t, size_t): float128_array_is_sorted_range_ascendancy \
	)(arr, begin, end)

#define array_is_sorted_range_descendancy(arr, begin, end) \
	_Generic((void (*)(__typeof__(arr), __typeof__(begin), __typeof__(end)))NULL, \
		void (*)(int8_t *, size_t, size_t): int8_array_is_sorted_range_descendancy, \
		void (*)(int16_t *, size_t, size_t): int16_array_is_sorted_range_descendancy, \
		void (*)(int32_t *, size_t, size_t): int32_array_is_sorted_range_descendancy, \
		void (*)(int64_t *, size_t, size_t): int64_array_is_sorted_range_descendancy, \
		void (*)(uint8_t *, size_t, size_t): uint8_array_is_sorted_range_descendancy, \
		void (*)(uint16_t *, size_t, size_t): uint16_array_is_sorted_range_descendancy, \
		void (*)(uint32_t *, size_t, size_t): uint32_array_is_sorted_range_descendancy, \
		void (*)(uint64_t *, size_t, size_t): uint64_array_is_sorted_range_descendancy, \
		void (*)(float32_t *, size_t, size_t): float32_array_is_sorted_range_descendancy, \
		void (*)(float64_t *, size_t, size_t): float64_array_is_sorted_range_descendancy, \
		void (*)(float128_t *, size_t, size_t): float128_array_is_sorted_range_descendancy \
	)(arr, begin, end)

#define array_is_sorted(arr, length, order) \
	_Generic((void (*)(__typeof__(arr), __typeof__(length), __typeof__(order)))NULL, \
		void (*)(int8_t *, size_t, sort_order_t): int8_array_is_sorted, \
		void (*)(int16_t *, size_t, sort_order_t): int16_array_is_sorted, \
		void (*)(int32_t *, size_t, sort_order_t): int32_array_is_sorted, \
		void (*)(int64_t *, size_t, sort_order_t): int64_array_is_sorted, \
		void (*)(uint8_t *, size_t, sort_order_t): uint8_array_is_sorted, \
		void (*)(uint16_t *, size_t, sort_order_t): uint16_array_is_sorted, \
		void (*)(uint32_t *, size_t, sort_order_t): uint32_array_is_sorted, \
		void (*)(uint64_t *, size_t, sort_order_t): uint64_array_is_sorted, \
		void (*)(float32_t *, size_t, sort_order_t): float32_array_is_sorted, \
		void (*)(float64_t *, size_t, sort_order_t): float64_array_is_sorted, \
		void (*)(float128_t *, size_t, sort_order_t): float128_array_is_sorted \
	)(arr, length, order)

#define array_is_sorted_ascendancy(arr, length) \
	_Generic((void (*)(__typeof__(arr), __typeof__(length)))NULL, \
		void (*)(int8_t *, size_t): int8_array_is_sorted_ascendancy, \
		void (*)(int16_t *, size_t): int16_array_is_sorted_ascendancy, \
		void (*)(int32_t *, size_t): int32_array_is_sorted_ascendancy, \
		void (*)(int64_t *, size_t): int64_array_is_sorted_ascendancy, \
		void (*)(uint8_t *, size_t): uint8_array_is_sorted_ascendancy, \
		void (*)(uint16_t *, size_t): uint16_array_is_sorted_ascendancy, \
		void (*)(uint32_t *, size_t): uint32_array_is_sorted_ascendancy, \
		void (*)(uint64_t *, size_t): uint64_array_is_sorted_ascendancy, \
		void (*)(float32_t *, size_t): float32_array_is_sorted_ascendancy, \
		void (*)(float64_t *, size_t): float64_array_is_sorted_ascendancy, \
		void (*)(float128_t *, size_t): float128_array_is_sorted_ascendancy \
	)(arr, length)

#define array_is_sorted_descendancy(arr, length) \
	_Generic((void (*)(__typeof__(arr), __typeof__(length)))NULL, \
		void (*)(int8_t *, size_t): int8_array_is_sorted_descendancy, \
		void (*)(int16_t *, size_t): int16_array_is_sorted_descendancy, \
		void (*)(int32_t *, size_t): int32_array_is_sorted_descendancy, \
		void (*)(int64_t *, size_t): int64_array_is_sorted_descendancy, \
		void (*)(uint8_t *, size_t): uint8_array_is_sorted_descendancy, \
		void (*)(uint16_t *, size_t): uint16_array_is_sorted_descendancy, \
		void (*)(uint32_t *, size_t): uint32_array_is_sorted_descendancy, \
		void (*)(uint64_t *, size_t): uint64_array_is_sorted_descendancy, \
		void (*)(float32_t *, size_t): float32_array_is_sorted_descendancy, \
		void (*)(float64_t *, size_t): float64_array_is_sorted_descendancy, \
		void (*)(float128_t *, size_t): float128_array_is_sorted_descendancy \
	)(arr, length)
#endif // HERBARY_LIB_UTIL_SORT_H_NO_FUNCTION_MACROS

#endif // HERBARY_LIB_UTIL_SORT_H_INCLUDED
