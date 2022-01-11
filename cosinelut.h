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
        struct vsincos
        {
            flint4 vsin;
            flint4 vcos;
        };

        const uint32_t size;
        vsincos *lut;
    };
} // namespace rapid
