#include "robotkinematics.h"

#include <stdlib.h>


#if defined __cplusplus
extern "C" {
#endif


rkArm2D *rkCreateArm(int count) {
    rkArm2D *arm = (rkArm2D*) malloc(sizeof(rkArm2D));
    arm->links = (rkArmLink2D*) malloc(count * sizeof(rkArmLink2D));
    arm->count = 0;
    arm->reservedCount = count;
    arm->transform = (rkMat3) {{
        {1, 0, 0},
        {0, 1, 0}
    }};
    return arm;
}


#if defined __cplusplus
}
#endif
