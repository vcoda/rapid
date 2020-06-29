namespace rapid
{
    class alignas(16) matrix : public XMMATRIX
    {
    public:
        matrix() { *this = XMMatrixIdentity(); }
        matrix(const XMMATRIX& m): XMMATRIX(m) {}
        matrix(float _00, float _01,
            float _10, float _11);
        matrix(float _00, float _01, float _02,
            float _10, float _11, float _12,
            float _20, float _21, float _22);
        matrix(float _00, float _01, float _02, float _03,
            float _10, float _11, float _12, float _13,
            float _20, float _21, float _22, float _23,
            float _30, float _31, float _32, float _33);
        matrix(const class quaternion& q);

        matrix operator*(const matrix& m) const { return XMMatrixMultiply(*this, m); }
        vector2 operator*(const vector2& v) const { return XMVector2Transform(v.V, *this); }
        vector3 operator*(const vector3& v) const { return XMVector3Transform(v.V, *this); }
        vector4 operator*(const vector4& v) const { return XMVector4Transform(v.V, *this); }

        bool nan() const { return XMMatrixIsNaN(*this); }
        bool infinite() const { return XMMatrixIsInfinite(*this); }
        bool unit() const { return XMMatrixIsIdentity(*this); }

        void identity() { *this = XMMatrixIdentity(); }
        vector determinant() const { return XMMatrixDeterminant(*this); }
    };
} // namespace rapid
