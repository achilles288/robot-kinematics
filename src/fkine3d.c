#include "robotkinematics.h"

#include <stdarg.h>
#include <stdio.h>


#if defined __cplusplus
extern "C" {
#endif


rkMat4 rkForwardKinematics3D(rkArm3D *base, ...) {
    va_list args;
    va_start(args, base);
    
    rkMat4 T = base->transform;
    
    for(int i=0; i < base->count; i++) {
        rkArmLink3D *link = &base->links[i];
        link->q = va_arg(args, double);
        float t = link->q + link->theta;
        float cT = cos(t);
        float sT = sin(t);
        link->transform = rkMat4Multiply(
            T,
            (rkMat4) {{
                { cT, -sT,  0,  0 },
                { sT,  cT,  0,  0 },
                {  0,   0,  1,  0 }
            }}
        );
        
        float cA = cos(link->alpha);
        float sA = sin(link->alpha);
        T = rkMat4Multiply(
            link->transform,
            (rkMat4) {{
                { cA, -sA,  0, link->d },
                { sA,  sA,  0,    0    },
                {  0,   0,  1, link->a }
            }}
        );
    }
    va_end(args);
    return T;
}

#if defined __cplusplus
}
#endif
