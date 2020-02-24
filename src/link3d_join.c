#include <rk/kinematics.h>


#if defined __cplusplus
extern "C" {
#endif


rkLink3D *rkJoinLink3D(rkLink3D *root, float d, float a,
                               float theta, float alpha)
{
    rkLink3D *link = root;
    while(!link->endOfChain) { ++link; }
    
    link->endOfChain = false;
    link++;
    link->d = d;
    link->a = a;
    link->theta = theta;
    link->alpha = alpha;
    return link;
}


#if defined __cplusplus
}
#endif
