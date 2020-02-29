#include <rk/kinematics.h>


#if defined __cplusplus
extern "C" {
#endif


rkLink3D *rkCreateChain3D(int count) {
    rkLink3D *chain = (rkLink3D*) malloc((count+1) * sizeof(rkLink3D));
    for(int i=0; i<count+1; i++) {
        chain[i].q = 0;
        chain[i].transform = (rkMat4) {{
            {1, 0, 0, 0},
            {0, 1, 0, 0},
            {0, 0, 1, 0}
        }};
        chain[i].startOfChain = false;
        chain[i].endOfChain = true;
    }
    chain->startOfChain = true;
    return chain;
}


#if defined __cplusplus
}
#endif
