#pragma once
#include "platform.h"
#ifdef _MSC_VER
#define _XM_AVX_INTRINSICS_
#define _XM_F16C_INTRINSICS_
#else
#define _XM_NO_INTRINSICS_
#define _XM_NO_XMVECTOR_OVERLOADS_
#endif
#include "DirectXMath/Inc/DirectXMath.h"
#include "DirectXMath/Inc/DirectXPackedVector.h"

using namespace DirectX;

namespace rapid
{
    typedef XMFLOAT2 float2;
    typedef XMFLOAT2A float2a;
    typedef XMINT2 int2;
    typedef XMUINT2 uint2;
    typedef XMFLOAT3 float3;
    typedef XMFLOAT3A float3a;
    typedef XMINT3 int3;
    typedef XMUINT3 uint3;
    typedef XMFLOAT4 float4;
    typedef XMFLOAT4A float4a;
    typedef XMINT4 int4;
    typedef XMUINT4 uint4;

    typedef PackedVector::HALF half;
    typedef PackedVector::XMHALF2 half2;
    typedef PackedVector::XMHALF4 half4;

    typedef XMFLOAT3X3 float3x3;
    typedef XMFLOAT4X3 float4x3;
    typedef XMFLOAT4X3A float4x3a;
    typedef XMFLOAT4X4 float4x4;
    typedef XMFLOAT4X4A float4x4a;

    union flint
    {
        int i;
        float f;
    };

    namespace constants
    {
        constexpr float exp = 2.718281828f;
        constexpr float pi = XM_PI;
        constexpr float twoPi = XM_2PI;
        constexpr float invPi = XM_1DIVPI;
        constexpr float invTwoPi = XM_1DIV2PI;
        constexpr float halfPi = XM_PIDIV2;
        constexpr float fourthPi = XM_PIDIV4;
        constexpr float sqrtTwo = 1.414213562f;
        constexpr float invSqrtTwo = 0.707106781f;
        constexpr float epsilon = 1e-6f;
    } // namespace constants

    inline bool aligned(const void *p) noexcept
    {
        return (reinterpret_cast<uintptr_t>(p) & 15ULL) == 0;
    }
} // namespace rapid

#include "vector.h"
#include "vector2.h"
#include "vector3.h"
#include "vector4.h"
#include "matrix.h"
#include "quaternion.h"
#include "plane.h"
#include "vector.inl"
#include "matrix.inl"
#include "quaternion.inl"
#include "sincos.inl"
#include "sqrt.inl"
#include "minmax.inl"
#include "half.inl"
#include "misc.inl"
#include "popcnt.inl"
