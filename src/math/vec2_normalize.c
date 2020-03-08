#include <rk/vector.h>

#include <math.h>


#if defined __cplusplus
extern "C" {
#endif


rkVec2 rkVec2Normalize(rkVec2 v) {
    float mag = sqrt(v.x*v.x + v.y*v.y);
    return (rkVec2){v.x/mag, v.y/mag};
}


#if defined __cplusplus
}
#endif
