#include "../robotkinematics/vector.h"


#if defined __cplusplus
extern "C" {
#endif


rkVec3 rkVec3Cross(rkVec3 a, rkVec3 b) {
    rkVec3 c;
    c.x = a.y*b.z - a.z*b.y;
    c.y = a.z*b.x - a.x*b.z;
    c.z = a.x*b.y - a.y*b.x;
    return c;
}


#if defined __cplusplus
}
#endif
