namespace rapid
{
    class vector2 : public vector
    {
    public:
        vector2() {}
        vector2(FXMVECTOR v): vector(v) {}
        vector2(const vector& v): vector(v) {}
        vector2(const float x): vector(x) {}
        vector2(const float x, const float y): vector(x, y) {}
        vector2(const float2& v): vector(XMLoadFloat2(&v)) {}
        vector2(const float2a& v): vector(XMLoadFloat2A(&v)) {}

        bool operator==(const vector2& v) const { return XMVector2Equal(V, v.V); }
        bool nearEqual(const vector2& v, const vector2& eps) const { return XMVector2NearEqual(V, v.V, eps); }
        bool operator!=(const vector2& v) const { return XMVector2NotEqual(V, v.V); }
        bool operator>(const vector2& v) const { return XMVector2Greater(V, v.V); }
        bool operator>=(const vector2& v) const { return XMVector2GreaterOrEqual(V, v.V); }
        bool operator<(const vector2& v) const { return XMVector2Less(V, v.V); }
        bool operator<=(const vector2& v) const { return XMVector2LessOrEqual(V, v.V); }

        vector2 operator|(const vector2& v) const { return XMVector2Dot(V, v.V); }
        vector2 operator^(const vector2& v) const { return XMVector2Cross(V, v.V); }
        vector2 operator!() const { return XMVector2Length(V); }

        bool nan() const { return XMVector2IsNaN(V); }
        bool infinite() const { return XMVector2IsInfinite(V); }

        vector2 dot(const vector2& v) const { return XMVector2Dot(V, v.V); }
        vector2 cross(const vector2& v) const { return XMVector2Cross(V, v.V); }
        vector2 lengthSq() const { return XMVector2LengthSq(V); }
        vector2 rcpLengthEst() const { return XMVector2ReciprocalLengthEst(V); }
        vector2 rcpLength() const { return XMVector2ReciprocalLength(V); }
        vector2 lengthEst() const { return XMVector2LengthEst(V); }
        vector2 length() const { return XMVector2Length(V); }
        void normalizeEst() { V = XMVector2NormalizeEst(V); }
        vector2 normalizedEst() const { return XMVector2NormalizeEst(V); }
        void normalize() { V = XMVector2Normalize(V); }
        vector2 normalized() const { return XMVector2Normalize(V); }
        vector2 clampLength(const float min, const float max) { return XMVector2ClampLength(V, min, max); }
        vector2 clampLength(const vector2& min, const vector2& max) { return XMVector2ClampLengthV(V, min.V, max.V); }

        float y() const { return XMVectorGetY(V); }

        operator float2() const { float2 v; XMStoreFloat2(&v, V); return v; }
        operator float2a() const { float2a v; XMStoreFloat2A(&v, V); return v; }
    };
} // namespace rapid
