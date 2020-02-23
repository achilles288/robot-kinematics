#include "robotkinematics.h"

#include <stdarg.h>


#if defined __cplusplus
extern "C" {
#endif


rkMat4 _rkForwardKinematics3D(rkArmLink3D *root, ...) {
    va_list args;
    va_start(args, root);
    
    rkArmLink3D *link = root;
    rkMat4 T = link->transform;
    
    if(link->startOfChain)
        link++;
    
    do {
        float q = va_arg(args, double);
        if(isnan(q))
            break;
        link->q = q;
        float t = q + link->theta;
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
                { 1,   0,   0, link->a },
                { 0,  cA, -sA,    0    },
                { 0,  sA,  cA, link->d }
            }}
        );
    } while(!(link++)->endOfChain);
    
    if(!link->endOfChain)
        (++link)->transform = T;
    
    va_end(args);
    return T;
}

#if defined __cplusplus
}
#endif
