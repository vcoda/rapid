namespace rapid
{
    class alignas(16) vector
    {
    public:
        XMVECTOR V;

        vector() {}
        vector(FXMVECTOR v): V(v) {}
        vector(const float x): V(XMVectorReplicate(x)) {}
        vector(const float x, const float y): V(XMVectorSet(x, y, 0.f, 1.f)) {}
        vector(const float x, const float y, const float z): V(XMVectorSet(x, y, z, 1.f)) {}
        vector(const float x, const float y, const float z, const float w): V(XMVectorSet(x, y, z, w)) {}

        const vector& operator+() const { return *this; }
        vector operator-() const { return XMVectorNegate(V); }
        vector operator+(const vector& v) const { return XMVectorAdd(V, v.V); }
        vector operator-(const vector& v) const { return XMVectorSubtract(V, v.V); }
        vector operator*(const vector& v) const { return XMVectorMultiply(V, v.V); }
        vector operator*(const float s) const { return XMVectorScale(V, s); }
        vector operator/(const vector& v) const { return XMVectorDivide(V, v.V); }
        vector operator/(const float s) const { return XMVectorScale(V, 1.f/s); }

        float x() const { return XMVectorGetX(V); }

        void zero() { V = XMVectorZero(); }
        void splatOne() { V = XMVectorSplatOne(); }
        void splatInfinity() { V = XMVectorSplatInfinity(); }
        void splatQNaN() { V = XMVectorSplatQNaN(); }
        void splatEpsilon() { V = XMVectorSplatEpsilon(); }
        void splatSignMask() { V = XMVectorSplatSignMask(); }

        operator XMVECTOR() const { return V; }
        operator float() const { float s; XMStoreFloat(&s, V); return s; }
    };

    inline vector operator*(float s, const vector& v) { return v * s; }
    inline vector operator/(float s, const vector& v) { return vector(s)/v; }
} // namespace rapid
