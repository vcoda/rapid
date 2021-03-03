namespace rapid
{
    class alignas(16) matrix : public XMMATRIX
    {
    public:
        matrix() noexcept { *this = XMMatrixIdentity(); }
        matrix(const XMMATRIX& m) noexcept: XMMATRIX(m) {}
        matrix(float _00, float _01,
            float _10, float _11) noexcept;
        matrix(float _00, float _01, float _02,
            float _10, float _11, float _12,
            float _20, float _21, float _22) noexcept;
        matrix(float _00, float _01, float _02, float _03,
            float _10, float _11, float _12, float _13,
            float _20, float _21, float _22, float _23,
            float _30, float _31, float _32, float _33) noexcept;
        matrix(const class quaternion& q) noexcept;

        matrix operator*(const matrix& m) const noexcept { return XMMatrixMultiply(*this, m); }
        vector2 operator*(const vector2& v) const noexcept { return XMVector2Transform(v.V, *this); }
        vector3 operator*(const vector3& v) const noexcept { return XMVector3Transform(v.V, *this); }
        vector4 operator*(const vector4& v) const noexcept { return XMVector4Transform(v.V, *this); }

        bool nan() const noexcept { return XMMatrixIsNaN(*this); }
        bool infinite() const noexcept { return XMMatrixIsInfinite(*this); }
        bool unit() const noexcept { return XMMatrixIsIdentity(*this); }

        void identity() noexcept { *this = XMMatrixIdentity(); }
        float inverse() noexcept;
        vector determinant() const noexcept { return XMMatrixDeterminant(*this); }
    };
} // namespace rapid
