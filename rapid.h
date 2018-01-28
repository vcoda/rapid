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
} // namespace rapid

#include "vector.h"
#include "vector2.h"
#include "vector3.h"
#include "vector4.h"
#include "matrix.h"
#include "vector.inl"
#include "matrix.inl"
#include "quaternion.h"
#include "quaternion.inl"
#include "sincos.inl"

namespace rapid
{
    inline float radians(const float degrees) { return XMConvertToRadians(degrees); }
    inline float degrees(const float radians) { return XMConvertToDegrees(radians); }
} // namespace rapid
