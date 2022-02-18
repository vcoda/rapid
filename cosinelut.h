namespace rapid
{
    class cosinelut final
    {
    public:
        explicit cosinelut(float start, float step, uint32_t count);
        ~cosinelut() { delete[] lut; }
        float sin(uint32_t i) const noexcept { return lut[i/4].vsin.a[i%4]; }
        float cos(uint32_t i) const noexcept { return lut[i/4].vcos.a[i%4]; }

    private:
        const uint32_t size;

        union vec4
        {
            float a[4];
        #if defined(__x86_64__) || defined(_M_AMD64)
            float4a v;
        #else
            float4 v;
        #endif
        };

        struct vsincos
        {
            vec4 vsin;
            vec4 vcos;
        } *lut;
    };
} // namespace rapid
