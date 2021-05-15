#include <iostream>
#include <fstream>

constexpr char comp[] = {'x', 'y', 'z', 'w'};
constexpr char Comp[] = {'X', 'Y', 'Z', 'W'};

void printWarning()
{
    std::cout << "// The following code is generated automatically. DO NOT MODIFY!" << std::endl;
}

void genVector2Swizzles(const char *fileName)
{
    std::ofstream out(fileName);
    std::cout.rdbuf(out.rdbuf());
    printWarning();
    for (int y = 0; y < 2; ++y)
    {
        for (int x = 0; x < 2; ++x)
        {
            std::cout << "vector2 "
                << comp[x] << comp[y] << "() "
                << "const noexcept { return XMVectorSwizzle<"
                << "XM_SWIZZLE_" << Comp[x] << ", " 
                << "XM_SWIZZLE_" << Comp[y] << ", "
                << "XM_SWIZZLE_W, "
                << "XM_SWIZZLE_W"
                << ">(V); }" << std::endl;
        }
    }
}

void genVector3Swizzles(const char *fileName)
{
    std::ofstream out(fileName);
    std::cout.rdbuf(out.rdbuf());
    printWarning();
    for (int z = 0; z < 3; ++z)
    {
        for (int y = 0; y < 3; ++y)
        {
            for (int x = 0; x < 3; ++x)
            {
                std::cout << "vector3 "
                    << comp[x] << comp[y] << comp[z] << "() "
                    << "const noexcept { return XMVectorSwizzle<"
                    << "XM_SWIZZLE_" << Comp[x] << ", " 
                    << "XM_SWIZZLE_" << Comp[y] << ", "
                    << "XM_SWIZZLE_" << Comp[z] << ", "
                    << "XM_SWIZZLE_W"
                    << ">(V); }" << std::endl;
            }
        }
    }
}

void genVector4Swizzles(const char *fileName)
{
    std::ofstream out(fileName);
    std::cout.rdbuf(out.rdbuf());
    printWarning();
    for (int w = 0; w < 4; ++w)
    {
        for (int z = 0; z < 4; ++z)
        {
            for (int y = 0; y < 4; ++y)
            {
                for (int x = 0; x < 4; ++x)
                {
                    std::cout << "vector4 "
                        << comp[x] << comp[y] << comp[z] << comp[w] << "() "
                        << "const noexcept { return XMVectorSwizzle<"
                        << "XM_SWIZZLE_" << Comp[x] << ", " 
                        << "XM_SWIZZLE_" << Comp[y] << ", "
                        << "XM_SWIZZLE_" << Comp[z] << ", "
                        << "XM_SWIZZLE_" << Comp[w]
                        << ">(V); }" << std::endl;
                }
            }
        }
    }
}

int main()
{
    std::streambuf *outbuf = std::cout.rdbuf();
    genVector2Swizzles("../vector2.inl");
    genVector3Swizzles("../vector3.inl");
    genVector4Swizzles("../vector4.inl");
    std::cout.rdbuf(outbuf);
    return 0;
}
