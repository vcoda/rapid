// https://github.com/tim-janik/anklang/blob/trunk/ase/mathutils.hh

namespace rapid
{
    // f=2^x
    inline float exp2(float x) noexcept
    {
        const int i = x < 0.f ? int(x - .5f) : int(x + .5f);
        ieee754float fp = {0};
        fp.e = ieee754float::bias + i;
        x -= i;
        float r;
        r = x *  0.0013276471992255f;
        r = x * (0.0096755413344448f + r);
        r = x * (0.0555071327349880f + r);
        r = x * (0.2402211972384019f + r);
        r = x * (0.6931469670647601f + r);
        r = fp.f * (1.f + r);
        return r;
    }

    // f=(1/log(2)) * log(x+1)
    inline float log2(float x) noexcept
    {
        ieee754float fp = {x};
        const int i = fp.e - ieee754float::bias;
        fp.e = ieee754float::bias;
        x = fp.f - 1.f;
        float r;
        r = x *  -0.0259366993544709205147977455165000143561553284592936f;
        r = x * (+0.122047857676447181074792747820717519424533931189428f + r);
        r = x * (-0.27814297685064327713977752916286528359628147166014f + r);
        r = x * (+0.45764712300320092992105460899527194244236573556309f + r);
        r = x * (-0.71816105664624015087225994551041120290062342459945f + r);
        r = x * (+1.44254540258782520489769598315182363877204824648687f + r);
        return i + r;
    }
} // namespace rapid
