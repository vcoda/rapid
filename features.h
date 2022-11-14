namespace rapid
{
    struct features
    {
        const bool sse3: 1;
        const bool ssse3: 1;
        const bool sse4: 1;
        const bool avx: 1;
        const bool avx2: 1;
        const bool fma3: 1;
        const bool fma4: 1;
        const bool f16c: 1;
        features() noexcept;
    };
} // namespace rapid
