/**
 Copyright 2013 BlackBerry Inc.
 Copyright (c) 2013-2016 Chukong Technologies Inc.
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 #WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.

 Original file from GamePlay3D: http://gameplay3d.org

 This file was modified to fit the cocos2d-x project
 */

#include "math/Quaternion.h"

#include <cmath>
#include "base/ccMacros.h"

#if USE_ENOKI
#include "enoki/quaternion.h"
#endif

NS_CC_MATH_BEGIN

const Quaternion Quaternion::ZERO(0.0f, 0.0f, 0.0f, 0.0f);

Quaternion::Quaternion()
    : x(0.0f), y(0.0f), z(0.0f), w(1.0f)
{
}

Quaternion::Quaternion(float xx, float yy, float zz, float ww)
    : x(xx), y(yy), z(zz), w(ww)
{
}

Quaternion::Quaternion(float* array)
{
    set(array);
}

Quaternion::Quaternion(const Mat4& m)
{
    set(m);
}

Quaternion::Quaternion(const Vec3& axis, float angle)
{
    set(axis, angle);
}

Quaternion::Quaternion(const Quaternion& copy)
{
    set(copy);
}

Quaternion::~Quaternion()
{
}

const Quaternion& Quaternion::identity()
{
    static Quaternion value(0.0f, 0.0f, 0.0f, 1.0f);
    return value;
}

const Quaternion& Quaternion::zero()
{
    static Quaternion value(0.0f, 0.0f, 0.0f, 0.0f);
    return value;
}

bool Quaternion::isIdentity() const
{
    return x == 0.0f && y == 0.0f && z == 0.0f && w == 1.0f;
}

bool Quaternion::isZero() const
{
    return x == 0.0f && y == 0.0f && z == 0.0f && w == 0.0f;
}

void Quaternion::createFromRotationMatrix(const Mat4& m, Quaternion* dst)
{
    m.getRotation(dst);
}

void Quaternion::createFromAxisAngle(const Vec3& axis, float angle, Quaternion* dst)
{
    GP_ASSERT(dst);

#if USE_ENOKI
    enoki::Array<float,3> vAxis = enoki::load_unaligned<enoki::Array<float,3>>(&axis);
    auto quad = enoki::rotate<enoki::Quaternion<float>>(vAxis, angle);
    enoki::store_unaligned(dst, quad);
#else
    float halfAngle = angle * 0.5f;
    float sinHalfAngle = sinf(halfAngle);

    Vec3 normal(axis);
    normal.normalize();
    dst->x = normal.x * sinHalfAngle;
    dst->y = normal.y * sinHalfAngle;
    dst->z = normal.z * sinHalfAngle;
    dst->w = cosf(halfAngle);
#endif
}

void Quaternion::conjugate()
{
    x = -x;
    y = -y;
    z = -z;
    //w =  w;
}

Quaternion Quaternion::getConjugated() const
{
    Quaternion q(*this);
    q.conjugate();
    return q;
}

bool Quaternion::inverse()
{
#if USE_ENOKI
    auto quad = enoki::load_unaligned<enoki::Quaternion<float>>(this);
    auto rcp = enoki::rcp(quad);
    enoki::store_unaligned(this, rcp);
#else
    float n = x * x + y * y + z * z + w * w;
    if (n == 1.0f)
    {
        x = -x;
        y = -y;
        z = -z;
        //w = w;

        return true;
    }

    // Too close to zero.
    if (n < 0.000001f)
        return false;

    n = 1.0f / n;
    x = -x * n;
    y = -y * n;
    z = -z * n;
    w = w * n;
#endif

    return true;
}

Quaternion Quaternion::getInversed() const
{
    Quaternion q(*this);
    q.inverse();
    return q;
}

void Quaternion::multiply(const Quaternion& q)
{
    multiply(*this, q, this);
}

void Quaternion::multiply(const Quaternion& q1, const Quaternion& q2, Quaternion* dst)
{
    GP_ASSERT(dst);
#if USE_ENOKI
    auto qA = enoki::load_unaligned<enoki::Quaternion<float>>(&q1);
    auto qB = enoki::load_unaligned<enoki::Quaternion<float>>(&q2);
    enoki::Quaternion<float> qC = qA * qB;
    enoki::store_unaligned(dst, qC);
#else
    float x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
    float y = q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x;
    float z = q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w;
    float w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;

    dst->x = x;
    dst->y = y;
    dst->z = z;
    dst->w = w;
#endif
}

void Quaternion::normalize()
{
#if USE_ENOKI
    auto vThis = enoki::load_unaligned<enoki::Quaternion<float>>(this);
    auto vN = enoki::normalize(vThis);
    enoki::store_unaligned(this, vN);
#else
    float n = x * x + y * y + z * z + w * w;

    // Already normalized.
    if (n == 1.0f)
        return;

    n = std::sqrt(n);
    // Too close to zero.
    if (n < 0.000001f)
        return;

    n = 1.0f / n;
    x *= n;
    y *= n;
    z *= n;
    w *= n;
#endif
}

Quaternion Quaternion::getNormalized() const
{
    Quaternion q(*this);
    q.normalize();
    return q;
}

void Quaternion::set(float xx, float yy, float zz, float ww)
{
    this->x = xx;
    this->y = yy;
    this->z = zz;
    this->w = ww;
}

void Quaternion::set(float* array)
{
    GP_ASSERT(array);
#if USE_ENOKI
    memcpy(this, array, sizeof(*this));
#else
    x = array[0];
    y = array[1];
    z = array[2];
    w = array[3];
#endif
}

void Quaternion::set(const Mat4& m)
{
    Quaternion::createFromRotationMatrix(m, this);
}

void Quaternion::set(const Vec3& axis, float angle)
{
    Quaternion::createFromAxisAngle(axis, angle, this);
}

void Quaternion::set(const Quaternion& q)
{
#if USE_ENOKI
    memcpy(this, &q, sizeof(q));
#else
    this->x = q.x;
    this->y = q.y;
    this->z = q.z;
    this->w = q.w
            ;
#endif
}

void Quaternion::setIdentity()
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
    w = 1.0f;
}

float Quaternion::toAxisAngle(Vec3* axis) const
{
    GP_ASSERT(axis);

    Quaternion q(x, y, z, w);
    q.normalize();
    axis->x = q.x;
    axis->y = q.y;
    axis->z = q.z;
    axis->normalize();

    return (2.0f * std::acos(q.w));
}

void Quaternion::toEuler(Vec3* e) const
{
    toEuler(*this, e);
}

void Quaternion::toEuler(const Quaternion& q, Vec3* e)
{
#if USE_ENOKI
    auto vThis = enoki::load_unaligned<enoki::Quaternion<float>>(&q);
    auto v3 = enoki::quat_to_euler<enoki::Array<float,3>>(vThis);
    enoki::store_unaligned(e, v3);
#else
    float bank = 0;
    float heading = 0;
    float attitude = 0;
    const float test = q.x * q.y + q.z * q.w;
    if (test > 0.499999) {
        bank = 0; // default to zero
        heading = CC_RADIANS_TO_DEGREES(2 * atan2(q.x, q.w));
        attitude = 90;
    }
    else if (test < -0.499999) {
        bank = 0; // default to zero
        heading = -CC_RADIANS_TO_DEGREES(2 * atan2(q.x, q.w));
        attitude = -90;
    }
    else {
        const float sqx = q.x * q.x;
        const float sqy = q.y * q.y;
        const float sqz = q.z * q.z;
        bank = CC_RADIANS_TO_DEGREES(atan2(2 * q.x * q.w - 2 * q.y * q.z, 1 - 2 * sqx - 2 * sqz));
        heading = CC_RADIANS_TO_DEGREES(atan2(2 * q.y * q.w - 2 * q.x * q.z, 1 - 2 * sqy - 2 * sqz));
        attitude = CC_RADIANS_TO_DEGREES(asin(2 * test));
//        if (outerZ) {
//            bank = -180 * CC_SIGN(bank + 1e-6) + bank;
//            heading = -180 * CC_SIGN(heading + 1e-6) + heading;
//            attitude = 180 * CC_SIGN(attitude + 1e-6) - attitude;
//        }
    }
    e->x = bank;
    e->y = heading;
    e->z = attitude;
#endif
}

void Quaternion::lerp(const Quaternion& q1, const Quaternion& q2, float t, Quaternion* dst)
{
    GP_ASSERT(dst);
    GP_ASSERT(!(t < 0.0f || t > 1.0f));

    if (t == 0.0f)
    {
        memcpy(dst, &q1, sizeof(float) * 4);
        return;
    }
    else if (t == 1.0f)
    {
        memcpy(dst, &q2, sizeof(float) * 4);
        return;
    }

    float t1 = 1.0f - t;

    dst->x = t1 * q1.x + t * q2.x;
    dst->y = t1 * q1.y + t * q2.y;
    dst->z = t1 * q1.z + t * q2.z;
    dst->w = t1 * q1.w + t * q2.w;
}

void Quaternion::slerp(const Quaternion& q1, const Quaternion& q2, float t, Quaternion* dst)
{
    GP_ASSERT(dst);
#if USE_ENOKI
    auto vA = enoki::load_unaligned<enoki::Quaternion<float>>(&q1);
    auto vB = enoki::load_unaligned<enoki::Quaternion<float>>(&q2);
    auto vC = enoki::slerp(vA, vB, t);
    enoki::store_unaligned(dst, vC);
#else
    slerp(q1.x, q1.y, q1.z, q1.w, q2.x, q2.y, q2.z, q2.w, t, &dst->x, &dst->y, &dst->z, &dst->w);
#endif
}

void Quaternion::squad(const Quaternion& q1, const Quaternion& q2, const Quaternion& s1, const Quaternion& s2, float t, Quaternion* dst)
{
    GP_ASSERT(!(t < 0.0f || t > 1.0f));

    Quaternion dstQ(0.0f, 0.0f, 0.0f, 1.0f);
    Quaternion dstS(0.0f, 0.0f, 0.0f, 1.0f);

    slerpForSquad(q1, q2, t, &dstQ);
    slerpForSquad(s1, s2, t, &dstS);
    slerpForSquad(dstQ, dstS, 2.0f * t * (1.0f - t), dst);
}

void Quaternion::slerp(float q1x, float q1y, float q1z, float q1w, float q2x, float q2y, float q2z, float q2w, float t, float* dstx, float* dsty, float* dstz, float* dstw)
{
    // Fast slerp implementation by kwhatmough:
    // It contains no division operations, no trig, no inverse trig
    // and no sqrt. Not only does this code tolerate small constraint
    // errors in the input quaternions, it actually corrects for them.
    GP_ASSERT(dstx && dsty && dstz && dstw);
    GP_ASSERT(!(t < 0.0f || t > 1.0f));

#if USE_ENOKI
    enoki::Quaternion<float> vA(q1x, q1y, q1z, q1w);
    enoki::Quaternion<float> vB(q2x, q2y, q2z, q2w);
    auto vC = enoki::slerp(vA, vB, t);
    *dstx = vC.x();
    *dsty = vC.y();
    *dstz = vC.z();
    *dstw = vC.w();
#else
    if (t == 0.0f)
    {
        *dstx = q1x;
        *dsty = q1y;
        *dstz = q1z;
        *dstw = q1w;
        return;
    }
    else if (t == 1.0f)
    {
        *dstx = q2x;
        *dsty = q2y;
        *dstz = q2z;
        *dstw = q2w;
        return;
    }

    if (q1x == q2x && q1y == q2y && q1z == q2z && q1w == q2w)
    {
        *dstx = q1x;
        *dsty = q1y;
        *dstz = q1z;
        *dstw = q1w;
        return;
    }

    float halfY, alpha, beta;
    float u, f1, f2a, f2b;
    float ratio1, ratio2;
    float halfSecHalfTheta, versHalfTheta;
    float sqNotU, sqU;

    float cosTheta = q1w * q2w + q1x * q2x + q1y * q2y + q1z * q2z;

    // As usual in all slerp implementations, we fold theta.
    alpha = cosTheta >= 0 ? 1.0f : -1.0f;
    halfY = 1.0f + alpha * cosTheta;

    // Here we bisect the interval, so we need to fold t as well.
    f2b = t - 0.5f;
    u = f2b >= 0 ? f2b : -f2b;
    f2a = u - f2b;
    f2b += u;
    u += u;
    f1 = 1.0f - u;

    // One iteration of Newton to get 1-cos(theta / 2) to good accuracy.
    halfSecHalfTheta = 1.09f - (0.476537f - 0.0903321f * halfY) * halfY;
    halfSecHalfTheta *= 1.5f - halfY * halfSecHalfTheta * halfSecHalfTheta;
    versHalfTheta = 1.0f - halfY * halfSecHalfTheta;

    // Evaluate series expansions of the coefficients.
    sqNotU = f1 * f1;
    ratio2 = 0.0000440917108f * versHalfTheta;
    ratio1 = -0.00158730159f + (sqNotU - 16.0f) * ratio2;
    ratio1 = 0.0333333333f + ratio1 * (sqNotU - 9.0f) * versHalfTheta;
    ratio1 = -0.333333333f + ratio1 * (sqNotU - 4.0f) * versHalfTheta;
    ratio1 = 1.0f + ratio1 * (sqNotU - 1.0f) * versHalfTheta;

    sqU = u * u;
    ratio2 = -0.00158730159f + (sqU - 16.0f) * ratio2;
    ratio2 = 0.0333333333f + ratio2 * (sqU - 9.0f) * versHalfTheta;
    ratio2 = -0.333333333f + ratio2 * (sqU - 4.0f) * versHalfTheta;
    ratio2 = 1.0f + ratio2 * (sqU - 1.0f) * versHalfTheta;

    // Perform the bisection and resolve the folding done earlier.
    f1 *= ratio1 * halfSecHalfTheta;
    f2a *= ratio2;
    f2b *= ratio2;
    alpha *= f1 + f2a;
    beta = f1 + f2b;

    // Apply final coefficients to a and b as usual.
    float w = alpha * q1w + beta * q2w;
    float x = alpha * q1x + beta * q2x;
    float y = alpha * q1y + beta * q2y;
    float z = alpha * q1z + beta * q2z;

    // This final adjustment to the quaternion's length corrects for
    // any small constraint error in the inputs q1 and q2 But as you
    // can see, it comes at the cost of 9 additional multiplication
    // operations. If this error-correcting feature is not required,
    // the following code may be removed.
    f1 = 1.5f - 0.5f * (w * w + x * x + y * y + z * z);
    *dstw = w * f1;
    *dstx = x * f1;
    *dsty = y * f1;
    *dstz = z * f1;
#endif
}

void Quaternion::slerpForSquad(const Quaternion& q1, const Quaternion& q2, float t, Quaternion* dst)
{
    GP_ASSERT(dst);

    // cos(omega) = q1 * q2;
    // slerp(q1, q2, t) = (q1*sin((1-t)*omega) + q2*sin(t*omega))/sin(omega);
    // q1 = +- q2, slerp(q1,q2,t) = q1.
    // This is a straight-forward implementation of the formula of slerp. It does not do any sign switching.
#if USE_ENOKI
    auto vA = enoki::load_unaligned<enoki::Quaternion<float>>(&q1);
    auto vB = enoki::load_unaligned<enoki::Quaternion<float>>(&q2);

    float c = enoki::dot(vA, vB);

    if (std::abs(c) >= 1.0f)
    {
        enoki::store_unaligned(dst, vA);
        return;
    }

    float omega = std::acos(c);
    float s = std::sqrt(1.0f - c * c);
    if (std::abs(s) <= 0.00001f)
    {
        enoki::store_unaligned(dst, vA);
        return;
    }

    float r1 = std::sin((1 - t) * omega) / s;
    float r2 = std::sin(t * omega) / s;
    auto vC = vA * r1 + vB * r2;
    enoki::store_unaligned(dst, vC);
#else
    float c = q1.x * q2.x + q1.y * q2.y + q1.z * q2.z + q1.w * q2.w;

    if (std::abs(c) >= 1.0f)
    {
        dst->x = q1.x;
        dst->y = q1.y;
        dst->z = q1.z;
        dst->w = q1.w;
        return;
    }

    float omega = std::acos(c);
    float s = std::sqrt(1.0f - c * c);
    if (std::abs(s) <= 0.00001f)
    {
        dst->x = q1.x;
        dst->y = q1.y;
        dst->z = q1.z;
        dst->w = q1.w;
        return;
    }

    float r1 = std::sin((1 - t) * omega) / s;
    float r2 = std::sin(t * omega) / s;
    dst->x = (q1.x * r1 + q2.x * r2);
    dst->y = (q1.y * r1 + q2.y * r2);
    dst->z = (q1.z * r1 + q2.z * r2);
    dst->w = (q1.w * r1 + q2.w * r2);
#endif
}

NS_CC_MATH_END
