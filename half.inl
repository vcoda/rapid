namespace rapid
{
    inline float htof(const half x) noexcept
        { return PackedVector::XMConvertHalfToFloat(x); }
    inline half ftoh(const float x) noexcept
        { return PackedVector::XMConvertFloatToHalf(x); }

    inline float4a htof(const half4& v) noexcept
    {
        float4a fv;
#ifdef _XM_NO_INTRINSICS_
        fv.x = PackedVector::XMConvertHalfToFloat(v.x);
        fv.y = PackedVector::XMConvertHalfToFloat(v.y);
        fv.z = PackedVector::XMConvertHalfToFloat(v.z);
        fv.w = PackedVector::XMConvertHalfToFloat(v.w);
#else
        __m128i vh = _mm_loadl_epi64(reinterpret_cast<const __m128i*>(&v));
        __m128 vf = _mm_cvtph_ps(vh);
        _mm_stream_ps(reinterpret_cast<float*>(&fv), vf);
#endif
        return fv;
    }

    inline half4 ftoh(const float4& v) noexcept
    {
        half4 hv;
#ifdef _XM_NO_INTRINSICS_
        hv.x = PackedVector::XMConvertFloatToHalf(v.x);
        hv.y = PackedVector::XMConvertFloatToHalf(v.y);
        hv.z = PackedVector::XMConvertFloatToHalf(v.z);
        hv.w = PackedVector::XMConvertFloatToHalf(v.w);
#else
        __m128 vf = _mm_load_ps(reinterpret_cast<const float*>(&v));
        __m128i vh = _mm_cvtps_ph(vf, 0);
        _mm_storel_epi64(reinterpret_cast<__m128i*>(&hv), hv);
#endif
        return hv;
    }

    inline float *htof(float *out, const half *in, const size_t count) noexcept
        { return PackedVector::XMConvertHalfToFloatStream(out, sizeof(float), in, sizeof(half), count); }
    inline half *ftoh(half *out, const float *in, const size_t count) noexcept
        { return PackedVector::XMConvertFloatToHalfStream(out, sizeof(half), in, sizeof(float), count); }
} // namespace rapid
