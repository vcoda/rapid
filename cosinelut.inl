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
            vsin.store(&lut[i].vsin.v);
            vcos.store(&lut[i].vcos.v);
            thetas += steps;
        }
    }
} // namespace rapid
