#ifndef __RK_KINEMATICS_H__
#define __RK_KINEMATICS_H__

#include "math.h"

#include <stdbool.h>
#include <stdlib.h>


#if defined __cplusplus
extern "C" {
#endif


typedef struct _rkLink2D rkLink2D;
typedef struct _rkLink3D rkLink3D;


/*
 * 2-Dimension kinematic link.
 *
 * Kinematic chain link for revolute joints.
 */
struct _rkLink2D {
    float r;
    
    rkMat3 transform;
    float q;
    
    bool startOfChain;
    bool endOfChain;
};


/*
 * Reserve memory for a number of links.
 * Returns an array of links.
 */
rkLink2D *rkCreateChain2D(int count);

#define rkDestroyChain2D(ROOT) \
    free(ROOT)

/*
 * Append a link at the end of a kinematic chain.
 * Link length parameter.
 */
rkLink2D *rkJoinLink2D(rkLink2D *root, float r);


/*
 * Computes link positions from joint variables.
 * 
 * Starting link to rotate is to be specified.
 * Number of parameters is variable (as many input as u wish).
 * 
 * Returns end effector transform matrix.
 * Transform matricies of the rest of links can be accessed through
 * data structures.
 */
rkMat3 _rkForwardKinematics2D(rkLink2D *root, ...);

#define rkForwardKinematics2D(ROOT, ...) \
    _rkForwardKinematics2D((ROOT), __VA_ARGS__, NAN)

/*
 * Computes joint variables from target pose.
 * 
 * Starting and ending link.
 * 
 * Answer joint values are to be extracted from structures.
 */
void rkInverseKinematics2D(rkLink2D *root, rkLink2D *end,
                           rkVec2 pos, float t);



/*
 * 3-Dimension kinematic link.
 *
 * Kinematic chain link for revolute joints.
 * DH parameters.
 */
struct _rkLink3D {
    float d;
    float theta;
    float a;
    float alpha;
    
    rkMat4 transform;
    float q;
    
    bool startOfChain;
    bool endOfChain;
};


/*
 * Reserve memory for a number of links.
 * Returns an array of links.
 */
rkLink3D *rkCreateChain3D(int count);

#define rkDestroyChain3D(ROOT) \
    free(ROOT)

/*
 * Append a link at the end of a kinematic chain.
 * Link length parameter.
 */
rkLink3D *rkJoinLink3D(rkLink3D *root, float d, float theta,
                       float a, float alpha);


/*
 * Computes joint variables from target pose.
 * 
 * Starting and ending link.
 * 
 * Answer joint values are to be extracted from structures.
 */
rkMat4 _rkForwardKinematics3D(rkLink3D *root, ...);

#define rkForwardKinematics3D(ROOT, ...) \
    _rkForwardKinematics3D((ROOT), __VA_ARGS__, NAN)

/*
 * Computes joint variables from target pose.
 * 
 * Starting and ending link.
 * 
 * Answer joint values are to be extracted from structures.
 */
void rkInverseKinematics3D(rkLink3D *root, rkLink3D *end,
                           rkVec3 pos, rkEuler rot);


#define RK_2D_ORIENTATION_ANY NAN
#define RK_3D_ORIENTATION_ANY ((rkEuler) {NAN, NAN, NAN})


#if defined __cplusplus
}
#endif

#endif
