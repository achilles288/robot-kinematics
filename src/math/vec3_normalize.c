#include <rk/vector.h>

#include <math.h>


#if defined __cplusplus
extern "C" {
#endif


rkVec3 rkVec3Normalize(rkVec3 v) {
    float mag = sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
    return (rkVec3){v.x/mag, v.y/mag, v.z/mag};
}


#if defined __cplusplus
}
#endif
