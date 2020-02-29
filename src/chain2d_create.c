#include <rk/kinematics.h>


#if defined __cplusplus
extern "C" {
#endif


rkLink2D *rkCreateChain2D(int count) {
    rkLink2D *chain = (rkLink2D*) malloc((count+1) * sizeof(rkLink2D));
    for(int i=0; i<count+1; i++) {
        chain[i].q = 0;
        chain[i].transform = (rkMat3) {{
            {1, 0, 0},
            {0, 1, 0}
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
