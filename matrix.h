namespace rapid
{
    class matrix : public XMMATRIX
    {
    public:
        matrix() {}
        matrix(const XMMATRIX& m): XMMATRIX(m) {}
        matrix(const class quaternion& q);

        matrix operator*(const matrix& m) const { return XMMatrixMultiply(*this, m); }
        vector2 operator*(const vector2& v) const { return XMVector2Transform(v.V, *this); }
        vector3 operator*(const vector3& v) const { return XMVector3Transform(v.V, *this); }
        vector4 operator*(const vector4& v) const { return XMVector4Transform(v.V, *this); }

        bool nan() const { return XMMatrixIsNaN(*this); }
        bool infinite() const { return XMMatrixIsInfinite(*this); }
        bool unit() const { return XMMatrixIsIdentity(*this); }

        void identity() { *this = XMMatrixIdentity(); }
        vector determinant() const { XMMatrixDeterminant(*this); }
    };
} // namespace rapid
