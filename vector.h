namespace rapid
{
    class alignas(16) vector
    {
    public:
        XMVECTOR V;

        vector() noexcept {}
        vector(FXMVECTOR v) noexcept: V(v) {}
        explicit vector(const float x) noexcept: V(XMVectorReplicate(x)) {}
        explicit vector(const float x, const float y) noexcept: V(XMVectorSet(x, y, 0.f, 1.f)) {}
        explicit vector(const float x, const float y, const float z) noexcept: V(XMVectorSet(x, y, z, 1.f)) {}
        explicit vector(const float x, const float y, const float z, const float w) noexcept: V(XMVectorSet(x, y, z, w)) {}

        const vector& operator+() const noexcept { return *this; }
        vector operator-() const noexcept { return XMVectorNegate(V); }
        vector operator+(const vector& v) const noexcept { return XMVectorAdd(V, v.V); }
        vector operator-(const vector& v) const noexcept { return XMVectorSubtract(V, v.V); }
        vector operator*(const vector& v) const noexcept { return XMVectorMultiply(V, v.V); }
        vector operator*(const float s) const noexcept { return XMVectorScale(V, s); }
        vector operator/(const vector& v) const noexcept { return XMVectorDivide(V, v.V); }
        vector operator/(const float s) const noexcept { return XMVectorScale(V, 1.f/s); }

        float x() const noexcept { return XMVectorGetX(V); }

        void zero() noexcept { V = XMVectorZero(); }
        void one() noexcept { V = XMVectorSplatOne(); }
        void infinity() noexcept { V = XMVectorSplatInfinity(); }
        void qNan() noexcept { V = XMVectorSplatQNaN(); }
        void epsilon() noexcept { V = XMVectorSplatEpsilon(); }
        void signMask() noexcept { V = XMVectorSplatSignMask(); }

        operator XMVECTOR() const noexcept { return V; }
        operator float() const noexcept;
    };

    inline vector operator*(float s, const vector& v) noexcept { return v * s; }
    inline vector operator/(float s, const vector& v) noexcept { return vector(s)/v; }
} // namespace rapid
