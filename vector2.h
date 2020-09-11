namespace rapid
{
    class vector2 : public vector
    {
    public:
        vector2() noexcept {}
        vector2(FXMVECTOR v) noexcept: vector(v) {}
        vector2(const vector& v) noexcept: vector(v) {}
        vector2(const float x) noexcept: vector(x) {}
        vector2(const float x, const float y) noexcept: vector(x, y) {}
        vector2(const float2& v) noexcept: vector(XMLoadFloat2(&v)) {}
        vector2(const float2a& v) noexcept: vector(XMLoadFloat2A(&v)) {}

        vector2 operator+(const vector2& v) const noexcept { return XMVectorAdd(V, v.V); }
        vector2 operator-(const vector2& v) const noexcept { return XMVectorSubtract(V, v.V); }
        vector2 operator*(const vector2& v) const noexcept { return XMVectorMultiply(V, v.V); }
        vector2 operator*(const float s) const noexcept { return XMVectorScale(V, s); }
        vector2 operator/(const vector2& v) const noexcept { return XMVectorDivide(V, v.V); }
        vector2 operator/(const float s) const noexcept { return XMVectorScale(V, 1.f/s); }
        vector operator|(const vector2& v) const noexcept { return XMVector2Dot(V, v.V); }
        vector2 operator^(const vector2& v) const noexcept { return XMVector2Cross(V, v.V); }
        vector operator!() const noexcept { return XMVector2Length(V); }

        const vector2& operator+() const noexcept { return *this; }
        vector2 operator-() const noexcept { return XMVectorNegate(V); }
        const vector2& operator+=(const vector2& v) noexcept { V = XMVectorAdd(V, v.V); return *this; }
        const vector2& operator-=(const vector2& v) noexcept { V = XMVectorSubtract(V, v.V); return *this; }
        const vector2& operator*=(const vector2& v) noexcept { V = XMVectorMultiply(V, v.V); return *this; }
        const vector2& operator*=(const float s) noexcept { V = XMVectorScale(V, s); return *this; }
        const vector2& operator/=(const vector2& v) noexcept { V = XMVectorDivide(V, v.V); return *this; }
        const vector2& operator/=(const float s) noexcept { V = XMVectorScale(V, 1.f/s); return *this; }

        bool operator==(const vector2& v) const noexcept { return XMVector2Equal(V, v.V); }
        bool nearEqual(const vector2& v, const vector2& eps) const noexcept { return XMVector2NearEqual(V, v.V, eps); }
        bool operator!=(const vector2& v) const noexcept { return XMVector2NotEqual(V, v.V); }
        bool operator>(const vector2& v) const noexcept { return XMVector2Greater(V, v.V); }
        bool operator>=(const vector2& v) const noexcept { return XMVector2GreaterOrEqual(V, v.V); }
        bool operator<(const vector2& v) const noexcept { return XMVector2Less(V, v.V); }
        bool operator<=(const vector2& v) const noexcept { return XMVector2LessOrEqual(V, v.V); }

        float y() const noexcept { return XMVectorGetY(V); }

        bool nan() const noexcept { return XMVector2IsNaN(V); }
        bool infinite() const noexcept { return XMVector2IsInfinite(V); }

        vector sum() const noexcept { return XMVector2Dot(V, XMVectorSet(1.f, 1.f, 0.f, 0.f)); }
        vector sumAbs() const noexcept { return XMVector2Dot(XMVectorAbs(V), XMVectorSet(1.f, 1.f, 0.f, 0.f)); }

        vector dot(const vector2& v) const noexcept { return XMVector2Dot(V, v.V); }
        vector2 cross(const vector2& v) const noexcept { return XMVector2Cross(V, v.V); }
        vector lengthSq() const noexcept { return XMVector2LengthSq(V); }
        vector rcpLengthEst() const noexcept { return XMVector2ReciprocalLengthEst(V); }
        vector rcpLength() const noexcept { return XMVector2ReciprocalLength(V); }
        vector lengthEst() const noexcept { return XMVector2LengthEst(V); }
        vector length() const noexcept { return XMVector2Length(V); }
        void normalizeEst() noexcept { V = XMVector2NormalizeEst(V); }
        vector2 normalizedEst() const noexcept { return XMVector2NormalizeEst(V); }
        void normalize() noexcept { V = XMVector2Normalize(V); }
        vector2 normalized() const noexcept { return XMVector2Normalize(V); }
        vector2 clampLength(const float min, const float max) noexcept { return XMVector2ClampLength(V, min, max); }
        vector2 clampLength(const vector2& min, const vector2& max) noexcept { return XMVector2ClampLengthV(V, min.V, max.V); }

        void store(float2 *v) const noexcept { XMStoreFloat2(v, V); };
        void store(float2a *v) const noexcept { XMStoreFloat2A(v, V); };
    };
} // namespace rapid
