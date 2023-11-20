#ifndef HERBARY_LIB_UTIL_QUICK_SORT_H_INCLUDED
#define HERBARY_LIB_UTIL_QUICK_SORT_H_INCLUDED

#include <stddef.h>
#include <stdint.h>

#include "herbary/lib/type/float.h"
#include "herbary/lib/type/sort_order.h"

#include "./int_quick_sort.h"
#include "./float_quick_sort.h"

#ifndef HERBARY_LIB_UTIL_QUICK_SORT_H_NO_FUNCTION_MACROS
#define array_quick_sort_range(arr, begin, end, order) \
	_Generic((void (*)(__typeof__(arr), __typeof__(begin), __typeof__(end), __typeof__(order)))NULL, \
		void (*)(int8_t *, size_t, size_t, sort_order_t): int8_array_quick_sort_range, \
		void (*)(int16_t *, size_t, size_t, sort_order_t): int16_array_quick_sort_range, \
		void (*)(int32_t *, size_t, size_t, sort_order_t): int32_array_quick_sort_range, \
		void (*)(int64_t *, size_t, size_t, sort_order_t): int64_array_quick_sort_range, \
		void (*)(uint8_t *, size_t, size_t, sort_order_t): uint8_array_quick_sort_range, \
		void (*)(uint16_t *, size_t, size_t, sort_order_t): uint16_array_quick_sort_range, \
		void (*)(uint32_t *, size_t, size_t, sort_order_t): uint32_array_quick_sort_range, \
		void (*)(uint64_t *, size_t, size_t, sort_order_t): uint64_array_quick_sort_range, \
		void (*)(float32_t *, size_t, size_t, sort_order_t): float32_array_quick_sort_range, \
		void (*)(float64_t *, size_t, size_t, sort_order_t): float64_array_quick_sort_range, \
		void (*)(float128_t *, size_t, size_t, sort_order_t): float128_array_quick_sort_range \
	)(arr, begin, end, order)

#define array_quick_sort_range_ascendancy(arr, begin, end) \
	_Generic((void (*)(__typeof__(arr), __typeof__(begin), __typeof__(end)))NULL, \
		void (*)(int8_t *, size_t, size_t): int8_array_quick_sort_range_ascendancy, \
		void (*)(int16_t *, size_t, size_t): int16_array_quick_sort_range_ascendancy, \
		void (*)(int32_t *, size_t, size_t): int32_array_quick_sort_range_ascendancy, \
		void (*)(int64_t *, size_t, size_t): int64_array_quick_sort_range_ascendancy, \
		void (*)(uint8_t *, size_t, size_t): uint8_array_quick_sort_range_ascendancy, \
		void (*)(uint16_t *, size_t, size_t): uint16_array_quick_sort_range_ascendancy, \
		void (*)(uint32_t *, size_t, size_t): uint32_array_quick_sort_range_ascendancy, \
		void (*)(uint64_t *, size_t, size_t): uint64_array_quick_sort_range_ascendancy, \
		void (*)(float32_t *, size_t, size_t): float32_array_quick_sort_range_ascendancy, \
		void (*)(float64_t *, size_t, size_t): float64_array_quick_sort_range_ascendancy, \
		void (*)(float128_t *, size_t, size_t): float128_array_quick_sort_range_ascendancy \
	)(arr, begin, end)

#define array_quick_sort_range_descendancy(arr, begin, end) \
	_Generic((void (*)(__typeof__(arr), __typeof__(begin), __typeof__(end)))NULL, \
		void (*)(int8_t *, size_t, size_t): int8_array_quick_sort_range_descendancy, \
		void (*)(int16_t *, size_t, size_t): int16_array_quick_sort_range_descendancy, \
		void (*)(int32_t *, size_t, size_t): int32_array_quick_sort_range_descendancy, \
		void (*)(int64_t *, size_t, size_t): int64_array_quick_sort_range_descendancy, \
		void (*)(uint8_t *, size_t, size_t): uint8_array_quick_sort_range_descendancy, \
		void (*)(uint16_t *, size_t, size_t): uint16_array_quick_sort_range_descendancy, \
		void (*)(uint32_t *, size_t, size_t): uint32_array_quick_sort_range_descendancy, \
		void (*)(uint64_t *, size_t, size_t): uint64_array_quick_sort_range_descendancy, \
		void (*)(float32_t *, size_t, size_t): float32_array_quick_sort_range_descendancy, \
		void (*)(float64_t *, size_t, size_t): float64_array_quick_sort_range_descendancy, \
		void (*)(float128_t *, size_t, size_t): float128_array_quick_sort_range_descendancy \
	)(arr, begin, end)

#define array_quick_sort_range_recursive(arr, begin, end, order) \
	_Generic((void (*)(__typeof__(arr), __typeof__(begin), __typeof__(end), __typeof__(order)))NULL, \
		void (*)(int8_t *, size_t, size_t, sort_order_t): int8_array_quick_sort_range_recursive, \
		void (*)(int16_t *, size_t, size_t, sort_order_t): int16_array_quick_sort_range_recursive, \
		void (*)(int32_t *, size_t, size_t, sort_order_t): int32_array_quick_sort_range_recursive, \
		void (*)(int64_t *, size_t, size_t, sort_order_t): int64_array_quick_sort_range_recursive, \
		void (*)(uint8_t *, size_t, size_t, sort_order_t): uint8_array_quick_sort_range_recursive, \
		void (*)(uint16_t *, size_t, size_t, sort_order_t): uint16_array_quick_sort_range_recursive, \
		void (*)(uint32_t *, size_t, size_t, sort_order_t): uint32_array_quick_sort_range_recursive, \
		void (*)(uint64_t *, size_t, size_t, sort_order_t): uint64_array_quick_sort_range_recursive, \
		void (*)(float32_t *, size_t, size_t, sort_order_t): float32_array_quick_sort_range_recursive, \
		void (*)(float64_t *, size_t, size_t, sort_order_t): float64_array_quick_sort_range_recursive, \
		void (*)(float128_t *, size_t, size_t, sort_order_t): float128_array_quick_sort_range_recursive \
	)(arr, begin, end, order)

#define array_quick_sort_range_recursive_ascendancy(arr, begin, end) \
	_Generic((void (*)(__typeof__(arr), __typeof__(begin), __typeof__(end)))NULL, \
		void (*)(int8_t *, size_t, size_t): int8_array_quick_sort_range_recursive_ascendancy, \
		void (*)(int16_t *, size_t, size_t): int16_array_quick_sort_range_recursive_ascendancy, \
		void (*)(int32_t *, size_t, size_t): int32_array_quick_sort_range_recursive_ascendancy, \
		void (*)(int64_t *, size_t, size_t): int64_array_quick_sort_range_recursive_ascendancy, \
		void (*)(uint8_t *, size_t, size_t): uint8_array_quick_sort_range_recursive_ascendancy, \
		void (*)(uint16_t *, size_t, size_t): uint16_array_quick_sort_range_recursive_ascendancy, \
		void (*)(uint32_t *, size_t, size_t): uint32_array_quick_sort_range_recursive_ascendancy, \
		void (*)(uint64_t *, size_t, size_t): uint64_array_quick_sort_range_recursive_ascendancy, \
		void (*)(float32_t *, size_t, size_t): float32_array_quick_sort_range_recursive_ascendancy, \
		void (*)(float64_t *, size_t, size_t): float64_array_quick_sort_range_recursive_ascendancy, \
		void (*)(float128_t *, size_t, size_t): float128_array_quick_sort_range_recursive_ascendancy \
	)(arr, begin, end)

#define array_quick_sort_range_recursive_descendancy(arr, begin, end) \
	_Generic((void (*)(__typeof__(arr), __typeof__(begin), __typeof__(end)))NULL, \
		void (*)(int8_t *, size_t, size_t): int8_array_quick_sort_range_recursive_descendancy, \
		void (*)(int16_t *, size_t, size_t): int16_array_quick_sort_range_recursive_descendancy, \
		void (*)(int32_t *, size_t, size_t): int32_array_quick_sort_range_recursive_descendancy, \
		void (*)(int64_t *, size_t, size_t): int64_array_quick_sort_range_recursive_descendancy, \
		void (*)(uint8_t *, size_t, size_t): uint8_array_quick_sort_range_recursive_descendancy, \
		void (*)(uint16_t *, size_t, size_t): uint16_array_quick_sort_range_recursive_descendancy, \
		void (*)(uint32_t *, size_t, size_t): uint32_array_quick_sort_range_recursive_descendancy, \
		void (*)(uint64_t *, size_t, size_t): uint64_array_quick_sort_range_recursive_descendancy, \
		void (*)(float32_t *, size_t, size_t): float32_array_quick_sort_range_recursive_descendancy, \
		void (*)(float64_t *, size_t, size_t): float64_array_quick_sort_range_recursive_descendancy, \
		void (*)(float128_t *, size_t, size_t): float128_array_quick_sort_range_recursive_descendancy \
	)(arr, begin, end)

#define array_quick_sort(arr, length, order) \
	_Generic((void (*)(__typeof__(arr), __typeof__(length), __typeof__(order)))NULL, \
		void (*)(int8_t *, size_t, sort_order_t): int8_array_quick_sort, \
		void (*)(int16_t *, size_t, sort_order_t): int16_array_quick_sort, \
		void (*)(int32_t *, size_t, sort_order_t): int32_array_quick_sort, \
		void (*)(int64_t *, size_t, sort_order_t): int64_array_quick_sort, \
		void (*)(uint8_t *, size_t, sort_order_t): uint8_array_quick_sort, \
		void (*)(uint16_t *, size_t, sort_order_t): uint16_array_quick_sort, \
		void (*)(uint32_t *, size_t, sort_order_t): uint32_array_quick_sort, \
		void (*)(uint64_t *, size_t, sort_order_t): uint64_array_quick_sort, \
		void (*)(float32_t *, size_t, sort_order_t): float32_array_quick_sort, \
		void (*)(float64_t *, size_t, sort_order_t): float64_array_quick_sort, \
		void (*)(float128_t *, size_t, sort_order_t): float128_array_quick_sort \
	)(arr, length, order)

#define array_quick_sort_ascendancy(arr, length) \
	_Generic((void (*)(__typeof__(arr), __typeof__(length)))NULL, \
		void (*)(int8_t *, size_t): int8_array_quick_sort_ascendancy, \
		void (*)(int16_t *, size_t): int16_array_quick_sort_ascendancy, \
		void (*)(int32_t *, size_t): int32_array_quick_sort_ascendancy, \
		void (*)(int64_t *, size_t): int64_array_quick_sort_ascendancy, \
		void (*)(uint8_t *, size_t): uint8_array_quick_sort_ascendancy, \
		void (*)(uint16_t *, size_t): uint16_array_quick_sort_ascendancy, \
		void (*)(uint32_t *, size_t): uint32_array_quick_sort_ascendancy, \
		void (*)(uint64_t *, size_t): uint64_array_quick_sort_ascendancy, \
		void (*)(float32_t *, size_t): float32_array_quick_sort_ascendancy, \
		void (*)(float64_t *, size_t): float64_array_quick_sort_ascendancy, \
		void (*)(float128_t *, size_t): float128_array_quick_sort_ascendancy \
	)(arr, length)

#define array_quick_sort_descendancy(arr, length) \
	_Generic((void (*)(__typeof__(arr), __typeof__(length)))NULL, \
		void (*)(int8_t *, size_t): int8_array_quick_sort_descendancy, \
		void (*)(int16_t *, size_t): int16_array_quick_sort_descendancy, \
		void (*)(int32_t *, size_t): int32_array_quick_sort_descendancy, \
		void (*)(int64_t *, size_t): int64_array_quick_sort_descendancy, \
		void (*)(uint8_t *, size_t): uint8_array_quick_sort_descendancy, \
		void (*)(uint16_t *, size_t): uint16_array_quick_sort_descendancy, \
		void (*)(uint32_t *, size_t): uint32_array_quick_sort_descendancy, \
		void (*)(uint64_t *, size_t): uint64_array_quick_sort_descendancy, \
		void (*)(float32_t *, size_t): float32_array_quick_sort_descendancy, \
		void (*)(float64_t *, size_t): float64_array_quick_sort_descendancy, \
		void (*)(float128_t *, size_t): float128_array_quick_sort_descendancy \
	)(arr, length)

#define array_quick_sort_recursive(arr, length, order) \
	_Generic((void (*)(__typeof__(arr), __typeof__(length), __typeof__(order)))NULL, \
		void (*)(int8_t *, size_t, sort_order_t): int8_array_quick_sort_recursive, \
		void (*)(int16_t *, size_t, sort_order_t): int16_array_quick_sort_recursive, \
		void (*)(int32_t *, size_t, sort_order_t): int32_array_quick_sort_recursive, \
		void (*)(int64_t *, size_t, sort_order_t): int64_array_quick_sort_recursive, \
		void (*)(uint8_t *, size_t, sort_order_t): uint8_array_quick_sort_recursive, \
		void (*)(uint16_t *, size_t, sort_order_t): uint16_array_quick_sort_recursive, \
		void (*)(uint32_t *, size_t, sort_order_t): uint32_array_quick_sort_recursive, \
		void (*)(uint64_t *, size_t, sort_order_t): uint64_array_quick_sort_recursive, \
		void (*)(float32_t *, size_t, sort_order_t): float32_array_quick_sort_recursive, \
		void (*)(float64_t *, size_t, sort_order_t): float64_array_quick_sort_recursive, \
		void (*)(float128_t *, size_t, sort_order_t): float128_array_quick_sort_recursive \
	)(arr, length, order)

#define array_quick_sort_recursive_ascendancy(arr, length) \
	_Generic((void (*)(__typeof__(arr), __typeof__(length)))NULL, \
		void (*)(int8_t *, size_t): int8_array_quick_sort_recursive_ascendancy, \
		void (*)(int16_t *, size_t): int16_array_quick_sort_recursive_ascendancy, \
		void (*)(int32_t *, size_t): int32_array_quick_sort_recursive_ascendancy, \
		void (*)(int64_t *, size_t): int64_array_quick_sort_recursive_ascendancy, \
		void (*)(uint8_t *, size_t): uint8_array_quick_sort_recursive_ascendancy, \
		void (*)(uint16_t *, size_t): uint16_array_quick_sort_recursive_ascendancy, \
		void (*)(uint32_t *, size_t): uint32_array_quick_sort_recursive_ascendancy, \
		void (*)(uint64_t *, size_t): uint64_array_quick_sort_recursive_ascendancy, \
		void (*)(float32_t *, size_t): float32_array_quick_sort_recursive_ascendancy, \
		void (*)(float64_t *, size_t): float64_array_quick_sort_recursive_ascendancy, \
		void (*)(float128_t *, size_t): float128_array_quick_sort_recursive_ascendancy \
	)(arr, length)

#define array_quick_sort_recursive_descendancy(arr, length) \
	_Generic((void (*)(__typeof__(arr), __typeof__(length)))NULL, \
		void (*)(int8_t *, size_t): int8_array_quick_sort_recursive_descendancy, \
		void (*)(int16_t *, size_t): int16_array_quick_sort_recursive_descendancy, \
		void (*)(int32_t *, size_t): int32_array_quick_sort_recursive_descendancy, \
		void (*)(int64_t *, size_t): int64_array_quick_sort_recursive_descendancy, \
		void (*)(uint8_t *, size_t): uint8_array_quick_sort_recursive_descendancy, \
		void (*)(uint16_t *, size_t): uint16_array_quick_sort_recursive_descendancy, \
		void (*)(uint32_t *, size_t): uint32_array_quick_sort_recursive_descendancy, \
		void (*)(uint64_t *, size_t): uint64_array_quick_sort_recursive_descendancy, \
		void (*)(float32_t *, size_t): float32_array_quick_sort_recursive_descendancy, \
		void (*)(float64_t *, size_t): float64_array_quick_sort_recursive_descendancy, \
		void (*)(float128_t *, size_t): float128_array_quick_sort_recursive_descendancy \
	)(arr, length)
#endif // HERBARY_LIB_UTIL_QUICK_SORT_H_NO_FUNCTION_MACROS

#endif // HERBARY_LIB_UTIL_QUICK_SORT_H_INCLUDED
