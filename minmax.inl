namespace rapid
{
    template<typename T>
    inline T min(const T& a, const T& b)
        { return a < b ? a : b; }
    template<typename T>
    inline T max(const T& a, const T& b)
        { return a > b ? a : b; }

    template<typename T>
    inline T min2(const T& a, const T& b)
    {
        T c{min(a.x, b.x),
            min(a.y, b.y)};
        return c;
    }

    template<typename T>
    inline T max2(const T& a, const T& b)
    {
        T c{max(a.x, b.x),
            max(a.y, b.y)};
        return c;
    }

    template<typename T>
    inline T min3(const T& a, const T& b)
    {
        T c{min(a.x, b.x),
            min(a.y, b.y),
            min(a.z, b.z)};
        return c;
    }

    template<typename T>
    inline T max3(const T& a, const T& b)
    {
        T c{max(a.x, b.x),
            max(a.y, b.y),
            max(a.z, b.z)};
        return c;
    }

    template<typename T>
    inline T min4(const T& a, const T& b)
    {
        T c{min(a.x, b.x),
            min(a.y, b.y),
            min(a.z, b.z),
            min(a.w, b.w)};
        return c;
    }

    template<typename T>
    inline T max4(const T& a, const T& b)
    {
        T c{max(a.x, b.x),
            max(a.y, b.y),
            max(a.z, b.z),
            max(a.w, b.w)};
        return c;
    }
} // namespace rapid
