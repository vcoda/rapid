namespace rapid
{
    inline void quaternion::fromAxisAngle(const vector3& axis, float angle, bool normalized) noexcept
    {
        if (normalized)
            Q = XMQuaternionRotationNormal(axis, angle);
        else
            Q = XMQuaternionRotationAxis(axis, angle);
    }

    inline float quaternion::toAxisAngle(vector3 *axis) const noexcept
    {
        float angle;
        XMQuaternionToAxisAngle(&axis->V, &angle, Q);
        return angle;
    }

    inline quaternion ln(const quaternion& q) noexcept
        { return XMQuaternionLn(q.Q); }
    inline quaternion exp(const quaternion& q) noexcept
        { return XMQuaternionExp(q.Q); }
    inline quaternion slepr(const quaternion& q1, const quaternion& q2, float t) noexcept
        { return XMQuaternionSlerp(q1.Q, q2.Q, t); }
    inline quaternion slepr(const quaternion& q1, const quaternion& q2, const vector& t) noexcept
        { return XMQuaternionSlerpV(q1.Q, q2.Q, t.V); }
    inline quaternion squad(const quaternion& q1, const quaternion& q2, const quaternion& q3, const quaternion& q4, float t) noexcept
        { return XMQuaternionSquad(q1.Q, q2.Q, q3.Q, q4.Q, t); }
    inline quaternion squad(const quaternion& q1, const quaternion& q2, const quaternion& q3, const quaternion& q4, const vector& t) noexcept
        { return XMQuaternionSquadV(q1.Q, q2.Q, q3.Q, q4.Q, t.V); }

    inline quaternion qidentity() noexcept
        { return XMQuaternionIdentity(); }
    inline quaternion pitchYawRoll(const float pitch, const float yaw, const float roll) noexcept
        { return XMQuaternionRotationRollPitchYaw(pitch, yaw, roll); }
    inline quaternion pitchYawRoll(const vector& angles) noexcept
        { return XMQuaternionRotationRollPitchYawFromVector(angles); }

    inline vector3 operator*(const vector3& v, const quaternion& q) noexcept
        { return XMVector3Rotate(v.V, q.Q); }
} // namespace rapid
