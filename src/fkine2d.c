#include "robotkinematics.h"

#include <stdarg.h>
#include <stdio.h>


#if defined __cplusplus
extern "C" {
#endif


rkMat3 rkForwardKinematics2D(rkArm2D *base, ...) {
    va_list args;
    va_start(args, base);
    
    rkMat3 T = base->transform;
    
    for(int i=0; i < base->count; i++) {
        rkArmLink2D *link = &base->links[i];
        link->q = va_arg(args, double);
        float t = link->q + link->theta;
        float c = cos(t);
        float s = sin(t);
        link->transform = rkMat3Multiply(
            T,
            (rkMat3) {{
                { c, -s,  0 },
                { s,  c,  0 }
            }}
        );
        T = rkMat3Multiply(
            link->transform,
            (rkMat3) {{
                { 1,  0, link->r },
                { 0,  1,    0    }
            }}
        );
    }
    va_end(args);
    return T;
}

#if defined __cplusplus
}
#endif
