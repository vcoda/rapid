namespace rapid
{
    class alignas(16) plane
    {
    public:
        XMVECTOR P;

        plane() {}
        plane(FXMVECTOR p): P(p) {}
        plane(const vector3& p, const vector3& n): P(XMPlaneFromPointNormal(p.V, n.V)) {}
        plane(const vector3& p1, const vector3& p2, const vector3& p3): P(XMPlaneFromPoints(p1.V, p2.V, p3.V)) {}

        plane operator*(const matrix& m) { return XMPlaneTransform(P, m); }

        bool operator==(const plane& p) const { return XMPlaneEqual(P, p.P); }
        bool nearEqual(const plane& p, const vector& eps) const { return XMPlaneNearEqual(P, p.P, eps); }
        bool operator!=(const plane& p) const { return XMPlaneNotEqual(P, p.P); }

        bool nan() const { return XMPlaneIsNaN(P); }
        bool infinite() const { return XMPlaneIsInfinite(P); }

        vector dot(const vector4& v) { return XMPlaneDot(P, v.V); }
        vector dotNormal(const vector3& n) { return XMPlaneDotNormal(P, n.V); }
        vector distance(const vector3& p) { return XMPlaneDotCoord(P, p.V); }

        void normalizeEst() { P = XMPlaneNormalizeEst(P); }
        plane normalizedEst() const { return XMPlaneNormalizeEst(P); }
        void normalize() { P = XMPlaneNormalize(P); }
        plane normalized() const { return XMPlaneNormalize(P); }

        vector intersectLine(const vector3& p1, const vector3& p2) { return XMPlaneIntersectLine(P, p1.V, p2.V); }
        void intersectPlane(const plane& p, vector3 *p1, vector3 *p2) { XMPlaneIntersectPlane(&p1->V, &p2->V, P, p.P); }
    };
} // namespace rapid
