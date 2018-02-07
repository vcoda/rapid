#pragma once
#define _XM_AVX2_INTRINSICS_
#include "DirectXMath/Inc/DirectXMath.h"

using namespace DirectX;

namespace rapid
{
    typedef XMFLOAT2 float2;
    typedef XMFLOAT2A float2a;
    typedef XMFLOAT3 float3;
    typedef XMFLOAT3A float3a;
    typedef XMFLOAT4 float4;
    typedef XMFLOAT4A float4a;

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

namespace rapid
{
    inline float radians(const float degrees) { return XMConvertToRadians(degrees); }
    inline float degrees(const float radians) { return XMConvertToDegrees(radians); }

    template<typename T> inline T min(const T& a, const T& b) { return a < b ? a : b; }
    template<typename T> inline T max(const T& a, const T& b) { return a > b ? a : b; }
} // namespace rapid
