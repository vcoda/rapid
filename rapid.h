#pragma once
#include "platform.h"
#ifdef _MSC_VER
#define _XM_AVX_INTRINSICS_
#else
#define _XM_NO_INTRINSICS_
#define _XM_NO_XMVECTOR_OVERLOADS_
#endif
#include "DirectXMath/Inc/DirectXMath.h"

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
#include "minmax.inl"
#include "misc.inl"
