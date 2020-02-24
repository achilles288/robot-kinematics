#include <rk/vector.h>

#include <math.h>


#if defined __cplusplus
extern "C" {
#endif


float rkVec2Normalize(rkVec2 v) {
    return sqrt(v.x*v.x + v.y*v.y);
}


#if defined __cplusplus
}
#endif
