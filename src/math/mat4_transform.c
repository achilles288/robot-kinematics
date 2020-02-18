#include "../robotkinematics/matrix.h"

#include <math.h>


#if defined __cplusplus
extern "C" {
#endif


rkMat4 rkMat4Transform(rkVec3 pos, rkEuler rot) {
    /*float c1 = cos(rot.x);
    float c2 = cos(rot.y);
    float c3 = cos(rot.z);
    float s1 = sin(rot.x);
    float s2 = sin(rot.y);
    float s3 = sin(rot.z);*/
    return (rkMat4) {{
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
    }};
}


#if defined __cplusplus
}
#endif
