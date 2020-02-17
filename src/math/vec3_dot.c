#include "../robotkinematics/vector.h"


#if defined __cplusplus
extern "C" {
#endif


float rkVec3Dot(rkVec3 a, rkVec3 b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}


#if defined __cplusplus
}
#endif
