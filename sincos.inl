namespace rapid
{
    inline float sin(const float x) noexcept
        { return XMScalarSin(x); }

    // "Faster Math Functions" by Robin Green
    // http://www.ue.eti.pg.gda.pl/~wrona/lab_dsp/cw04/fun_aprox.pdf
    constexpr float sinEst(const float x) noexcept
    {
        float x2 = x * x;
        return x - x *
            x2 * (0.16666656732559f -
            x2 * (0.00833220803f -
            x2 * 0.000195168955f));
    }

    inline float cos(const float x) noexcept
        { return XMScalarCos(x); }
    inline float cosEst(const float x) noexcept
        { return XMScalarCosEst(x); }
    inline void sincos(float *psin, float *pcos, const float x) noexcept
        { XMScalarSinCos(psin, pcos, x); }
    inline void sincosEst(float *psin, float *pcos, const float x) noexcept
        { XMScalarSinCosEst(psin, pcos, x); }
    inline float asin(const float x) noexcept
        { return XMScalarASin(x); }
    inline float asinEst(const float x) noexcept
        { return XMScalarASinEst(x); }
    inline float acos(const float x) noexcept
        { return XMScalarACos(x); }
    inline float acosEst(const float x) noexcept
        { return XMScalarACosEst(x); }
} // namespace rapid
