#ifndef __RK_KINEMATICS_H__
#define __RK_KINEMATICS_H__

#include "robotkinematics/math.h"

#include <stdbool.h>
#include <stdlib.h>


#if defined __cplusplus
extern "C" {
#endif


typedef struct _rkArmLink2D rkArmLink2D;
typedef struct _rkArmLink3D rkArmLink3D;


struct _rkArmLink2D {
    // Link parameters
    float r;
    float theta;
    
    rkMat3 transform;
    float q;
    
    bool startOfChain;
    bool endOfChain;
};


rkArmLink2D *rkCreateArm2D(int count);
#define rkDestroyArm2D(ROOT) \
    free(ROOT)

rkArmLink2D *rkJoinArmLink2D(rkArmLink2D *root, float r, float theta);


rkMat3 _rkForwardKinematics2D(rkArmLink2D *root, ...);
#define rkForwardKinematics2D(ROOT, ...) \
    _rkForwardKinematics2D((ROOT), __VA_ARGS__, NAN)

float *rkInverseKinematics2D(rkArmLink2D *root, rkArmLink2D *end,
                             rkVec2 pos, float t);


struct _rkArmLink3D {
    // DH parameters
    float d;
    float a;
    float theta;
    float alpha;
    
    rkMat4 transform;
    float q;
    
    bool startOfChain;
    bool endOfChain;
};


rkArmLink3D *rkCreateArm3D(int count);
#define rkDestroyArm3D(ROOT) \
    free(ROOT)

rkArmLink3D *rkJoinArmLink3D(rkArmLink3D *root, float d, float a,
                             float theta, float alpha);


rkMat4 _rkForwardKinematics3D(rkArmLink3D *root, ...);
#define rkForwardKinematics3D(ROOT, ...) \
    _rkForwardKinematics3D((ROOT), __VA_ARGS__, NAN)

float *rkInverseKinematics3D(rkArmLink3D *root, rkArmLink3D *end,
                             rkVec3 pos, rkEuler rot);


#define RK_2D_ORIENTATION_ANY NAN
#define RK_3D_ORIENTATION_ANY ((rkEuler) {NAN, NAN, NAN})


#if defined __cplusplus
}
#endif

#endif
