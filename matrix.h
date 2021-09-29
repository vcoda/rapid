namespace rapid
{
    class alignas(16) matrix : public XMMATRIX
    {
    public:
        matrix() noexcept { *this = XMMatrixIdentity(); }
        matrix(FXMMATRIX m) noexcept: XMMATRIX(m) {}
        matrix(FXMVECTOR q) noexcept: XMMATRIX(XMMatrixRotationQuaternion(q)) {}
        explicit matrix(float _00, float _01,
            float _10, float _11) noexcept;
        explicit matrix(float _00, float _01, float _02,
            float _10, float _11, float _12,
            float _20, float _21, float _22) noexcept;
        explicit matrix(float _00, float _01, float _02, float _03,
            float _10, float _11, float _12, float _13,
            float _20, float _21, float _22, float _23,
            float _30, float _31, float _32, float _33) noexcept;
        explicit matrix(const float scale, const float3& translation) noexcept;

        matrix operator*(const matrix& m) const noexcept { return XMMatrixMultiply(*this, m); }
        vector2 operator*(const vector2& v) const noexcept { return XMVector2Transform(v.V, *this); }
        vector3 operator*(const vector3& v) const noexcept { return XMVector3Transform(v.V, *this); }
        vector4 operator*(const vector4& v) const noexcept { return XMVector4Transform(v.V, *this); }
        matrix operator~() const noexcept { return XMMatrixInverse(nullptr, *this); }

        bool nan() const noexcept { return XMMatrixIsNaN(*this); }
        bool infinite() const noexcept { return XMMatrixIsInfinite(*this); }
        bool identity() const noexcept { return XMMatrixIsIdentity(*this); }

        float inverse() noexcept;
        vector determinant() const noexcept { return XMMatrixDeterminant(*this); }

        void store(float3x3 *m) const noexcept { XMStoreFloat3x3(m, *this); }
        void store(float4x3 *m) const noexcept { XMStoreFloat4x3(m, *this); }
        void store(float4x3a *m) const noexcept { XMStoreFloat4x3A(m, *this); }
        void store(float4x4 *m) const noexcept { XMStoreFloat4x4(m, *this); }
        void store(float4x4a *m) const noexcept { XMStoreFloat4x4A(m, *this); }
        template<int rows, int cols>
        void store(float (&m)[rows][cols]) const noexcept;
    };
} // namespace rapid
