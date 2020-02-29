#include <rk/kinematics.h>


#if defined __cplusplus
extern "C" {
#endif


rkLink3D *rkJoinLink3D(rkLink3D *root, float d, float theta,
                       float a, float alpha)
{
    rkLink3D *link = root;
    while(!link->endOfChain) { ++link; }
    
    link->endOfChain = false;
    link++;
    link->d = d;
    link->theta = theta;
    link->a = a;
    link->alpha = alpha;
    return link;
}


#if defined __cplusplus
}
#endif
