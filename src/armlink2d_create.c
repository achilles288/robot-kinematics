#include "robotkinematics.h"


#if defined __cplusplus
extern "C" {
#endif


rkArmLink2D *rkCreateArmLink(rkArm2D *base, float r, float theta)
{
    rkArmLink2D *link = &base->links[base->count];
    link->r = r;
    link->theta = theta;
    return link;
}


#if defined __cplusplus
}
#endif
