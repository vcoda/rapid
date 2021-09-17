namespace rapid
{
    inline constexpr float radians(const float degrees) noexcept
        { return XMConvertToRadians(degrees); }
    inline constexpr float degrees(const float radians) noexcept
        { return XMConvertToDegrees(radians); }

    inline constexpr float sign(const float x) noexcept
    {
        if (x > 0.f)
            return 1.f;
        else if (x < 0.f)
            return -1.f;
        return 0.f;
    }

    // https://rosettacode.org/wiki/Map_range
    // Given two ranges:
    // [a1,a2] and [b1,b2];
    // then a value s in range [a1,a2]
    // is linearly mapped to a value t in range[b1,b2]
    inline constexpr float mapRange(const float a1, const float a2, const float s, const float b1, const float b2) noexcept
    {
        float t = b1 + (s - a1) * (b2 - b1)/(a2 - a1);
        return t;
    }
} // namespace rapid
