#ifndef __RK_KINEMATICS_H__
#define __RK_KINEMATICS_H__

#include "rkmath.h"

#if defined __cplusplus
extern "C" {
#endif

typedef _armLink ArmLink;

/*
 * DH parameters
 */
struct _armLink {
    float d;
    float a;
    float theta;
    float alpha;
    ArmLink *nextLink;
};


ArmLink *rkCreateLink(ArmLink *prevLink, float d, float a,
                      float theta, float alpha);

vec3 *rkForwardKinematics(ArmLink *base, ...);
float *rkInverseKinematics(ArmLink *base, float x, float y, float z);

#if define __cplusplus
}
#endif

#endif
