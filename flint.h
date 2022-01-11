namespace rapid
{
    union flint
    {
        int i;
        float f;
    };

    union flint4
    {
        int i[4];
        float f[4];
    #if defined(__x86_64__) || defined(_M_AMD64)
        float4a v;
    #else
        float4 v;
    #endif
    };
} // namespace rapid
