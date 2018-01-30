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
        vector4(const float3& v, float w): vector4(v.x, v.y, v.z, w) {}
        vector4(const float3a& v, float w): vector4(v.x, v.y, v.z, w) {}
        vector4(const float4& v): vector(XMLoadFloat4(&v)) {}
        vector4(const float4a& v): vector(XMLoadFloat4A(&v)) {}
        
        bool operator==(const vector4& v) const { return XMVector4Equal(V, v.V); }
        bool nearEqual(const vector4& v, const vector4& eps) const { return XMVector4NearEqual(V, v.V, eps); }
        bool operator!=(const vector4& v) const { return XMVector4NotEqual(V, v.V); }
        bool operator>(const vector4& v) const { return XMVector4Greater(V, v.V); }
        bool operator>=(const vector4& v) const { return XMVector4GreaterOrEqual(V, v.V); }
        bool operator<(const vector4& v) const { return XMVector4Less(V, v.V); }
        bool operator<=(const vector4& v) const { return XMVector4LessOrEqual(V, v.V); }

        vector4 operator|(const vector4& v) const { return XMVector4Dot(V, v.V); }
        vector4 operator!() const { return XMVector4Length(V); }

        bool nan() const { return XMVector4IsNaN(V); }
        bool infinite() const { return XMVector4IsInfinite(V); }

        vector4 dot(const vector4& v) const { return XMVector4Dot(V, v.V); }
        vector4 cross(const vector4& v2, const vector4& v3) const { return XMVector4Cross(V, v2.V, v3.V); }
        vector4 lengthSq() const { return XMVector4LengthSq(V); }
        vector4 rcpLengthEst() const { return XMVector4ReciprocalLengthEst(V); }
        vector4 rcpLength() const { return XMVector4ReciprocalLength(V); }
        vector4 lengthEst() const { return XMVector4LengthEst(V); }
        vector4 length() const { return XMVector4Length(V); }
        void normalizeEst() { V = XMVector4NormalizeEst(V); }
        vector4 normalizedEst() const { return XMVector4NormalizeEst(V); }
        void normalize() { V = XMVector4Normalize(V); }
        vector4 normalized() const { return XMVector4Normalize(V); }
        vector4 clampLength(const float min, const float max) { return XMVector4ClampLength(V, min, max); }
        vector4 clampLength(const vector4& min, const vector4& max) { return XMVector4ClampLengthV(V, min.V, max.V); }

        float y() const { return XMVectorGetY(V); }
        float z() const { return XMVectorGetZ(V); }
        float w() const { return XMVectorGetW(V); }

        operator float2a() const { float2a v; XMStoreFloat2A(&v, V); return v; }
        operator float3a() const { float3a v; XMStoreFloat3A(&v, V); return v; }
        operator float4a() const { float4a v; XMStoreFloat4A(&v, V); return v; }
    };
} // namespace rapid
