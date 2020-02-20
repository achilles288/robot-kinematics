#ifndef __RK_KINEMATICS_H__
#define __RK_KINEMATICS_H__

#include "robotkinematics/math.h"

#if defined __cplusplus
extern "C" {
#endif

typedef struct _rkArm2D     rkArm2D;
typedef struct _rkArmLink2D rkArmLink2D;
typedef struct _rkArm2D     rkArm3D;
typedef struct _rkArmLink3D rkArmLink3D;


/*
 * Linked list data structure.
 */
 
struct _rkArm2D {
    rkArmLink2D *links;
    int count;
    int reservedCount;
    rkMat3 transform;
};
 
struct _rkArmLink2D {
    float r;
    float theta;
    rkMat3 transform;
    float q;
};

rkArm2D rkCreateArm2D(int count);
void rkDestroyArm2D(rkArm2D *arm);
rkArmLink2D *rkCreateArmLink2D(rkArm2D *base, float r, float theta);

rkMat3 rkForwardKinematics2D(rkArm2D *base, ...);
float *rkInverseKinematics2D(rkArm2D *base, rkVec2 pos, float t);


/*
 * DH parameters.
 * Linked list data structure.
 */
struct _rkArm3D {
    rkArmLink3D *links;
    int count;
    int reservedCount;
    rkMat4 transform;
};

struct _rkArmLink3D {
    float d;
    float a;
    float theta;
    float alpha;
    rkMat4 transform;
    float q;
};

rkArm3D rkCreateArm3D(int count);
void rkDestroyArm3D(rkArm3D *arm);
rkArmLink3D *rkCreateArmLink3D(rkArm3D *base, float d, float a,
                               float theta, float alpha);

rkMat4 rkForwardKinematics3D(rkArm3D *base, ...);
float *rkInverseKinematics3D(rkArm3D *base, rkVec3 pos, rkEuler rot);


#if defined __cplusplus
}
#endif

#endif
