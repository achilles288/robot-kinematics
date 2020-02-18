#include "../robotkinematics/matrix.h"


#if defined __cplusplus
extern "C" {
#endif


rkMat3 rkMat3Multiply(rkMat3 A, rkMat3 B) {
    rkMat3 C;
    
    C.data[0][0] = A.data[0][0]*B.data[0][0] + A.data[0][1]*B.data[1][0];
    C.data[0][1] = A.data[0][0]*B.data[0][1] + A.data[0][1]*B.data[1][1];
    C.data[0][2] = A.data[0][0]*B.data[0][2] + A.data[0][1]*B.data[1][2] + A.data[0][2];
    
    C.data[1][0] = A.data[1][0]*B.data[0][0] + A.data[1][1]*B.data[1][0];
    C.data[1][1] = A.data[1][0]*B.data[0][1] + A.data[1][1]*B.data[1][1];
    C.data[1][2] = A.data[1][0]*B.data[0][2] + A.data[1][1]*B.data[1][2] + A.data[1][2];
    
    return C;
}


#if defined __cplusplus
}
#endif
