#include "lut/isqrt.h"

namespace rapid
{   // https://github.com/id-Software/DOOM-3/blob/master/neo/idlib/math/Math.h
    inline float isqrtEst(const float x) noexcept
    {
        constexpr int expPos = 23, expBias = 127;
        constexpr int lookupBits = 8;
        constexpr int lookupPos = expPos - lookupBits;
        constexpr int seedPos = expPos - 8;
        constexpr int lutSize = 2 << lookupBits;
        constexpr int lookupMask = lutSize - 1;
        const uint32_t i = ((const flint*)(&x))->i;
        const double y = (double)x * .5f;
        flint seed;
        seed.i = ((((3 * expBias - 1) - ((i >> expPos) & 0xFF)) >> 1) << expPos) | isqrtLut[(i >> (expPos - lookupBits)) & lookupMask];
        double f = seed.f;
        f = f * (1.5f - f * f * y);
        f = f * (1.5f - f * f * y);
        return (float)f;
    }

    inline float sqrtEst(const float x) noexcept
        { return x * isqrtEst(x); }
} // namespace rapid
