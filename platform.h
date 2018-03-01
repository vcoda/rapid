#pragma once
#if !defined(_MSC_VER)
#include <cpuid.h>

#ifdef __cpuid
#undef __cpuid
#endif

#define __cpuid(cpu, func)\
	__cpuid_count(func, 0, cpu[0], cpu[1], cpu[2], cpu[3])
#define __cpuidex(cpu, func, subfunc)\
	__cpuid_count(func, 0, cpu[0], cpu[1], cpu[2], cpu[3])

#define _declspec(modifier)
#define __declspec(modifier)
#define __fastcall

#define align(alignment)
#define selectany

#endif // !_MSC_VER
