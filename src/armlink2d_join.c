#include "robotkinematics.h"


#if defined __cplusplus
extern "C" {
#endif


rkArmLink2D *rkJoinArmLink2D(rkArmLink2D *root, float r, float theta)
{
    rkArmLink2D *link = root;
    while(!link->endOfChain) { ++link; }
    
    link->endOfChain = false;
    link++;
    link->r = r;
    link->theta = theta;
    return link;
}


#if defined __cplusplus
}
#endif
