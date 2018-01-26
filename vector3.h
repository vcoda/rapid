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
        vector3(const float3& v): vector(XMLoadFloat3(&v)) {}
        vector3(const float3a& v): vector(XMLoadFloat3A(&v)) {}
        
        bool operator==(const vector3& v) const { return XMVector3Equal(V, v.V); }
        bool nearEqual(const vector3& v, const vector3& eps) const { return XMVector3NearEqual(V, v.V, eps); }
        bool operator!=(const vector3& v) const { return XMVector3NotEqual(V, v.V); }
        bool operator>(const vector3& v) const { return XMVector3Greater(V, v.V); }
        bool operator>=(const vector3& v) const { return XMVector3GreaterOrEqual(V, v.V); }
        bool operator<(const vector3& v) const { return XMVector3Less(V, v.V); }
        bool operator<=(const vector3& v) const { return XMVector3LessOrEqual(V, v.V); }

        vector3 operator|(const vector3& v) const { return dot(v); }
        vector3 operator^(const vector3& v) const { return cross(v); }
        vector3 operator!() const { return length(); }

        bool nan() const { return XMVector3IsNaN(V); }
        bool infinite() const { return XMVector3IsInfinite(V); }

        vector3 dot(const vector3& v) const { return XMVector3Dot(V, v.V); }
        vector3 cross(const vector3& v) const { return XMVector3Cross(V, v.V); }
        vector3 lengthSq() const { return XMVector3LengthSq(V); }
        vector3 rcpLengthEst() const { return XMVector3ReciprocalLengthEst(V); }
        vector3 rcpLength() const { return XMVector3ReciprocalLength(V); }
        vector3 lengthEst() const { return XMVector3LengthEst(V); }
        vector3 length() const { return XMVector3Length(V); }
        void normalizeEst() { V = XMVector3NormalizeEst(V); }
        vector3 normalizedEst() const { return XMVector3NormalizeEst(V); }
        void normalize() { V = XMVector3Normalize(V); }
        vector3 normalized() const { return XMVector3Normalize(V); }
        vector3 clampLength(const float min, const float max) { return XMVector3ClampLength(V, min, max); }
        vector3 clampLength(const vector3& min, const vector3& max) { return XMVector3ClampLengthV(V, min.V, max.V); } 

        float z() const { XMVectorGetZ(V); }

        operator float3() const { float3 v; XMStoreFloat3(&v, V); return v; }
        operator float3a() const { float3a v; XMStoreFloat3A(&v, V); return v; }
    };
} // namespace rapid
