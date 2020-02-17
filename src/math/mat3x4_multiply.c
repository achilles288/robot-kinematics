#include "../robotkinematics/matrix.h"


#if defined __cplusplus
extern "C" {
#endif


rkMat3x4 rkMat3x4Multiply(rkMat3x4 A, rkMat3x4 B) {
    rkMat3x4 C;
    
    C.data[0]  = A.data[0]*B.data[0] + A.data[1]*B.data[4] + A.data[2]*B.data[8];
    C.data[1]  = A.data[0]*B.data[1] + A.data[1]*B.data[5] + A.data[2]*B.data[9];
    C.data[2]  = A.data[0]*B.data[2] + A.data[1]*B.data[6] + A.data[2]*B.data[10];
    C.data[3]  = A.data[0]*B.data[3] + A.data[1]*B.data[7] + A.data[2]*B.data[11] + A.data[3];
    
    C.data[4]  = A.data[4]*B.data[0] + A.data[5]*B.data[4] + A.data[6]*B.data[8];
    C.data[5]  = A.data[4]*B.data[1] + A.data[5]*B.data[5] + A.data[6]*B.data[9];
    C.data[6]  = A.data[4]*B.data[2] + A.data[5]*B.data[6] + A.data[6]*B.data[10];
    C.data[7]  = A.data[4]*B.data[3] + A.data[5]*B.data[7] + A.data[6]*B.data[11] + A.data[7];
    
    C.data[8]  = A.data[8]*B.data[0] + A.data[9]*B.data[4] + A.data[10]*B.data[8];
    C.data[9]  = A.data[8]*B.data[1] + A.data[9]*B.data[5] + A.data[10]*B.data[9];
    C.data[10] = A.data[8]*B.data[2] + A.data[9]*B.data[6] + A.data[10]*B.data[10];
    C.data[11] = A.data[8]*B.data[3] + A.data[9]*B.data[7] + A.data[10]*B.data[11] + A.data[11];
    
    return C;
}


#if defined __cplusplus
}
#endif
