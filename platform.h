#pragma once
#if !defined(_MSC_VER)

#ifndef align
#define align(size) // aligned(size) // warning: attribute ignored
#endif

#ifndef selectany
#define selectany weak
#endif

#ifndef __declspec
#define __declspec(modifier) __attribute__((modifier))
#define _declspec(modifier) __declspec(modifier)
#endif

#ifndef __fastcall
#define __fastcall // fastcall // warning: attribute ignored
#endif

#include <cpuid.h>

#ifdef __cpuid
#undef __cpuid
#endif
#define __cpuid(reg, leaf)\
    __cpuid_count(leaf, 0, reg[0], reg[1], reg[2], reg[3])

#ifdef __cpuidex
#undef __cpuidex
#endif
#define __cpuidex(reg, leaf, subleaf)\
    __cpuid_count(leaf, subleaf, reg[0], reg[1], reg[2], reg[3])

#endif // !_MSC_VER
