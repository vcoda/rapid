namespace rapid
{
    class vector4 : public vector
    {
    public:
        vector4() {}
        vector4(FXMVECTOR v): vector(v) {}
        vector4(const vector& v): vector(v) {}
        vector4(const float x): vector(x) {}
        vector4(const float x, const float y, const float z, const float w): vector(x, y, z, w) {}
        vector4(const vector2& v, const float z, const float w): vector(v.x(), v.y(), z, w) {}
        vector4(const vector3& v, const float w): vector(v) { V = XMVectorSetW(V, w); }
        vector4(const float3& v, float w): vector(XMLoadFloat3(&v)) { V = XMVectorSetW(V, w); }
        vector4(const float3a& v, float w): vector(XMLoadFloat3A(&v)) { V = XMVectorSetW(V, w); }
        vector4(const float4& v): vector(XMLoadFloat4(&v)) {}
        vector4(const float4a& v): vector(XMLoadFloat4A(&v)) {}
        
        vector4 operator+(const vector4& v) const { return XMVectorAdd(V, v.V); }
        vector4 operator-(const vector4& v) const { return XMVectorSubtract(V, v.V); }
        vector4 operator*(const vector4& v) const { return XMVectorMultiply(V, v.V); }
        vector4 operator*(const float s) const { return XMVectorScale(V, s); }
        vector4 operator/(const vector4& v) const { return XMVectorDivide(V, v.V); }
        vector4 operator/(const float s) const { return XMVectorScale(V, 1.f/s); }
        vector operator|(const vector4& v) const { return XMVector4Dot(V, v.V); }
        vector operator!() const { return XMVector4Length(V); }

        const vector4& operator+() const { return *this; }
        vector4 operator-() const { return XMVectorNegate(V); }
        const vector4& operator+=(const vector4& v) { V = XMVectorAdd(V, v.V); return *this; }
        const vector4& operator-=(const vector4& v) { V = XMVectorSubtract(V, v.V); return *this; }
        const vector4& operator*=(const vector4& v) { V = XMVectorMultiply(V, v.V); return *this; }
        const vector4& operator*=(const float s) { V = XMVectorScale(V, s); return *this; }
        const vector4& operator/=(const vector4& v) { V = XMVectorDivide(V, v.V); return *this; }
        const vector4& operator/=(const float s) { V = XMVectorScale(V, 1.f/s); return *this; }

        bool operator==(const vector4& v) const { return XMVector4Equal(V, v.V); }
        bool nearEqual(const vector4& v, const vector4& eps) const { return XMVector4NearEqual(V, v.V, eps); }
        bool operator!=(const vector4& v) const { return XMVector4NotEqual(V, v.V); }
        bool operator>(const vector4& v) const { return XMVector4Greater(V, v.V); }
        bool operator>=(const vector4& v) const { return XMVector4GreaterOrEqual(V, v.V); }
        bool operator<(const vector4& v) const { return XMVector4Less(V, v.V); }
        bool operator<=(const vector4& v) const { return XMVector4LessOrEqual(V, v.V); }

        float y() const { return XMVectorGetY(V); }
        float z() const { return XMVectorGetZ(V); }
        float w() const { return XMVectorGetW(V); }

        bool nan() const { return XMVector4IsNaN(V); }
        bool infinite() const { return XMVector4IsInfinite(V); }

        vector dot(const vector4& v) const { return XMVector4Dot(V, v.V); }
        vector4 cross(const vector4& v2, const vector4& v3) const { return XMVector4Cross(V, v2.V, v3.V); }
        vector lengthSq() const { return XMVector4LengthSq(V); }
        vector rcpLengthEst() const { return XMVector4ReciprocalLengthEst(V); }
        vector rcpLength() const { return XMVector4ReciprocalLength(V); }
        vector lengthEst() const { return XMVector4LengthEst(V); }
        vector length() const { return XMVector4Length(V); }
        void normalizeEst() { V = XMVector4NormalizeEst(V); }
        vector4 normalizedEst() const { return XMVector4NormalizeEst(V); }
        void normalize() { V = XMVector4Normalize(V); }
        vector4 normalized() const { return XMVector4Normalize(V); }
        vector4 clampLength(const float min, const float max) { return XMVector4ClampLength(V, min, max); }
        vector4 clampLength(const vector4& min, const vector4& max) { return XMVector4ClampLengthV(V, min.V, max.V); }

        void store(float2 *v) const { XMStoreFloat2(v, V); };
        void store(float2a *v) const { XMStoreFloat2A(v, V); };
        void store(float3 *v) const { XMStoreFloat3(v, V); };
        void store(float3a *v) const { XMStoreFloat3A(v, V); };
        void store(float4 *v) const { XMStoreFloat4(v, V); };
        void store(float4a *v) const { XMStoreFloat4A(v, V); };
    };
} // namespace rapid
