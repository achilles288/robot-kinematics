#ifndef __RK_KINEMATICS_H__
#define __RK_KINEMATICS_H__

#include "robotkinematics/math.h"

#if defined __cplusplus
extern "C" {
#endif


typedef struct _rkArmLink2D rkArmLink2D;
typedef struct _rkArmLink3D rkArmLink3D;


/*
 * Linked list data structure.
 */
struct _rkArmLink2D {
    float r;
    float theta;
    rkArmLink2D *nextLink;
};

rkArmLink2D *rkCreateArmLink2D(ArmLink2D *root, float r, float theta);
void *rkDestroyArmLink2D(ArmLink2D *root);

rkPose2 *rkForwardKinematics2D(rkArmLink *root, ...);
float *rkInverseKinematics2D(rkArmLink *root, float x, float y, float t);


/*
 * DH parameters.
 * Linked list data structure.
 */
struct _rkArmLink3D {
    float d;
    float a;
    float theta;
    float alpha;
    rkArmLink3D *nextLink;
};

rkArmLink3D *rkCreateArmLink3D(ArmLink3D *root, float d, float a,
                               float theta, float alpha);
void *rkDestroyArmLink3D(ArmLink3D *root);

rkPose3 *rkForwardKinematics3D(rkArmLink *root, ...);
float *rkInverseKinematics3D(rkArmLink *root, rkPose3 pose);


#if defined __cplusplus
}
#endif

#endif
