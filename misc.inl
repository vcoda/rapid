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

#ifdef _M_X64
    inline int64_t popCount(uint64_t x) noexcept
    {
    #ifdef _XM_SSE4_INTRINSICS_
        return _mm_popcnt_u64(x);
    #else
        // The Wilkes-Wheeler-Gill implementation
        constexpr uint64_t c1 = 0x5555555555555555ull;
        constexpr uint64_t c2 = 0x3333333333333333ull;
        constexpr uint64_t c4 = 0x0f0f0f0f0f0f0f0full;
        x -= (x >> 1) & c1;
        x = ((x >> 2) & c2) + (x & c2);
        x = (x + (x >> 4)) & c4;
        x *= 0x0101010101010101ull;
        return int64_t(x >> 56);
    #endif
    }
#else
    inline int32_t popCount(uint32_t x) noexcept
    {
    #ifdef _XM_SSE4_INTRINSICS_
        return _mm_popcnt_u32(x);
    #else
        // Aka variable-precision SWAR algorithm
        constexpr uint32_t c1 = 0x55555555u;
        constexpr uint32_t c2 = 0x33333333u;
        constexpr uint32_t c4 = 0x0f0f0f0fu;
        x -= (x >> 1) & c1;
        x = ((x >> 2) & c2) + (x & c2);
        x = (x + (x >> 4)) & c4;
        x *= 0x01010101u;
        return int32_t(x >> 24);
    #endif;
    }
#endif // _M_X64
} // namespace rapid
