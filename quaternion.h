namespace rapid
{
    class alignas(16) quaternion
    {
    public:
        XMVECTOR Q;

        quaternion() {}
        quaternion(FXMVECTOR q): Q(q) {}
        quaternion(const float x, const float y, const float z, const float w): Q(XMVectorSet(x, y, z, w)) {}
        quaternion(const vector3& v, const float w): Q(v) { Q = XMVectorSetW(Q, w); }
        quaternion(const matrix& m): Q(XMQuaternionRotationMatrix(m)) {}

        quaternion operator*(const quaternion& q) const { return XMQuaternionMultiply(Q, q.Q); }
        vector operator|(const quaternion& q) const { return XMQuaternionDot(Q, q.Q); }
        vector operator!() const { return XMQuaternionLength(Q); }
        quaternion operator~() const { return XMQuaternionInverse(Q); }

        const quaternion& operator*=(const quaternion& q) { Q = XMQuaternionMultiply(Q, q.Q); return *this; }

        bool operator==(const quaternion& q) const { return XMQuaternionEqual(Q, q.Q); }
        bool operator!=(const quaternion& q) const { return XMQuaternionNotEqual(Q, q.Q); }

        bool nan() const { return XMQuaternionIsNaN(Q); }
        bool infinite() const { return XMQuaternionIsInfinite(Q); }
        bool unit() const { return XMQuaternionIsIdentity(Q); }

        void identity() { Q = XMQuaternionIdentity(); }
        vector dot(const quaternion& q) { return XMQuaternionDot(Q, q.Q); }
        vector lengthSq() const { return XMQuaternionLengthSq(Q); }
        vector rcpLengthSq() const { return XMQuaternionReciprocalLength(Q); }
        vector length() const { return XMQuaternionLength(Q); }
        void normalizeEst() { Q = XMQuaternionNormalizeEst(Q); }
        quaternion normalizedEst() const { return XMQuaternionNormalizeEst(Q); }
        void normalize() { Q = XMQuaternionNormalize(Q); }
        quaternion normalized() const { return XMQuaternionNormalize(Q); }
        void conjugate() { Q = XMQuaternionConjugate(Q); }
        quaternion conjugated() const { return XMQuaternionConjugate(Q); }
        void inverse() { Q = XMQuaternionInverse(Q); }
        quaternion inversed() const { return XMQuaternionInverse(Q); }

        void pitchYawRoll(float pitch, float yaw, float roll) { Q = XMQuaternionRotationRollPitchYaw(pitch, yaw, roll); }
        void pitchYawRoll(const vector& angles) { Q = XMQuaternionRotationRollPitchYawFromVector(angles); }
        void fromAxisAngle(const vector3& axis, float angle) { Q = XMQuaternionRotationAxis(axis, angle); }
        vector3 toAxisAngle(float& angle) const { XMVECTOR axis; XMQuaternionToAxisAngle(&axis, &angle, Q); return axis; }

        float x() const { return XMVectorGetX(Q); }
        float y() const { return XMVectorGetY(Q); }
        float z() const { return XMVectorGetZ(Q); }
        float w() const { return XMVectorGetW(Q); }
        vector3 xyz() const { return Q; }

        operator XMVECTOR() const { return Q; }
    };

    inline vector3 operator*(const vector3& v, const quaternion& q) 
        { return XMVector3Rotate(v.V, q.Q); }
} // namespace rapid
