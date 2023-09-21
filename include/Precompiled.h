#pragma once

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef float f32;
typedef double f64;

#define NO_UNKNOWN 1

#if NO_UNKNOWN
    #define NO_UNKNOWN_PLATFORM 1
    #define NO_UNKNOWN_COMPILER 1
#else
    // Edit these separately if needed
    #define NO_UNKNOWN_PLATFORM 0
    #define NO_UNKNOWN_COMPILER 0
#endif

#ifdef _WIN32
    /* Windows x64/x86 */
    #ifdef _WIN64
        /* Windows x64  */
        #define PLATFORM_WINDOWS
    #else
        /* Windows x86 */
        #error "x86 Builds are not supported!"
    #endif
#elif defined(__APPLE__) || defined(__MACH__)
    #include <TargetConditionals.h>
    /* TARGET_OS_MAC exists on all the platforms
     * so we must check all of them (in this order)
     * to ensure that we're running on MAC
     * and not some other Apple platform */
    #if TARGET_IPHONE_SIMULATOR == 1
        #error "IOS simulator is not supported!"
    #elif TARGET_OS_IPHONE == 1
        #error "IOS is not supported!"
    #elif TARGET_OS_MAC == 1
        #define PLATFORM_MACOS
    #else
        #error "Unknown Apple platform!"
    #endif
/* We also have to check __ANDROID__ before __linux__
 * since android is based on the linux kernel
 * it has __linux__ defined */
#elif defined(__ANDROID__)
    #error "Android is not supported!"
#elif defined(__linux__)
    #define PLATFORM_LINUX
#elif defined(SWIG)
    #define PLATFORM_SWIG
#else
    /* Unknown compiler/platform */
    #if NO_UNKNOWN_PLATFORM
        #error "Unknown platform!"
    #else
        #define PLATFORM_UNKNOWN
    #endif
#endif

// End of platform detection

#if defined(__clang__)
    #define COMPILER_CLANG
#elif defined(__GNUC__) || defined(__GNUG__)
    #define COMPILER_GCC
#elif defined(_MSC_VER)
    #define COMPILER_MSVC
#elif defined(SWIG)
#else
    #if NO_UNKNOWN_COMPILER
        #error "Unsupported compiler"
    #else
        #define COMPILER_UNKNOWN
    #endif
#endif

#ifndef NDEBUG
    #define DEBUG 1
#endif

#define STRINGIFY(x) #x

#define BIT(x) (1 << x)

#ifdef PLATFORM_WINDOWS
    #define FUNC_SIG __FUNCSIG__
#else
    #define FUNC_SIG __PRETTY_FUNCTION__
#endif
