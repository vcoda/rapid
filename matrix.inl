namespace rapid
{
    inline matrix::matrix(float _00, float _01,
        float _10, float _11) noexcept:
        XMMATRIX(_00, _01, 0.f, 0.f,
                 _10, _11, 0.f, 0.f,
                 0.f, 0.f, 1.f, 0.f,
                 0.f, 0.f, 0.f, 1.f) {}
    inline matrix::matrix(float _00, float _01, float _02,
        float _10, float _11, float _12,
        float _20, float _21, float _22) noexcept:
        XMMATRIX(_00, _01, _02, 0.f,
                 _10, _11, _12, 0.f,
                 _20, _21, _22, 0.f,
                 0.f, 0.f, 0.f, 1.f) {}
    inline matrix::matrix(float _00, float _01, float _02, float _03,
        float _10, float _11, float _12, float _13,
        float _20, float _21, float _22, float _23,
        float _30, float _31, float _32, float _33) noexcept:
        XMMATRIX(_00, _01, _02, _03,
                 _10, _11, _12, _13,
                 _20, _21, _22, _23,
                 _30, _31, _32, _33) {}
    inline matrix::matrix(const float scale, const float3& translation) noexcept:
        XMMATRIX(scale, 0.f, 0.f, 0.f,
                 0.f, scale, 0.f, 0.f,
                 0.f, 0.f, scale, 0.f,
                 translation.x, translation.y, translation.z, 1.f) {}
    inline matrix::matrix(const quaternion& q) noexcept:
        XMMATRIX(XMMatrixRotationQuaternion(q.Q)) {}

    inline float matrix::inverse() noexcept
    {
        vector d; 
        *this = XMMatrixInverse(&d.V, *this);
        float determinant;
        XMStoreFloat(&determinant, d);
        return determinant;
    }

    inline void matrix::store3x4(float m[3][4]) const noexcept
    {
        float4x3a m4x3;
        XMStoreFloat4x3A(&m4x3, *this);
        for (size_t i = 0; i < 3; ++i)
            for (size_t j = 0; j < 4; ++j)
                m[i][j] = m4x3(j, i);
    }

    inline matrix transpose(const matrix& m) noexcept
        { return XMMatrixTranspose(m); }
    inline matrix identity() noexcept { return XMMatrixIdentity(); }
    inline matrix translation(float x, float y) noexcept
        { return XMMatrixTranslation(x, y, 0.f); }
    inline matrix translation(float x, float y, float z) noexcept
        { return XMMatrixTranslation(x, y, z); }
    inline matrix translation(const vector& offset) noexcept
        { return XMMatrixTranslationFromVector(offset); }
    inline matrix scaling(float scaleX, float scaleY, float scaleZ) noexcept
        { return XMMatrixScaling(scaleX, scaleY, scaleZ); }
    inline matrix scaling(const vector& scale) noexcept
        { return XMMatrixScalingFromVector(scale); }
    inline matrix rotationX(float angle) noexcept
        { return XMMatrixRotationX(angle); }
    inline matrix rotationY(float angle) noexcept
        { return XMMatrixRotationY(angle); }
    inline matrix rotationZ(float angle) noexcept
        { return XMMatrixRotationZ(angle); }
    inline matrix rotationNormal(const vector3& normal, float angle) noexcept
        { return XMMatrixRotationNormal(normal, angle); }
    inline matrix rotationAxis(const vector3& axis, float angle) noexcept
        { return XMMatrixRotationAxis(axis, angle); }

    inline matrix affine(const vector& scaling, const vector& rotationOrigin, float rotation, const vector& translation) noexcept
        { return XMMatrixAffineTransformation2D(scaling, rotationOrigin, rotation, translation); }
    inline matrix affine(const vector& scaling, const vector& rotationOrigin, const quaternion& rotation, const vector& translation) noexcept
        { return XMMatrixAffineTransformation(scaling, rotationOrigin, rotation, translation); }

    inline matrix lookAtLH(const vector& eyePosition, const vector& focusPosition, const vector& upDirection) noexcept
        { return XMMatrixLookAtLH(eyePosition, focusPosition, upDirection); }
    inline matrix lookAtRH(const vector& eyePosition, const vector& focusPosition, const vector& upDirection) noexcept
        { return XMMatrixLookAtRH(eyePosition, focusPosition, upDirection); }
    inline matrix lookToLH(const vector& eyePosition, const vector& eyeDirection, const vector& upDirection) noexcept
        { return XMMatrixLookToLH(eyePosition, eyeDirection, upDirection); }
    inline matrix lookToRH(const vector& eyePosition, const vector& eyeDirection, const vector& upDirection) noexcept
        { return XMMatrixLookToRH(eyePosition, eyeDirection, upDirection); }
    inline matrix perspectiveLH(float viewWidth, float viewHeight, float nearZ, float farZ) noexcept
        { return XMMatrixPerspectiveLH(viewWidth, viewHeight, nearZ, farZ); }
    inline matrix perspectiveRH(float viewWidth, float viewHeight, float nearZ, float farZ) noexcept
        { return XMMatrixPerspectiveRH(viewWidth, viewHeight, nearZ, farZ); }
    inline matrix perspectiveFovLH(float fovAngleY, float aspectRatio, float nearZ, float farZ) noexcept
        { return XMMatrixPerspectiveFovLH(fovAngleY, aspectRatio, nearZ, farZ); }
    inline matrix perspectiveFovRH(float fovAngleY, float aspectRatio, float nearZ, float farZ) noexcept
        { return XMMatrixPerspectiveFovRH(fovAngleY, aspectRatio, nearZ, farZ); }

    inline matrix inverse(const matrix& m, float *determinant = nullptr) noexcept
    {
        vector d;
        matrix inv = XMMatrixInverse(determinant ? &d.V : nullptr, m);
        if (determinant) XMStoreFloat(determinant, d);
        return inv;
    }

    // Assuming your matrix multiplication follows the convention: M = (S * R * T)
    // (where M is your composed matrix, T is a Translation matrix, R rotation, S scale),
    // then we can normalize the first three rows of the matrix to get just the T * R part.
    // https://gamedev.stackexchange.com/questions/119702/fastest-way-to-neutralize-scale-in-the-transform-matrix
    inline matrix excludeNonUniformScaling(const rapid::matrix& m)
    {
        rapid::matrix uniform;
        uniform.r[0] = XMVector3Normalize(m.r[0]);
        uniform.r[1] = XMVector3Normalize(m.r[1]);
        uniform.r[2] = XMVector3Normalize(m.r[2]);
        uniform.r[3] = m.r[3];
        return uniform;
    }
} // namespace rapid
