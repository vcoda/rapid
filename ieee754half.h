#ifdef XM_F16C_INTRINSICS_

namespace rapid
{
    /* IEEE 754 half-precision binary floating-point format.

       At the time of writing modern CPUs do not support native 16-bit FP math.
       This class emulates it through a series of conversions between half-precision
       and single-precision floating-point formats, which requires F16C instruction set.
       Keep in mind that this doesn't improve FPU perfomance, the implementation
       intended to simplify usage of FP16 format with C++ operator overloading. */

    class ieee754half
    {
    public:
        static constexpr uint16_t eps  = 0b0001010000000000; // 2^-10 = 9.77e-04     Machine epsilon
        static constexpr uint16_t fmin = 0b0000010000000000; // 0.00006103515625     Smallest positive normal number
        static constexpr uint16_t fmax = 0b0111101111111111; // 65504.0              Largest normal number
        static constexpr uint16_t smin = 0b0000000000000001; // 0.000000059604645    Smallest positive subnormal number
        static constexpr uint16_t smax = 0b0000001111111111; // 0.000060975552       Largest subnormal number
        static constexpr uint16_t low  = 0b1111101111111111; // -65504.0             Smallest negative number
        static constexpr uint16_t one  = 0b0011110000000000; // 1.0                  One
        static constexpr uint16_t inf  = 0b0111110000000000; //                      Infinity
        static constexpr uint16_t nan  = 0b0111111000000000; //                      Not-a-Number
        static constexpr uint16_t bias = 15;                 //                      Exponent bias

        union
        {
            uint16_t binary;
            struct
            {   // little-endian byte order
                uint16_t m : 10;
                uint16_t e : 5;
                uint16_t sign : 1;
            };
        };

        ieee754half() noexcept {}
        ieee754half(uint16_t h) noexcept: binary(h) {}
        ieee754half(int i) noexcept: binary(i) {}
        ieee754half(float s) noexcept;

        ieee754half operator++(int) const noexcept;
        ieee754half operator--(int) const noexcept;
        ieee754half& operator++() noexcept;
        ieee754half& operator--() noexcept;
        const ieee754half& operator+() const noexcept { return *this; }
        ieee754half operator-() const noexcept;

        ieee754half operator*(ieee754half h) const noexcept;
        ieee754half operator/(ieee754half h) const noexcept;
        ieee754half operator+(ieee754half h) const noexcept;
        ieee754half operator-(ieee754half h) const noexcept;
        ieee754half& operator*=(ieee754half h) noexcept;
        ieee754half& operator/=(ieee754half h) noexcept;
        ieee754half& operator+=(ieee754half h) noexcept;
        ieee754half& operator-=(ieee754half h) noexcept;
        ieee754half& operator=(float s) noexcept;

        bool operator<(ieee754half h) const noexcept;
        bool operator>(ieee754half h) const noexcept;
        bool operator<=(ieee754half h) const noexcept;
        bool operator>=(ieee754half h) const noexcept;
        bool operator==(ieee754half h) const noexcept;
        bool operator!=(ieee754half h) const noexcept;

        bool operator<(float s) const noexcept;
        bool operator>(float s) const noexcept;
        bool operator<=(float s) const noexcept;
        bool operator>=(float s) const noexcept;
        bool operator==(float s) const noexcept;
        bool operator!=(float s) const noexcept;

        operator float() const noexcept;
        operator double() const noexcept;
    };

} // namespace rapid

#include "iieee754half.inl"

#endif // XM_F16C_INTRINSICS_
