#include "../robotkinematics/matrix.h"

#include <math.h>


#if defined __cplusplus
extern "C" {
#endif


rkMat4 rkMat4Transform(rkVec3 pos, rkEuler rot) {
    float c1 = cos(rot.x);
    float c2 = cos(rot.y);
    float c3 = cos(rot.z);
    float s1 = sin(rot.x);
    float s2 = sin(rot.y);
    float s3 = sin(rot.z);
    return (rkMat4) {{
        { c2*c3,  s1*s2*c3 - c1*s3,  c1*s2*c3 + s1*s3,  pos.x },
        { c2*s3,  s1*s2*s3 + c1*c3,  c1*s2*s3 - s1*c3,  pos.y },
        {  -s2,        s1*c2,             c1*c2,        pos.z }
    }};
}


#if defined __cplusplus
}
#endif
