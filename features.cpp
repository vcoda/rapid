#if defined(_M_AMD64) || defined(__amd64__) || defined(__x86_64__)
#include <DirectXMath.h>
#ifndef XM_ALIGNED_DATA
#define XM_ALIGNED_DATA(x) // Stub define in case of DirectXMath.h incompatibility
#endif
#include "DirectXMath/Extensions/DirectXMathSSE3.h"
#include "DirectXMath/Extensions/DirectXMathSSE4.h"
#include "DirectXMath/Extensions/DirectXMathBE.h"
#include "DirectXMath/Extensions/DirectXMathAVX.h"
#include "DirectXMath/Extensions/DirectXMathAVX2.h"
#include "DirectXMath/Extensions/DirectXMathFMA3.h"
#include "DirectXMath/Extensions/DirectXMathFMA4.h"
#include "DirectXMath/Extensions/DirectXMathF16C.h"
#endif
#include "features.h"

namespace rapid
{
features::features() noexcept:
#if defined(_M_AMD64) || defined(__amd64__) || defined(__x86_64__)
    sse3(DirectX::SSE3::XMVerifySSE3Support()),
    ssse3(DirectX::SSSE3::XMVerifySSSE3Support()),
    sse4(DirectX::SSE4::XMVerifySSE4Support()),
    avx(DirectX::AVX::XMVerifyAVXSupport()),
    avx2(DirectX::AVX2::XMVerifyAVX2Support()),
    fma3(DirectX::FMA3::XMVerifyFMA3Support()),
    fma4(DirectX::FMA4::XMVerifyFMA4Support()),
    f16c(DirectX::F16C::XMVerifyF16CSupport())
#else
    sse3(false),
    ssse3(false),
    sse4(false),
    avx(false),
    avx2(false),
    fma3(false),
    fma4(false),
    f16c(false)
#endif // _M_AMD64 || __amd64__ || __x86_64__
{}
} // namespace rapid
