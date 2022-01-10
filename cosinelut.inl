namespace rapid
{
    inline cosinelut::cosinelut(float start, float step, uint32_t count):
        size(count/4 + (count%4 ? 1 : 0)),
        lut(new vsincos[size])
    {
        vector4 thetas(
            start,
            start + step,
            start + step * 2.f,
            start + step * 3.f);
        const vector4 steps(step * 4.f);
        vector4 vsin, vcos;
        for (uint32_t i = 0; i < size; ++i)
        {
            sincosEst(&vsin, &vcos, thetas);
            vsin.store(&lut[i].vsin);
            vcos.store(&lut[i].vcos);
            thetas += steps;
        }
    }

    inline cosinelut::~cosinelut()
        { delete[] lut; }
    inline float cosinelut::sin(uint32_t i) const noexcept
        { return lut[i/4].qsin[i%4]; }
    inline float cosinelut::cos(uint32_t i) const noexcept
        { return lut[i/4].qcos[i%4]; }
} // namespace rapid
