#include "../robotkinematics/matrix.h"


#if defined __cplusplus
extern "C" {
#endif


rkMat4 rkMat4Multiply(rkMat4 A, rkMat4 B) {
    rkMat4 C;
    
    C.data[0][0] = A.data[0][0]*B.data[0][0] + A.data[0][1]*B.data[1][0] + A.data[0][2]*B.data[3][0];
    C.data[0][1] = A.data[0][0]*B.data[0][1] + A.data[0][1]*B.data[1][1] + A.data[0][2]*B.data[3][1];
    C.data[0][2] = A.data[0][0]*B.data[0][2] + A.data[0][1]*B.data[1][2] + A.data[0][2]*B.data[3][2];
    C.data[0][3] = A.data[0][0]*B.data[0][3] + A.data[0][1]*B.data[1][3] + A.data[0][2]*B.data[3][3] + A.data[0][3];
    
    C.data[1][0] = A.data[1][0]*B.data[0][0] + A.data[1][1]*B.data[1][0] + A.data[1][2]*B.data[3][0];
    C.data[1][1] = A.data[1][0]*B.data[0][1] + A.data[1][1]*B.data[1][1] + A.data[1][2]*B.data[3][1];
    C.data[1][2] = A.data[1][0]*B.data[0][2] + A.data[1][1]*B.data[1][2] + A.data[1][2]*B.data[3][2];
    C.data[1][3] = A.data[1][0]*B.data[0][3] + A.data[1][1]*B.data[1][3] + A.data[1][2]*B.data[3][3] + A.data[1][3];
    
    C.data[2][0] = A.data[2][0]*B.data[0][0] + A.data[2][1]*B.data[1][0] + A.data[2][2]*B.data[3][0];
    C.data[2][1] = A.data[2][0]*B.data[0][1] + A.data[2][1]*B.data[1][1] + A.data[2][2]*B.data[3][1];
    C.data[2][2] = A.data[2][0]*B.data[0][2] + A.data[2][1]*B.data[1][2] + A.data[2][2]*B.data[3][2];
    C.data[2][3] = A.data[2][0]*B.data[0][3] + A.data[2][1]*B.data[1][3] + A.data[2][2]*B.data[3][3] + A.data[2][3];
    
    return C;
}


#if defined __cplusplus
}
#endif
