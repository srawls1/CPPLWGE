#pragma once

#include <inttypes.h>
#include <functional>

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef float f32;
typedef double f64;

typedef std::function<bool()> Predicate;
typedef std::function<void()> Action;

template <typename... Args>
typedef std::function<bool(Args)> Predicate<Args>;

template <typename... Args>
typedef std::function<void(Args)> Action<Args>;

template <typename T, typename... Args>
typedef std::function<T(Args)> Function<T(Args)>;
