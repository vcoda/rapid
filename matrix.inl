namespace rapid
{
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
