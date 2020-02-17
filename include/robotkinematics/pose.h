#ifndef __RK_MATH_POSE_H__
#define __RK_MATH_POSE_H__

#include "vector.h"

#if defined __cplusplus
extern "C" {
#endif


typedef struct _rkPose2 rkPose2;
typedef struct _rkPose3 rkPose3;


struct _rkPose2 {
    rkVec2 position;
    float orientation;
};

struct _rkPose3 {
    rkVec3 position;
    rkEuler orientation;
};


#if defined __cplusplus
}
#endif

#endif
