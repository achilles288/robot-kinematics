#include "../robotkinematics/vector.h"

#include <math.h>


#if defined __cplusplus
extern "C" {
#endif


float rkVec3Normalize(rkVec3 v) {
    return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}


#if defined __cplusplus
}
#endif
