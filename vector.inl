namespace rapid
{
    inline vector splatx(const vector& v) { return XMVectorSplatX(v.V); }
    inline vector splaty(const vector& v) { return XMVectorSplatY(v.V); }
    inline vector splatz(const vector& v) { return XMVectorSplatZ(v.V); }
    inline vector splatw(const vector& v) { return XMVectorSplatW(v.V); }

    inline vector sum(const vector& v) { return XMVectorSum(v.V); }
    inline vector madd(const vector& v1, const vector& v2, const vector& v3) { return XMVectorMultiplyAdd(v1.V, v2.V, v3.V); }
    inline vector nmadd(const vector& v1, const vector& v2, const vector& v3) { return XMVectorNegativeMultiplySubtract(v1.V, v2.V, v3.V); }

    inline vector rcpEst(const vector& v) { return XMVectorReciprocalEst(v.V); }
    inline vector rcp(const vector& v) { return XMVectorReciprocal(v.V); }
    inline vector sqrtEst(const vector& v) { return XMVectorSqrtEst(v.V); }
    inline vector sqrt(const vector& v) { return XMVectorSqrt(v.V); }
    inline vector rcpSqrtEst(const vector& v) { return XMVectorReciprocalSqrtEst(v.V); }
    inline vector rcpSqrt(const vector& v) { return XMVectorReciprocalSqrt(v.V); }

    inline vector exp2(const vector& v) { return XMVectorExp2(v.V); }
    inline vector expE(const vector& v) { return XMVectorExpE(v.V); }
    inline vector exp(const vector& v) { return XMVectorExp(v.V); }
    inline vector log2(const vector& v) { return XMVectorLog2(v.V); }
    inline vector logE(const vector& v) { return XMVectorLogE(v.V); }
    inline vector log(const vector& v) { return XMVectorLog(v.V); }
    inline vector pow(const vector& v, const vector& e) { return XMVectorPow(v.V, e.V); }
    inline vector abs(const vector& v) { return XMVectorAbs(v.V); }
    inline vector mod(const vector& v1, const vector& v2) { return XMVectorMod(v1.V, v2.V); }
    inline vector modAngles(const vector& angles) { return XMVectorModAngles(angles.V); }
    inline vector sin(const vector& v) { return XMVectorSin(v.V); }
    inline vector sinEst(const vector& v) { return XMVectorSinEst(v.V); }
    inline vector cos(const vector& v) { return XMVectorCos(v.V); }
    inline vector cosEst(const vector& v) { return XMVectorCosEst(v.V); }
    inline void sincos(vector *psin, vector *pcos, const vector& v) { XMVectorSinCos(&psin->V, &pcos->V, v.V); }
    inline void sincosEst(vector *psin, vector *pcos, const vector& v) { XMVectorSinCosEst(&psin->V, &pcos->V, v.V); }
    inline vector tan(const vector& v) { return XMVectorTan(v.V); }
    inline vector tanEst(const vector& v) { return XMVectorTanEst(v.V); }
    inline vector sinh(const vector& v) { return XMVectorSinH(v.V); }
    inline vector cosh(const vector& v) { return XMVectorCosH(v.V); }
    inline vector tanh(const vector& v) { return XMVectorTanH(v.V); }
    inline vector asin(const vector& v) { return XMVectorASin(v.V); }
    inline vector asinEst(const vector& v) { return XMVectorASinEst(v.V); }
    inline vector acos(const vector& v) { return XMVectorACos(v.V); }
    inline vector acosEst(const vector& v) { return XMVectorACosEst(v.V); }
    inline vector atan(const vector& v) { return XMVectorATan(v.V); }
    inline vector atanEst(const vector& v) { return XMVectorATanEst(v.V); }
    inline vector atan2(const vector& y, const vector& x) { return XMVectorATan2(y.V, x.V); }
    inline vector atan2Est(const vector& y, const vector& x) { return XMVectorATan2Est(y.V, x.V); }
    inline vector lerp(const vector& v1, const vector& v2, const float t) { return XMVectorLerp(v1.V, v2.V, t); }
    inline vector lerp(const vector& v1, const vector& v2, const vector& t) { return XMVectorLerpV(v1, v2, t); }
} // namespace rapid
