namespace rapid
{
    class cosinelut final
    {
    public:
        explicit cosinelut(float start, float step, uint32_t count);
        ~cosinelut();
        float sin(const uint32_t i) const noexcept;
        float cos(const uint32_t i) const noexcept;

    private:
#if defined(__x86_64__) || defined(_M_AMD64)
        typedef float4a vec4;
#else
        typedef float4 vec4;
#endif
        struct vsincos
        {
            union {
                vec4 vsin;
                float qsin[4];
            };
            union {
                vec4 vcos;
                float qcos[4];
            };
        };

        const uint32_t size;
        vsincos *lut;
    };
} // namespace rapid
