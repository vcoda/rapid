namespace rapid
{
    class quaternion
    {
    public:
        XMVECTOR Q;

        quaternion() {}
        quaternion(FXMVECTOR q): Q(q) {}
        quaternion(float pitch, float yaw, float roll): Q(XMQuaternionRotationRollPitchYaw(pitch, yaw, roll)) {}
        quaternion(const vector& angles): Q(XMQuaternionRotationRollPitchYawFromVector(angles)) {}
        quaternion(const vector& axis, float angle): Q(XMQuaternionRotationAxis(axis, angle)) {}
        quaternion(const matrix& m): Q(XMQuaternionRotationMatrix(m)) {}
        quaternion(const float x, const float y, const float z, const float w): Q(XMVectorSet(x, y, z, w)) {}

        quaternion operator*(const quaternion& q) const { return XMQuaternionMultiply(Q, q.Q); }

        bool operator==(const quaternion& q) const { return XMQuaternionEqual(Q, q.Q); }
        bool operator!=(const quaternion& q) const { return XMQuaternionNotEqual(Q, q.Q); }

        vector operator|(const quaternion& q) const { return XMQuaternionDot(Q, q.Q); }
        vector operator!() const { return XMQuaternionLength(Q); }
        vector operator~() const { return XMQuaternionInverse(Q); }

        bool nan() const { return XMQuaternionIsNaN(Q); }
        bool infinite() const { return XMQuaternionIsInfinite(Q); }
        bool unit() const { return XMQuaternionIsIdentity(Q); }

        void identity() { Q = XMQuaternionIdentity(); }
        quaternion dot(const quaternion& q) { return XMQuaternionDot(Q, q.Q); }
        quaternion lengthSq() const { return XMQuaternionLengthSq(Q); }
        quaternion rcpLengthSq() const { return XMQuaternionReciprocalLength(Q); }
        quaternion length() const { return XMQuaternionLength(Q); }
        void normalizeEst() { Q = XMQuaternionNormalizeEst(Q); }
        quaternion normalizedEst() const { return XMQuaternionNormalizeEst(Q); }
        void normalize() { Q = XMQuaternionNormalize(Q); }
        quaternion normalized() const { return XMQuaternionNormalize(Q); }
        void conjugate() { Q = XMQuaternionConjugate(Q); }
        quaternion conjugated() const { return XMQuaternionConjugate(Q); }
        void inverse() { Q = XMQuaternionInverse(Q); }
        quaternion inversed() const { return XMQuaternionInverse(Q); }

        vector3 toAxisAngle(float& angle) const { XMVECTOR axis; XMQuaternionToAxisAngle(&axis, &angle, Q); return axis; }

        operator XMVECTOR() const { return Q; }
    };

    inline vector3 operator*(const vector3& v, const quaternion& q) { return XMVector3Rotate(v.V, q.Q); }
} // namespace rapid
