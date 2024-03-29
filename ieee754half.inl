#ifdef XM_F16C_INTRINSICS_

#define _MM_LOAD_HALF(h) _mm_cvtsi32_si128(static_cast<int>(h))
#define _MM_EXTRACT_HALF(v) static_cast<uint16_t>(_mm_extract_epi16(v, 0))

namespace rapid
{
inline ieee754half::ieee754half(const float s) noexcept
{
    __m128 v = _mm_set_ss(s);
    __m128i h = _mm_cvtps_ph(v, _MM_FROUND_TO_NEAREST_INT);
    binary = _MM_EXTRACT_HALF(h);
}

inline ieee754half ieee754half::operator++(int) const noexcept
{
    __m128i h = _MM_LOAD_HALF(binary);
    __m128 x = _mm_cvtph_ps(h);
    x = _mm_add_ss(x, _mm_set_ss(1.f));
    h = _mm_cvtps_ph(x, _MM_FROUND_TO_NEAREST_INT);
    return _MM_EXTRACT_HALF(h);
}

inline ieee754half ieee754half::operator--(int) const noexcept
{
    __m128i h = _MM_LOAD_HALF(binary);
    __m128 x = _mm_cvtph_ps(h);
    x = _mm_sub_ss(x, _mm_set_ss(1.f));
    h = _mm_cvtps_ph(x, _MM_FROUND_TO_NEAREST_INT);
    return _MM_EXTRACT_HALF(h);
}

inline ieee754half& ieee754half::operator++() noexcept
{
    __m128i h = _MM_LOAD_HALF(binary);
    __m128 x = _mm_cvtph_ps(h);
    x = _mm_add_ss(x, _mm_set_ss(1.f));
    h = _mm_cvtps_ph(x, _MM_FROUND_TO_NEAREST_INT);
    binary = _MM_EXTRACT_HALF(h);
    return *this;
}

inline ieee754half& ieee754half::operator--() noexcept
{
    __m128i h = _MM_LOAD_HALF(binary);
    __m128 x = _mm_cvtph_ps(h);
    x = _mm_sub_ss(x, _mm_set_ss(1.f));
    h = _mm_cvtps_ph(x, _MM_FROUND_TO_NEAREST_INT);
    binary = _MM_EXTRACT_HALF(h);
    return *this;
}

inline ieee754half ieee754half::operator-() const noexcept
{
    return ieee754half(static_cast<uint16_t>(binary ^ 0b1000000000000000)); // Invert sign bit
}

inline ieee754half ieee754half::operator*(const ieee754half h) const noexcept
{
    __m128i ix = _MM_LOAD_HALF(binary);
    __m128i iy = _MM_LOAD_HALF(h.binary);
    __m128 x = _mm_cvtph_ps(ix);
    __m128 y = _mm_cvtph_ps(iy);
    x = _mm_mul_ss(x, y);
    ix = _mm_cvtps_ph(x, _MM_FROUND_TO_NEAREST_INT);
    return _MM_EXTRACT_HALF(ix);
}

inline ieee754half ieee754half::operator/(const ieee754half h) const noexcept
{
    __m128i ix = _MM_LOAD_HALF(binary);
    __m128i iy = _MM_LOAD_HALF(h.binary);
    __m128 x = _mm_cvtph_ps(ix);
    __m128 y = _mm_cvtph_ps(iy);
    x = _mm_div_ss(x, y);
    ix = _mm_cvtps_ph(x, _MM_FROUND_TO_NEAREST_INT);
    return _MM_EXTRACT_HALF(ix);
}

inline ieee754half ieee754half::operator+(const ieee754half h) const noexcept
{
    __m128i ix = _MM_LOAD_HALF(binary);
    __m128i iy = _MM_LOAD_HALF(h.binary);
    __m128 x = _mm_cvtph_ps(ix);
    __m128 y = _mm_cvtph_ps(iy);
    x = _mm_add_ss(x, y);
    ix = _mm_cvtps_ph(x, _MM_FROUND_TO_NEAREST_INT);
    return _MM_EXTRACT_HALF(ix);
}

inline ieee754half ieee754half::operator-(const ieee754half h) const noexcept
{
    __m128i ix = _MM_LOAD_HALF(binary);
    __m128i iy = _MM_LOAD_HALF(h.binary);
    __m128 x = _mm_cvtph_ps(ix);
    __m128 y = _mm_cvtph_ps(iy);
    x = _mm_sub_ss(x, y);
    ix = _mm_cvtps_ph(x, _MM_FROUND_TO_NEAREST_INT);
    return _MM_EXTRACT_HALF(ix);
}

inline ieee754half& ieee754half::operator*=(const ieee754half h) noexcept
{
    __m128i ix = _MM_LOAD_HALF(binary);
    __m128i iy = _MM_LOAD_HALF(h.binary);
    __m128 x = _mm_cvtph_ps(ix);
    __m128 y = _mm_cvtph_ps(iy);
    x = _mm_mul_ss(x, y);
    ix = _mm_cvtps_ph(x, _MM_FROUND_TO_NEAREST_INT);
    binary = _MM_EXTRACT_HALF(ix);
    return *this;
}

inline ieee754half& ieee754half::operator/=(const ieee754half h) noexcept
{
    __m128i ix = _MM_LOAD_HALF(binary);
    __m128i iy = _MM_LOAD_HALF(h.binary);
    __m128 x = _mm_cvtph_ps(ix);
    __m128 y = _mm_cvtph_ps(iy);
    x = _mm_div_ss(x, y);
    ix = _mm_cvtps_ph(x, _MM_FROUND_TO_NEAREST_INT);
    binary = _MM_EXTRACT_HALF(ix);
    return *this;
}

inline ieee754half& ieee754half::operator+=(const ieee754half h) noexcept
{
    __m128i ix = _MM_LOAD_HALF(binary);
    __m128i iy = _MM_LOAD_HALF(h.binary);
    __m128 x = _mm_cvtph_ps(ix);
    __m128 y = _mm_cvtph_ps(iy);
    x = _mm_add_ss(x, y);
    ix = _mm_cvtps_ph(x, _MM_FROUND_TO_NEAREST_INT);
    binary = _MM_EXTRACT_HALF(ix);
    return *this;
}

inline ieee754half& ieee754half::operator-=(const ieee754half h) noexcept
{
    __m128i ix = _MM_LOAD_HALF(binary);
    __m128i iy = _MM_LOAD_HALF(h.binary);
    __m128 x = _mm_cvtph_ps(ix);
    __m128 y = _mm_cvtph_ps(iy);
    x = _mm_sub_ss(x, y);
    ix = _mm_cvtps_ph(x, _MM_FROUND_TO_NEAREST_INT);
    binary = _MM_EXTRACT_HALF(ix);
    return *this;
}

inline ieee754half& ieee754half::operator=(const float s) noexcept
{
    __m128 x = _mm_set_ss(s);
    __m128i ix = _mm_cvtps_ph(x, _MM_FROUND_TO_NEAREST_INT);
    binary = _MM_EXTRACT_HALF(ix);
    return *this;
}

inline bool ieee754half::operator<(const ieee754half h) const noexcept
{
    __m128i ix = _MM_LOAD_HALF(binary);
    __m128i iy = _MM_LOAD_HALF(h.binary);
    __m128 x = _mm_cvtph_ps(ix);
    __m128 y = _mm_cvtph_ps(iy);
    x = _mm_cmplt_ss(x, y);
    return x.m128_u32[0] != 0;
}

inline bool ieee754half::operator>(const ieee754half h) const noexcept
{
    __m128i ix = _MM_LOAD_HALF(binary);
    __m128i iy = _MM_LOAD_HALF(h.binary);
    __m128 x = _mm_cvtph_ps(ix);
    __m128 y = _mm_cvtph_ps(iy);
    x = _mm_cmpgt_ss(x, y);
    return x.m128_u32[0] != 0;
}

inline bool ieee754half::operator<=(const ieee754half h) const noexcept
{
    __m128i ix = _MM_LOAD_HALF(binary);
    __m128i iy = _MM_LOAD_HALF(h.binary);
    __m128 x = _mm_cvtph_ps(ix);
    __m128 y = _mm_cvtph_ps(iy);
    x = _mm_cmple_ss(x, y);
    return x.m128_u32[0] != 0;
}

inline bool ieee754half::operator>=(const ieee754half h) const noexcept
{
    __m128i ix = _MM_LOAD_HALF(binary);
    __m128i iy = _MM_LOAD_HALF(h.binary);
    __m128 x = _mm_cvtph_ps(ix);
    __m128 y = _mm_cvtph_ps(iy);
    x = _mm_cmpge_ss(x, y);
    return x.m128_u32[0] != 0;
}

inline bool ieee754half::operator==(const ieee754half h) const noexcept
{
    return binary == h.binary;
}

inline bool ieee754half::operator!=(const ieee754half h) const noexcept
{
    return binary != h.binary;
}

inline bool ieee754half::operator<(const float s) const noexcept
{
    __m128i ix = _MM_LOAD_HALF(binary);
    __m128 x = _mm_cvtph_ps(ix);
    __m128 y = _mm_set_ss(s);
    x = _mm_cmplt_ss(x, y);
    return x.m128_u32[0] != 0;
}

inline bool ieee754half::operator>(const float s) const noexcept
{
    __m128i ix = _MM_LOAD_HALF(binary);
    __m128 x = _mm_cvtph_ps(ix);
    __m128 y = _mm_set_ss(s);
    x = _mm_cmpgt_ss(x, y);
    return x.m128_u32[0] != 0;
}

inline bool ieee754half::operator<=(const float s) const noexcept
{
    __m128i ix = _MM_LOAD_HALF(binary);
    __m128 x = _mm_cvtph_ps(ix);
    __m128 y = _mm_set_ss(s);
    x = _mm_cmple_ss(x, y);
    return x.m128_u32[0] != 0;
}

inline bool ieee754half::operator>=(const float s) const noexcept
{
    __m128i ix = _MM_LOAD_HALF(binary);
    __m128 x = _mm_cvtph_ps(ix);
    __m128 y = _mm_set_ss(s);
    x = _mm_cmpge_ss(x, y);
    return x.m128_u32[0] != 0;
}

inline bool ieee754half::operator==(const float s) const noexcept
{
    return operator==(ieee754half(s));
}

inline bool ieee754half::operator!=(const float s) const noexcept
{
    return operator!=(ieee754half(s));
}

inline ieee754half::operator int() const noexcept
{
    return static_cast<int>(ieee754half::operator float());
}

inline ieee754half::operator unsigned int() const noexcept
{
    return static_cast<unsigned int>(ieee754half::operator float());
}

inline ieee754half::operator float() const noexcept
{
    __m128i h = _MM_LOAD_HALF(binary);
    __m128 s = _mm_cvtph_ps(h);
    return _mm_cvtss_f32(s);
}

inline ieee754half::operator double() const noexcept
{
    return static_cast<double>(ieee754half::operator float());
}

inline float operator*(const float s, const ieee754half h) noexcept
{
    __m128 x = _mm_set_ss(s);
    __m128i iy = _MM_LOAD_HALF(h.binary);
    __m128 y = _mm_cvtph_ps(iy);
    x = _mm_mul_ss(x, y);
    return _mm_cvtss_f32(x);
}

inline float operator/(const float s, const ieee754half h) noexcept
{
    __m128 x = _mm_set_ss(s);
    __m128i iy = _MM_LOAD_HALF(h.binary);
    __m128 y = _mm_cvtph_ps(iy);
    x = _mm_div_ss(x, y);
    return _mm_cvtss_f32(x);
}

inline float operator+(const float s, const ieee754half h) noexcept
{
    __m128 x = _mm_set_ss(s);
    __m128i iy = _MM_LOAD_HALF(h.binary);
    __m128 y = _mm_cvtph_ps(iy);
    x = _mm_add_ss(x, y);
    return _mm_cvtss_f32(x);
}

inline float operator-(const float s, const ieee754half h) noexcept
{
    __m128 x = _mm_set_ss(s);
    __m128i iy = _MM_LOAD_HALF(h.binary);
    __m128 y = _mm_cvtph_ps(iy);
    x = _mm_sub_ss(x, y);
    return _mm_cvtss_f32(x);
}

inline float& operator*=(float& s, const ieee754half h) noexcept
{
    __m128 x = _mm_set_ss(s);
    __m128i iy = _MM_LOAD_HALF(h.binary);
    __m128 y = _mm_cvtph_ps(iy);
    x = _mm_mul_ss(x, y);
    s = _mm_cvtss_f32(x);
    return s;
}

inline float& operator/=(float& s, const ieee754half h) noexcept
{
    __m128 x = _mm_set_ss(s);
    __m128i iy = _MM_LOAD_HALF(h.binary);
    __m128 y = _mm_cvtph_ps(iy);
    x = _mm_div_ss(x, y);
    s = _mm_cvtss_f32(x);
    return s;
}

inline float& operator+=(float& s, const ieee754half h) noexcept
{
    __m128 x = _mm_set_ss(s);
    __m128i iy = _MM_LOAD_HALF(h.binary);
    __m128 y = _mm_cvtph_ps(iy);
    x = _mm_add_ss(x, y);
    s = _mm_cvtss_f32(x);
    return s;
}

inline float& operator-=(float& s, const ieee754half h) noexcept
{
    __m128 x = _mm_set_ss(s);
    __m128i iy = _MM_LOAD_HALF(h.binary);
    __m128 y = _mm_cvtph_ps(iy);
    x = _mm_sub_ss(x, y);
    s = _mm_cvtss_f32(x);
    return s;
}

static_assert(sizeof(ieee754half) == sizeof(uint16_t), "IEEE 754 half-precision floating-point format must be 16-bit");
} // namespace rapid

#endif // XM_F16C_INTRINSICS_
