#include <rk/matrix.h>

#include <math.h>


#if defined __cplusplus
extern "C" {
#endif


rkMat3 rkMat3Transform(rkVec2 pos, float t) {
    float c = cos(t);
    float s = sin(t);
    return (rkMat3) {{
        { c, -s, pos.x },
        { s,  c, pos.y }
    }};
}


#if defined __cplusplus
}
#endif
