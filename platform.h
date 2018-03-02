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
#define __cpuid(cpu, func)\
	__cpuid_count(func, 0, cpu[0], cpu[1], cpu[2], cpu[3])

#ifdef __cpuidex
#undef __cpuidex
#endif
// TODO: subfunc
#define __cpuidex(cpu, func, subfunc)\
	__cpuid_count(func, 0, cpu[0], cpu[1], cpu[2], cpu[3])

#endif // !_MSC_VER
