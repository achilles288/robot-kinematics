#include "robotkinematics.h"

#include <stdlib.h>


#if defined __cplusplus
extern "C" {
#endif


rkArmLink2D *rkCreateArmLink2D(rkArm2D *base, float r, float theta)
{
    if(base->count == base->reservedCount) {
        base->links = (rkArmLink2D*) realloc(
                          base->links,
                          (base->count+1) * sizeof(rkArmLink2D)
                      );
        base->reservedCount++;
    }
    rkArmLink2D *link = &base->links[base->count];
    link->r = r;
    link->theta = theta;
    base->count++;
    return link;
}


#if defined __cplusplus
}
#endif
