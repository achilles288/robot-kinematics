#include "robotkinematics.h"


#if defined __cplusplus
extern "C" {
#endif


rkArmLink3D *rkCreateArm3D(int count) {
    rkArmLink3D *arm = (rkArmLink3D*) malloc((count+1) * sizeof(rkArmLink3D));
    for(int i=0; i<count; i++) {
        arm[i].q = 0;
        arm[i].transform = (rkMat4) {{
            {1, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 1, 0}
        }};
        arm[i].startOfChain = true;
        arm[i].endOfChain = true;
    }
    arm->startOfChain = true;
    return arm;
}


#if defined __cplusplus
}
#endif
