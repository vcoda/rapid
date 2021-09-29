namespace rapid
{
    class alignas(16) quaternion
    {
    public:
        XMVECTOR Q;

        quaternion() noexcept: Q(XMQuaternionIdentity()) {}
        quaternion(FXMVECTOR q) noexcept: Q(q) {}
        quaternion(const float x, const float y, const float z, const float w) noexcept: Q(XMVectorSet(x, y, z, w)) {}
        quaternion(const vector3& v, const float w) noexcept: Q(v) { Q = XMVectorSetW(Q, w); }
        quaternion(const matrix& m) noexcept: Q(XMQuaternionRotationMatrix(m)) {}

        quaternion operator*(const quaternion& q) const noexcept { return XMQuaternionMultiply(Q, q.Q); }
        vector operator|(const quaternion& q) const noexcept { return XMQuaternionDot(Q, q.Q); }
        vector operator!() const noexcept { return XMQuaternionLength(Q); }
        quaternion operator~() const noexcept { return XMQuaternionInverse(Q); }

        const quaternion& operator*=(const quaternion& q) noexcept { Q = XMQuaternionMultiply(Q, q.Q); return *this; }

        bool operator==(const quaternion& q) const noexcept { return XMQuaternionEqual(Q, q.Q); }
        bool operator!=(const quaternion& q) const noexcept { return XMQuaternionNotEqual(Q, q.Q); }

        bool nan() const noexcept { return XMQuaternionIsNaN(Q); }
        bool infinite() const noexcept { return XMQuaternionIsInfinite(Q); }
        bool identity() const noexcept { return XMQuaternionIsIdentity(Q); }

        vector dot(const quaternion& q) noexcept { return XMQuaternionDot(Q, q.Q); }
        vector lengthSq() const noexcept { return XMQuaternionLengthSq(Q); }
        vector rcpLengthSq() const noexcept { return XMQuaternionReciprocalLength(Q); }
        vector length() const noexcept { return XMQuaternionLength(Q); }
        void normalizeEst() noexcept { Q = XMQuaternionNormalizeEst(Q); }
        quaternion normalizedEst() const noexcept { return XMQuaternionNormalizeEst(Q); }
        void normalize() noexcept { Q = XMQuaternionNormalize(Q); }
        quaternion normalized() const noexcept { return XMQuaternionNormalize(Q); }
        void conjugate() noexcept { Q = XMQuaternionConjugate(Q); }
        quaternion conjugated() const noexcept { return XMQuaternionConjugate(Q); }
        void inverse() noexcept { Q = XMQuaternionInverse(Q); }
        quaternion inversed() const noexcept { return XMQuaternionInverse(Q); }

        void pitchYawRoll(const float pitch, const float yaw, const float roll) noexcept { Q = XMQuaternionRotationRollPitchYaw(pitch, yaw, roll); }
        void pitchYawRoll(const vector& angles) noexcept { Q = XMQuaternionRotationRollPitchYawFromVector(angles); }
        void fromAxisAngle(const vector3& axis, float angle) noexcept { Q = XMQuaternionRotationAxis(axis, angle); }
        vector3 toAxisAngle(float& angle) const noexcept { XMVECTOR axis; XMQuaternionToAxisAngle(&axis, &angle, Q); return axis; }

        float x() const noexcept { return XMVectorGetX(Q); }
        float y() const noexcept { return XMVectorGetY(Q); }
        float z() const noexcept { return XMVectorGetZ(Q); }
        float w() const noexcept { return XMVectorGetW(Q); }
        vector3 xyz() const noexcept { return Q; }

        operator XMVECTOR() const noexcept { return Q; }
    };

    inline vector3 operator*(const vector3& v, const quaternion& q) noexcept
        { return XMVector3Rotate(v.V, q.Q); }
} // namespace rapid
