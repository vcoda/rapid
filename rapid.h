#pragma once
#include "platform.h"
#ifdef _MSC_VER
#define _XM_AVX2_INTRINSICS_
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
        constexpr float pi = 3.14159265358979323846f;
        constexpr float two_pi = 2.f * pi;
        constexpr float half_pi = pi / 2.f;
        constexpr float fourth_pi = pi / 4.f;
        constexpr float eps = 1e-6f;
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

namespace rapid
{
    inline constexpr float radians(const float degrees)
        { return XMConvertToRadians(degrees); }
    inline constexpr float degrees(const float radians)
        { return XMConvertToDegrees(radians); }
} // namespace rapid
