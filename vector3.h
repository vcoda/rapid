namespace rapid
{
    class vector3 : public vector
    {
    public:
        vector3() {}
        vector3(FXMVECTOR v) noexcept: vector(v) {}
        vector3(const vector& v) noexcept: vector(v) {}
        vector3(const float x) noexcept: vector(x) {}
        vector3(const float x, const float y, const float z) noexcept: vector(x, y, z) {}
        vector3(const vector2& v, const float z) noexcept: vector(v.x(), v.y(), z) {}
        vector3(const float3& v) noexcept: vector(XMLoadFloat3(&v)) {}
        vector3(const float3a& v) noexcept: vector(XMLoadFloat3A(&v)) {}

        vector3 operator+(const vector3& v) const noexcept { return XMVectorAdd(V, v.V); }
        vector3 operator-(const vector3& v) const noexcept { return XMVectorSubtract(V, v.V); }
        vector3 operator*(const vector3& v) const noexcept { return XMVectorMultiply(V, v.V); }
        vector3 operator*(const float s) const noexcept { return XMVectorScale(V, s); }
        vector3 operator/(const vector3& v) const noexcept { return XMVectorDivide(V, v.V); }
        vector3 operator/(const float s) const noexcept { return XMVectorScale(V, 1.f/s); }
        vector operator|(const vector3& v) const noexcept { return XMVector3Dot(V, v.V); }
        vector3 operator^(const vector3& v) const noexcept { return XMVector3Cross(V, v.V); }
        vector operator!() const noexcept { return XMVector3Length(V); }

        const vector3& operator+() const noexcept { return *this; }
        vector3 operator-() const noexcept { return XMVectorNegate(V); }
        const vector3& operator+=(const vector3& v) noexcept { V = XMVectorAdd(V, v.V); return *this; }
        const vector3& operator-=(const vector3& v) noexcept { V = XMVectorSubtract(V, v.V); return *this; }
        const vector3& operator*=(const vector3& v) noexcept { V = XMVectorMultiply(V, v.V); return *this; }
        const vector3& operator*=(const float s) noexcept { V = XMVectorScale(V, s); return *this; }
        const vector3& operator/=(const vector3& v) noexcept { V = XMVectorDivide(V, v.V); return *this; }
        const vector3& operator/=(const float s) noexcept { V = XMVectorScale(V, 1.f/s); return *this; }

        bool operator==(const vector3& v) const noexcept { return XMVector3Equal(V, v.V); }
        bool nearEqual(const vector3& v, const vector3& eps) const noexcept { return XMVector3NearEqual(V, v.V, eps); }
        bool operator!=(const vector3& v) const noexcept { return XMVector3NotEqual(V, v.V); }
        bool operator>(const vector3& v) const noexcept { return XMVector3Greater(V, v.V); }
        bool operator>=(const vector3& v) const noexcept { return XMVector3GreaterOrEqual(V, v.V); }
        bool operator<(const vector3& v) const noexcept { return XMVector3Less(V, v.V); }
        bool operator<=(const vector3& v) const noexcept { return XMVector3LessOrEqual(V, v.V); }

        float y() const noexcept { return XMVectorGetY(V); }
        float z() const noexcept { return XMVectorGetZ(V); }
        #include "swizzling/vector2.inl"
        #include "swizzling/vector3.inl"

        bool nan() const noexcept { return XMVector3IsNaN(V); }
        bool infinite() const noexcept { return XMVector3IsInfinite(V); }
        bool unit() const noexcept {
            XMVECTOR v = XMVectorSubtract(g_XMOne3, XMVector3Dot(V, V));
            return XMVector3LessOrEqual(XMVectorAbs(v), g_XMEpsilon);
        }
        vector sum() const noexcept { return XMVector3Dot(V, g_XMOne3); }
        vector sumAbs() const noexcept { return XMVector3Dot(XMVectorAbs(V), g_XMOne3); }

        vector dot(const vector3& v) const noexcept { return XMVector3Dot(V, v.V); }
        vector3 cross(const vector3& v) const noexcept { return XMVector3Cross(V, v.V); }
        vector lengthSq() const noexcept { return XMVector3LengthSq(V); }
        vector rcpLengthEst() const noexcept { return XMVector3ReciprocalLengthEst(V); }
        vector rcpLength() const noexcept { return XMVector3ReciprocalLength(V); }
        vector lengthEst() const noexcept { return XMVector3LengthEst(V); }
        vector length() const noexcept { return XMVector3Length(V); }
        void normalizeEst() noexcept { V = XMVector3NormalizeEst(V); }
        vector3 normalizedEst() const noexcept { return XMVector3NormalizeEst(V); }
        void normalize() noexcept { V = XMVector3Normalize(V); }
        vector3 normalized() const noexcept { return XMVector3Normalize(V); }
        vector3 clampLength(const float min, const float max) noexcept { return XMVector3ClampLength(V, min, max); }
        vector3 clampLength(const vector3& min, const vector3& max) noexcept { return XMVector3ClampLengthV(V, min.V, max.V); }

        void store(float2 *v) const noexcept { XMStoreFloat2(v, V); };
        void store(float2a *v) const noexcept { XMStoreFloat2A(v, V); };
        void store(float3 *v) const noexcept { XMStoreFloat3(v, V); };
        void store(float3a *v) const noexcept { XMStoreFloat3A(v, V); };
    };
} // namespace rapid
