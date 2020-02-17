#include "../robotkinematics/matrix.h"


#if defined __cplusplus
extern "C" {
#endif


rkMat2x3 rkMat2x3Multiply(rkMat2x3 A, rkMat2x3 B) {
    rkMat2x3 C;
    
    C.data[0] = A.data[0]*B.data[0] + A.data[1]*B.data[3];
    C.data[1] = A.data[0]*B.data[1] + A.data[1]*B.data[4];
    C.data[2] = A.data[0]*B.data[2] + A.data[1]*B.data[5] + A.data[2];
    
    C.data[3] = A.data[3]*B.data[0] + A.data[4]*B.data[3];
    C.data[4] = A.data[3]*B.data[1] + A.data[4]*B.data[4];
    C.data[5] = A.data[3]*B.data[2] + A.data[4]*B.data[5] + A.data[5];
    
    return C;
}


#if defined __cplusplus
}
#endif
