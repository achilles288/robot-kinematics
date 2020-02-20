#include "robotkinematics.h"

#include <stdarg.h>


#if defined __cplusplus
extern "C" {
#endif


rkMat3 rkForwardKinematics2D(rkArm2D *base, ...) {
    va_list args;
    va_start(args, base);
    
    rkMat3 Ti;
    base->links[0].transform  = base->transform;
    int i = 0;
    
    while(1) {
        rkArmLink2D *link = &base->links[i];
        link->q = va_arg(args, double);
        float t = link->q + link->theta;
        float c = cos(t);
        float s = sin(t);
        rkMat3 T = (rkMat3) {{
            { c, -s, link->r },
            { s,  c,    0    }
        }};
        Ti = rkMat3Multiply(T, base->links[i].transform);
        if(i+1 > base->count)
            break;
        base->links[i+1].transform = Ti;
        i++;
    }
    va_end(args);
    return Ti;
}

#if defined __cplusplus
}
#endif
