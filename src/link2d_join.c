#include <rk/kinematics.h>


#if defined __cplusplus
extern "C" {
#endif


rkLink2D *rkJoinLink2D(rkLink2D *root, float r)
{
    rkLink2D *link = root;
    while(!link->endOfChain) { ++link; }
    
    link->endOfChain = false;
    link++;
    link->r = r;
    return link;
}


#if defined __cplusplus
}
#endif
