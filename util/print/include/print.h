#ifndef HERBARY_LIB_UTIL_PRINT_H_INCLUDED
#define HERBARY_LIB_UTIL_PRINT_H_INCLUDED

#include <stddef.h>
#include <stdint.h>

#include "herbary/lib/type/float.h"

#include "./int_print.h"
#include "./float_print.h"

#ifndef HERBARY_LIB_UTIL_PRINT_H_NO_FUNCTION_MACROS
#define array_print_range(arr, begin, end) \
	_Generic((void (*)(__typeof__(arr), __typeof__(begin), __typeof__(end)))NULL, \
		void (*)(int8_t *, size_t, size_t): int8_array_print_range, \
		void (*)(int16_t *, size_t, size_t): int16_array_print_range, \
		void (*)(int32_t *, size_t, size_t): int32_array_print_range, \
		void (*)(int64_t *, size_t, size_t): int64_array_print_range, \
		void (*)(uint8_t *, size_t, size_t): uint8_array_print_range, \
		void (*)(uint16_t *, size_t, size_t): uint16_array_print_range, \
		void (*)(uint32_t *, size_t, size_t): uint32_array_print_range, \
		void (*)(uint64_t *, size_t, size_t): uint64_array_print_range, \
		void (*)(float32_t *, size_t, size_t): float32_array_print_range, \
		void (*)(float64_t *, size_t, size_t): float64_array_print_range, \
		void (*)(float128_t *, size_t, size_t): float128_array_print_range \
	)(arr, begin, end)

#define array_print(arr, length) \
	_Generic((void (*)(__typeof__(arr), __typeof__(length)))NULL, \
		void (*)(int8_t *, size_t): int8_array_print, \
		void (*)(int16_t *, size_t): int16_array_print, \
		void (*)(int32_t *, size_t): int32_array_print, \
		void (*)(int64_t *, size_t): int64_array_print, \
		void (*)(uint8_t *, size_t): uint8_array_print, \
		void (*)(uint16_t *, size_t): uint16_array_print, \
		void (*)(uint32_t *, size_t): uint32_array_print, \
		void (*)(uint64_t *, size_t): uint64_array_print, \
		void (*)(float32_t *, size_t): float32_array_print, \
		void (*)(float64_t *, size_t): float64_array_print, \
		void (*)(float128_t *, size_t): float128_array_print \
	)(arr, length)
#endif // HERBARY_LIB_UTIL_PRINT_H_NO_FUNCTION_MACROS

#endif // HERBARY_LIB_UTIL_PRINT_H_INCLUDED
