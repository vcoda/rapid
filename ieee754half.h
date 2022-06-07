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
