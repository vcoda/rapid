namespace rapid
{
    inline float htof(const half x) noexcept
        { return PackedVector::XMConvertHalfToFloat(x); }
    inline half ftoh(const float x) noexcept
        { return PackedVector::XMConvertFloatToHalf(x); }

    inline float4a htof(const half4& v) noexcept
    {
        __m128i hV = _mm_loadl_epi64(reinterpret_cast<const __m128i*>(&v));
        __m128 fV = _mm_cvtph_ps(hV);
        float4a fv;
        _mm_stream_ps(reinterpret_cast<float*>(&fv), fV);
        return fv;
    }

    inline half4 ftoh(const float4& v) noexcept
    {
        __m128 fV = _mm_load_ps(reinterpret_cast<const float*>(&v));
        __m128i hV = _mm_cvtps_ph(fV, 0);
        half4 hv;
        _mm_storel_epi64(reinterpret_cast<__m128i*>(&hv), hV);
        return hv;
    }

    inline float *htof(float *out, const half *in, const size_t count) noexcept
        { return PackedVector::XMConvertHalfToFloatStream(out, sizeof(float), in, sizeof(half), count); }
    inline half *ftoh(half *out, const float *in, const size_t count) noexcept
        { return PackedVector::XMConvertFloatToHalfStream(out, sizeof(half), in, sizeof(float), count); }
} // namespace rapid
