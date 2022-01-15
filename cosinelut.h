namespace rapid
{
    class cosinelut final
    {
    public:
        explicit cosinelut(float start, float step, uint32_t count);
        ~cosinelut() { delete[] lut; }
        float sin(uint32_t i) const noexcept { return lut[i/4].vsin.f[i%4]; }
        float cos(uint32_t i) const noexcept { return lut[i/4].vcos.f[i%4]; }

    private:
        const uint32_t size;
        struct vsincos
        {
            flint4 vsin;
            flint4 vcos;
        } *lut;
    };
} // namespace rapid
