namespace rapid
{
    inline vector::operator float() const noexcept
    {
        float s;
        XMStoreFloat(&s, V);
        return s;
    }

    inline vector splatX(const vector& v) noexcept { return XMVectorSplatX(v.V); }
    inline vector splatY(const vector& v) noexcept { return XMVectorSplatY(v.V); }
    inline vector splatZ(const vector& v) noexcept { return XMVectorSplatZ(v.V); }
    inline vector splatW(const vector& v) noexcept { return XMVectorSplatW(v.V); }

    inline vector sum(const vector& v) noexcept { return XMVectorSum(v.V); }
    inline vector madd(const vector& v1, const vector& v2, const vector& v3) noexcept { return XMVectorMultiplyAdd(v1.V, v2.V, v3.V); }
    inline vector nmadd(const vector& v1, const vector& v2, const vector& v3) noexcept { return XMVectorNegativeMultiplySubtract(v1.V, v2.V, v3.V); }

    inline vector rcpEst(const vector& v) noexcept { return XMVectorReciprocalEst(v.V); }
    inline vector rcp(const vector& v) noexcept { return XMVectorReciprocal(v.V); }
    inline vector sqrtEst(const vector& v) noexcept { return XMVectorSqrtEst(v.V); }
    inline vector sqrt(const vector& v) noexcept { return XMVectorSqrt(v.V); }
    inline vector rcpSqrtEst(const vector& v) noexcept { return XMVectorReciprocalSqrtEst(v.V); }
    inline vector rcpSqrt(const vector& v) noexcept { return XMVectorReciprocalSqrt(v.V); }

    inline vector exp2(const vector& v) noexcept { return XMVectorExp2(v.V); }
    inline vector expE(const vector& v) noexcept { return XMVectorExpE(v.V); }
    inline vector exp(const vector& v) noexcept { return XMVectorExp(v.V); }
    inline vector log2(const vector& v) noexcept { return XMVectorLog2(v.V); }
    inline vector logE(const vector& v) noexcept { return XMVectorLogE(v.V); }
    inline vector log(const vector& v) noexcept { return XMVectorLog(v.V); }
    inline vector pow(const vector& v, const vector& e) noexcept { return XMVectorPow(v.V, e.V); }
    inline vector abs(const vector& v) noexcept { return XMVectorAbs(v.V); }
    inline vector mod(const vector& v1, const vector& v2) noexcept { return XMVectorMod(v1.V, v2.V); }
    inline vector modAngles(const vector& angles) noexcept { return XMVectorModAngles(angles.V); }
    inline vector sin(const vector& v) noexcept { return XMVectorSin(v.V); }
    inline vector sinEst(const vector& v) noexcept { return XMVectorSinEst(v.V); }
    inline vector cos(const vector& v) noexcept { return XMVectorCos(v.V); }
    inline vector cosEst(const vector& v) noexcept { return XMVectorCosEst(v.V); }
    inline void sincos(vector *psin, vector *pcos, const vector& v) noexcept { XMVectorSinCos(&psin->V, &pcos->V, v.V); }
    inline void sincosEst(vector *psin, vector *pcos, const vector& v) noexcept { XMVectorSinCosEst(&psin->V, &pcos->V, v.V); }
    inline vector tan(const vector& v) noexcept { return XMVectorTan(v.V); }
    inline vector tanEst(const vector& v) noexcept { return XMVectorTanEst(v.V); }
    inline vector sinh(const vector& v) noexcept { return XMVectorSinH(v.V); }
    inline vector cosh(const vector& v) noexcept { return XMVectorCosH(v.V); }
    inline vector tanh(const vector& v) noexcept { return XMVectorTanH(v.V); }
    inline vector asin(const vector& v) noexcept { return XMVectorASin(v.V); }
    inline vector asinEst(const vector& v) noexcept { return XMVectorASinEst(v.V); }
    inline vector acos(const vector& v) noexcept { return XMVectorACos(v.V); }
    inline vector acosEst(const vector& v) noexcept { return XMVectorACosEst(v.V); }
    inline vector atan(const vector& v) noexcept { return XMVectorATan(v.V); }
    inline vector atanEst(const vector& v) noexcept { return XMVectorATanEst(v.V); }
    inline vector atan2(const vector& y, const vector& x) noexcept { return XMVectorATan2(y.V, x.V); }
    inline vector atan2Est(const vector& y, const vector& x) noexcept { return XMVectorATan2Est(y.V, x.V); }
    inline vector lerp(const vector& v1, const vector& v2, const float t) noexcept { return XMVectorLerp(v1.V, v2.V, t); }
    inline vector lerp(const vector& v1, const vector& v2, const vector& t) noexcept { return XMVectorLerpV(v1, v2, t); }

    inline vector3 orthoProjectOnSphereRH(const vector2& v) noexcept
    {
        vector3 p(v, 0.f);
        const float lengthSq = p.lengthSq();
        if (lengthSq >= 1.f)
            p.normalize();
        else
            p = vector3(p.x(), p.y(), ::sqrtf(1.f - lengthSq));
        return p;
    }

    inline vector3 orthoProjectOnSphereLH(const vector2& v) noexcept
    {
        const vector3 p = orthoProjectOnSphereRH(v);
        return p * vector3(1.f, 1.f, -1.f);
    }

    inline vector operator*(float s, const vector& v) noexcept
        { return v * s; }
    inline vector operator/(float s, const vector& v) noexcept
        { return vector(s)/v; }
} // namespace rapid
