namespace rapid
{
    inline constexpr float radians(const float degrees)
        { return XMConvertToRadians(degrees); }
    inline constexpr float degrees(const float radians)
        { return XMConvertToDegrees(radians); }

    inline constexpr float sign(const float x) noexcept
    {
        if (x > 0.f)
            return 1.f;
        else if (x < 0.f)
            return -1.f;
        return 0.f;
    }
} // namespace rapid
