namespace rapid
{
    union ieee754float
    {
        float f;
        uint32_t i;
        struct
        {   // little-endian byte order
            uint32_t m: 23;
            uint32_t e: 8;
            uint32_t sign: 1;
        };

        static constexpr float eps = 5.9604644775390625e-08f; // 2^-24, round-off error at 1.0
        static constexpr int bias = 127;                      // exponent bias
        //static constexpr float fmax = 3.40282347e+38f;        // 0x7f7fffff, 2^128 * (1 - epsilon)
        static constexpr float fmin = 1.17549435e-38f;        // 0x00800000 minimum normal
        static constexpr float smax = 1.17549421e-38f;        // 0x007fffff maximum subnormal
        static constexpr float smin = 1.40129846e-45f;        // 0x00000001 minimum subnormal
    };
} // namespace rapid
