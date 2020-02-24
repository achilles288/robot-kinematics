#include <rk/kinematics.h>

#include <stdarg.h>


#if defined __cplusplus
extern "C" {
#endif


rkMat4 _rkForwardKinematics3D(rkLink3D *root, ...) {
    va_list args;
    va_start(args, root);
    
    rkLink3D *link = root;
    rkMat4 T = link->transform;
    
    if(link->startOfChain)
        link++;
    
    do {
        float q = va_arg(args, double);
        if(isnan(q))
            break;
        link->q = q;
        float c = cos(q);
        float s = sin(q);
        link->transform = rkMat4Multiply(
            T,
            (rkMat4) {{
                { c, -s,  0,  0 },
                { s,  c,  0,  0 },
                { 0,  0,  1,  0 }
            }}
        );
        
        float cT = cos(link->theta);
        float sT = sin(link->theta);
        float cA = cos(link->alpha);
        float sA = sin(link->alpha);
        T = rkMat4Multiply(
            link->transform,
            (rkMat4) {{
                { cT, -sT*cA,  sT*sA, link->a*cA },
                { sT,  cT*cA, -cT*sA, link->a*sT },
                {  0,    sA ,    cA , link->d }
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
