#include "../robotkinematics/vector.h"


#if defined __cplusplus
extern "C" {
#endif


float rkVec2Cross(rkVec2 a, rkVec2 b) {
    return a.x*b.y - a.y*b.x;
}


#if defined __cplusplus
}
#endif
