namespace rapid
{
    class matrix : public XMMATRIX
    {
    public:
        matrix() {}
        matrix(const XMMATRIX& m): XMMATRIX(m) {}
        matrix(const class quaternion& q);

        bool nan() const { return XMMatrixIsNaN(*this); }
        bool infinite() const { return XMMatrixIsInfinite(*this); }
        bool unit() const { return XMMatrixIsIdentity(*this); }

        void identity() { *this = XMMatrixIdentity(); }
        vector determinant() const { XMMatrixDeterminant(*this); }
    };
} // namespace rapid
