namespace rapid
{
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
