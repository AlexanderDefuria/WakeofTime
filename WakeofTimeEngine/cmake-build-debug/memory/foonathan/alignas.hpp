// This file was autogenerated using foonathan/compatibility.
// See https://github.com/foonathan/compatibility for further information.
// Do not edit manually!

#ifndef COMP_FOONATHAN_ALIGNAS_HPP_INCLUDED
#define COMP_FOONATHAN_ALIGNAS_HPP_INCLUDED

#include <cstddef>

#define FOONATHAN_HAS_ALIGNAS 1




#ifndef FOONATHAN_ALIGNAS
    #if FOONATHAN_HAS_ALIGNAS
        #define FOONATHAN_ALIGNAS(X) alignas(X)
    #elif defined(_MSC_VER)
        #define FOONATHAN_ALIGNAS(X) __declspec(align(X))
    #elif defined(__GNUC__)
        #define FOONATHAN_ALIGNAS(X)  __attribute__((__aligned__(X)))
    #else
        #error "no alignas replacement available"
    #endif
#endif

#endif