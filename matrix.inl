namespace rapid
{
    inline matrix::matrix(float _00, float _01,
        float _10, float _11):
        XMMATRIX(_00, _01, 0.f, 0.f,
                 _10, _11, 0.f, 0.f,
                 0.f, 0.f, 1.f, 0.f,
                 0.f, 0.f, 0.f, 1.f) {}
    inline matrix::matrix(float _00, float _01, float _02,
        float _10, float _11, float _12,
        float _20, float _21, float _22):
        XMMATRIX(_00, _01, _02, 0.f,
                 _10, _11, _12, 0.f,
                 _20, _21, _22, 0.f,
                 0.f, 0.f, 0.f, 1.f) {}
    inline matrix::matrix(float _00, float _01, float _02, float _03,
        float _10, float _11, float _12, float _13,
        float _20, float _21, float _22, float _23,
        float _30, float _31, float _32, float _33):
        XMMATRIX(_00, _01, _02, _03,
                 _10, _11, _12, _13,
                 _20, _21, _22, _23,
                 _30, _31, _32, _33) {}
    inline matrix::matrix(const quaternion& q):
        XMMATRIX(XMMatrixRotationQuaternion(q.Q)) {}

    inline matrix transpose(const matrix& m)
        { return XMMatrixTranspose(m); }
    inline matrix inverse(const matrix& m)
        { vector det; return XMMatrixInverse(&det.V, m); }
    inline matrix inverse(vector *det, const matrix& m)
        { return XMMatrixInverse(&det->V, m); }

    inline matrix identity() { return XMMatrixIdentity(); }
    inline matrix translation(float offsetX, float offsetY, float offsetZ)
        { return XMMatrixTranslation(offsetX, offsetY, offsetZ); }
    inline matrix translation(const vector& offset)
        { return XMMatrixTranslationFromVector(offset); }
    inline matrix scaling(float scaleX, float scaleY, float scaleZ)
        { return XMMatrixScaling(scaleX, scaleY, scaleZ); }
    inline matrix scaling(const vector& scale)
        { return XMMatrixScalingFromVector(scale); }
    inline matrix rotationX(float angle)
        { return XMMatrixRotationX(angle); }
    inline matrix rotationY(float angle)
        { return XMMatrixRotationY(angle); }
    inline matrix rotationZ(float angle)
        { return XMMatrixRotationZ(angle); }
    inline matrix rotationNormal(const vector3& normal, float angle)
        { return XMMatrixRotationNormal(normal, angle); }
    inline matrix rotationAxis(const vector3& axis, float angle)
        { return XMMatrixRotationAxis(axis, angle); }

    inline matrix lookAtLH(const vector& eyePosition, const vector& focusPosition, const vector& upDirection)
        { return XMMatrixLookAtLH(eyePosition, focusPosition, upDirection); }
    inline matrix lookAtRH(const vector& eyePosition, const vector& focusPosition, const vector& upDirection)
        { return XMMatrixLookAtRH(eyePosition, focusPosition, upDirection); }
    inline matrix lookToLH(const vector& eyePosition, const vector& eyeDirection, const vector& upDirection)
        { return XMMatrixLookToLH(eyePosition, eyeDirection, upDirection); }
    inline matrix lookToRH(const vector& eyePosition, const vector& eyeDirection, const vector& upDirection)
        { return XMMatrixLookToRH(eyePosition, eyeDirection, upDirection); }
    inline matrix perspectiveLH(float viewWidth, float viewHeight, float nearZ, float farZ)
        { return XMMatrixPerspectiveLH(viewWidth, viewHeight, nearZ, farZ); }
    inline matrix perspectiveRH(float viewWidth, float viewHeight, float nearZ, float farZ)
        { return XMMatrixPerspectiveRH(viewWidth, viewHeight, nearZ, farZ); }
    inline matrix perspectiveFovLH(float fovAngleY, float aspectRatio, float nearZ, float farZ)
        { return XMMatrixPerspectiveFovLH(fovAngleY, aspectRatio, nearZ, farZ); }
    inline matrix perspectiveFovRH(float fovAngleY, float aspectRatio, float nearZ, float farZ)
        { return XMMatrixPerspectiveFovRH(fovAngleY, aspectRatio, nearZ, farZ); }
} // namespace rapid
