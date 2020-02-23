#include "robotkinematics.h"


#if defined __cplusplus
extern "C" {
#endif


rkArmLink3D *rkJoinArmLink3D(rkArmLink3D *root, float d, float a,
                               float theta, float alpha)
{
    rkArmLink3D *link = root;
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
