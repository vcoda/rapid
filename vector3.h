namespace rapid
{
    class vector3 : public vector
    {
    public:
        vector3() {}
        vector3(FXMVECTOR v): vector(v) {}
        vector3(const vector& v): vector(v) {}
        vector3(const float x): vector(x) {}
        vector3(const float x, const float y, const float z): vector(x, y, z) {}
        vector3(const vector2& v, const float z): vector(v.x(), v.y(), z) {}
        vector3(const float3& v): vector(XMLoadFloat3(&v)) {}
        vector3(const float3a& v): vector(XMLoadFloat3A(&v)) {}

        vector3 operator+(const vector3& v) const { return XMVectorAdd(V, v.V); }
        vector3 operator-(const vector3& v) const { return XMVectorSubtract(V, v.V); }
        vector3 operator*(const vector3& v) const { return XMVectorMultiply(V, v.V); }
        vector3 operator*(const float s) const { return XMVectorScale(V, s); }
        vector3 operator/(const vector3& v) const { return XMVectorDivide(V, v.V); }
        vector3 operator/(const float s) const { return XMVectorScale(V, 1.f/s); }
        vector operator|(const vector3& v) const { return XMVector3Dot(V, v.V); }
        vector3 operator^(const vector3& v) const { return XMVector3Cross(V, v.V); }
        vector operator!() const { return XMVector3Length(V); }

        const vector3& operator+() const { return *this; }
        vector3 operator-() const { return XMVectorNegate(V); }
        const vector3& operator+=(const vector3& v) { V = XMVectorAdd(V, v.V); return *this; }
        const vector3& operator-=(const vector3& v) { V = XMVectorSubtract(V, v.V); return *this; }
        const vector3& operator*=(const vector3& v) { V = XMVectorMultiply(V, v.V); return *this; }
        const vector3& operator*=(const float s) { V = XMVectorScale(V, s); return *this; }
        const vector3& operator/=(const vector3& v) { V = XMVectorDivide(V, v.V); return *this; }
        const vector3& operator/=(const float s) { V = XMVectorScale(V, 1.f/s); return *this; }

        bool operator==(const vector3& v) const { return XMVector3Equal(V, v.V); }
        bool nearEqual(const vector3& v, const vector3& eps) const { return XMVector3NearEqual(V, v.V, eps); }
        bool operator!=(const vector3& v) const { return XMVector3NotEqual(V, v.V); }
        bool operator>(const vector3& v) const { return XMVector3Greater(V, v.V); }
        bool operator>=(const vector3& v) const { return XMVector3GreaterOrEqual(V, v.V); }
        bool operator<(const vector3& v) const { return XMVector3Less(V, v.V); }
        bool operator<=(const vector3& v) const { return XMVector3LessOrEqual(V, v.V); }

        float y() const { return XMVectorGetY(V); }
        float z() const { return XMVectorGetZ(V); }

        bool nan() const { return XMVector3IsNaN(V); }
        bool infinite() const { return XMVector3IsInfinite(V); }

        vector dot(const vector3& v) const { return XMVector3Dot(V, v.V); }
        vector3 cross(const vector3& v) const { return XMVector3Cross(V, v.V); }
        vector lengthSq() const { return XMVector3LengthSq(V); }
        vector rcpLengthEst() const { return XMVector3ReciprocalLengthEst(V); }
        vector rcpLength() const { return XMVector3ReciprocalLength(V); }
        vector lengthEst() const { return XMVector3LengthEst(V); }
        vector length() const { return XMVector3Length(V); }
        void normalizeEst() { V = XMVector3NormalizeEst(V); }
        vector3 normalizedEst() const { return XMVector3NormalizeEst(V); }
        void normalize() { V = XMVector3Normalize(V); }
        vector3 normalized() const { return XMVector3Normalize(V); }
        vector3 clampLength(const float min, const float max) { return XMVector3ClampLength(V, min, max); }
        vector3 clampLength(const vector3& min, const vector3& max) { return XMVector3ClampLengthV(V, min.V, max.V); }

        void store(float2 *v) const { XMStoreFloat2(v, V); };
        void store(float2a *v) const { XMStoreFloat2A(v, V); };
        void store(float3 *v) const { XMStoreFloat3(v, V); };
        void store(float3a *v) const { XMStoreFloat3A(v, V); };
    };
} // namespace rapid
