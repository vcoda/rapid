namespace rapid
{
    class vector4 : public vector
    {
    public:
        vector4() noexcept {}
        vector4(FXMVECTOR v) noexcept: vector(v) {}
        vector4(const vector& v) noexcept: vector(v) {}
        vector4(const float x) noexcept: vector(x) {}
        vector4(const float x, const float y, const float z, const float w) noexcept: vector(x, y, z, w) {}
        vector4(const vector2& v, const float z, const float w) noexcept: vector(v.x(), v.y(), z, w) {}
        vector4(const vector3& v, const float w) noexcept: vector(v) { V = XMVectorSetW(V, w); }
        vector4(const float3& v, float w) noexcept: vector(XMLoadFloat3(&v)) { V = XMVectorSetW(V, w); }
        vector4(const float3a& v, float w) noexcept: vector(XMLoadFloat3A(&v)) { V = XMVectorSetW(V, w); }
        vector4(const float4& v) noexcept: vector(XMLoadFloat4(&v)) {}
        vector4(const float4a& v) noexcept: vector(XMLoadFloat4A(&v)) {}

        vector4 operator+(const vector4& v) const noexcept { return XMVectorAdd(V, v.V); }
        vector4 operator-(const vector4& v) const noexcept { return XMVectorSubtract(V, v.V); }
        vector4 operator*(const vector4& v) const noexcept { return XMVectorMultiply(V, v.V); }
        vector4 operator*(const float s) const noexcept { return XMVectorScale(V, s); }
        vector4 operator/(const vector4& v) const noexcept { return XMVectorDivide(V, v.V); }
        vector4 operator/(const float s) const noexcept { return XMVectorScale(V, 1.f/s); }
        vector operator|(const vector4& v) const noexcept { return XMVector4Dot(V, v.V); }
        vector operator!() const noexcept { return XMVector4Length(V); }

        const vector4& operator+() const noexcept { return *this; }
        vector4 operator-() const noexcept { return XMVectorNegate(V); }
        const vector4& operator+=(const vector4& v) noexcept { V = XMVectorAdd(V, v.V); return *this; }
        const vector4& operator-=(const vector4& v) noexcept { V = XMVectorSubtract(V, v.V); return *this; }
        const vector4& operator*=(const vector4& v) noexcept { V = XMVectorMultiply(V, v.V); return *this; }
        const vector4& operator*=(const float s) noexcept { V = XMVectorScale(V, s); return *this; }
        const vector4& operator/=(const vector4& v) noexcept { V = XMVectorDivide(V, v.V); return *this; }
        const vector4& operator/=(const float s) noexcept { V = XMVectorScale(V, 1.f/s); return *this; }

        bool operator==(const vector4& v) const noexcept { return XMVector4Equal(V, v.V); }
        bool nearEqual(const vector4& v, const vector4& eps) const noexcept { return XMVector4NearEqual(V, v.V, eps); }
        bool operator!=(const vector4& v) const noexcept { return XMVector4NotEqual(V, v.V); }
        bool operator>(const vector4& v) const noexcept { return XMVector4Greater(V, v.V); }
        bool operator>=(const vector4& v) const noexcept { return XMVector4GreaterOrEqual(V, v.V); }
        bool operator<(const vector4& v) const noexcept { return XMVector4Less(V, v.V); }
        bool operator<=(const vector4& v) const noexcept { return XMVector4LessOrEqual(V, v.V); }

        float y() const noexcept { return XMVectorGetY(V); }
        float z() const noexcept { return XMVectorGetZ(V); }
        float w() const noexcept { return XMVectorGetW(V); }

        bool nan() const noexcept { return XMVector4IsNaN(V); }
        bool infinite() const noexcept { return XMVector4IsInfinite(V); }
        bool unit() const noexcept {
            XMVECTOR v = XMVectorSubtract(g_XMOne, XMVector4Dot(V, V));
            return XMVector4LessOrEqual(XMVectorAbs(v), g_XMEpsilon);
        }
        vector sum() const noexcept { return XMVectorSum(V); }
        vector sumAbs() const noexcept { return XMVectorSum(XMVectorAbs(V)); }

        vector dot(const vector4& v) const noexcept { return XMVector4Dot(V, v.V); }
        vector4 cross(const vector4& v2, const vector4& v3) const noexcept { return XMVector4Cross(V, v2.V, v3.V); }
        vector lengthSq() const noexcept { return XMVector4LengthSq(V); }
        vector rcpLengthEst() const noexcept { return XMVector4ReciprocalLengthEst(V); }
        vector rcpLength() const noexcept { return XMVector4ReciprocalLength(V); }
        vector lengthEst() const noexcept { return XMVector4LengthEst(V); }
        vector length() const noexcept { return XMVector4Length(V); }
        void normalizeEst() noexcept { V = XMVector4NormalizeEst(V); }
        vector4 normalizedEst() const noexcept { return XMVector4NormalizeEst(V); }
        void normalize() noexcept { V = XMVector4Normalize(V); }
        vector4 normalized() const noexcept { return XMVector4Normalize(V); }
        vector4 clampLength(const float min, const float max) noexcept { return XMVector4ClampLength(V, min, max); }
        vector4 clampLength(const vector4& min, const vector4& max) noexcept { return XMVector4ClampLengthV(V, min.V, max.V); }

        void store(float2 *v) const noexcept { XMStoreFloat2(v, V); };
        void store(float2a *v) const noexcept { XMStoreFloat2A(v, V); };
        void store(float3 *v) const noexcept { XMStoreFloat3(v, V); };
        void store(float3a *v) const noexcept { XMStoreFloat3A(v, V); };
        void store(float4 *v) const noexcept { XMStoreFloat4(v, V); };
        void store(float4a *v) const noexcept { XMStoreFloat4A(v, V); };
    };
} // namespace rapid
