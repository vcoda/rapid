namespace rapid
{
    inline vector ln(const quaternion& q) noexcept
        { return XMQuaternionLn(q.Q); }
    inline vector exp(const quaternion& q) noexcept
        { return XMQuaternionExp(q.Q); }
    inline vector slepr(const quaternion& q1, const quaternion& q2, float t) noexcept
        { return XMQuaternionSlerp(q1.Q, q2.Q, t); }
    inline vector slepr(const quaternion& q1, const quaternion& q2, const vector& t) noexcept
        { return XMQuaternionSlerpV(q1.Q, q2.Q, t.V); }
    inline vector squad(const quaternion& q1, const quaternion& q2, const quaternion& q3, const quaternion& q4, float t) noexcept
        { return XMQuaternionSquad(q1.Q, q2.Q, q3.Q, q4.Q, t); }
    inline vector squad(const quaternion& q1, const quaternion& q2, const quaternion& q3, const quaternion& q4, const vector& t) noexcept
        { return XMQuaternionSquadV(q1.Q, q2.Q, q3.Q, q4.Q, t.V); }
} // namespace rapid
