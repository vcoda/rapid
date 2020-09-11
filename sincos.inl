namespace rapid
{
    inline float sin(float x) noexcept
        { return XMScalarSin(x); }
    inline float sinEst(float x) noexcept
        { return XMScalarSinEst(x); }
    inline float cos(float x) noexcept
        { return XMScalarCos(x); }
    inline float cosEst(float x) noexcept
        { return XMScalarCosEst(x); }
    inline void sincos(float *psin, float *pcos, float x) noexcept
        { XMScalarSinCos(psin, pcos, x); }
    inline void sincosEst(float *psin, float *pcos, float x) noexcept
        { XMScalarSinCosEst(psin, pcos, x); }
    inline float asin(float x) noexcept
        { return XMScalarASin(x); }
    inline float asinEst(float x) noexcept
        { return XMScalarASinEst(x); }
    inline float acos(float x) noexcept
        { return XMScalarACos(x); }
    inline float acosEst(float x) noexcept
        { return XMScalarACosEst(x); }
} // namespace rapid
