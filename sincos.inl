namespace rapid
{
    inline float sin(float x) 
        { return XMScalarSin(x); }
    inline float sinEst(float x) 
        { return XMScalarSinEst(x); }
    inline float cos(float x) 
        { return XMScalarCos(x); }
    inline float cosEst(float x) 
        { return XMScalarCosEst(x); }
    inline void sincos(float *psin, float *pcos, float x) 
        { XMScalarSinCos(psin, pcos, x); }
    inline void sincosEst(float *psin, float *pcos, float x) 
        { XMScalarSinCosEst(psin, pcos, x); }
    inline float asin(float x) 
        { return XMScalarASin(x); }
    inline float asinEst(float x) 
        { return XMScalarASinEst(x); }
    inline float acos(float x) 
        { return XMScalarACos(x); }
    inline float acosEst(float x) 
        { return XMScalarACosEst(x); }
} // namespace rapid
