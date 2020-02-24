#include <rk/vector.h>


#if defined __cplusplus
extern "C" {
#endif


float rkVec2Dot(rkVec2 a, rkVec2 b) {
    return a.x*b.x + a.y*b.y;
}


#if defined __cplusplus
}
#endif
