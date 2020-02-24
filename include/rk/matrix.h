#ifndef __RK_MATH_MATRIX_H__
#define __RK_MATH_MATRIX_H__

#include "vector.h"

#if defined __cplusplus
extern "C" {
#endif


typedef struct _rkMat3 rkMat3;
typedef struct _rkMat4 rkMat4;


/*
 * In these data structures, one bottom row is removed.
 * The third block is always 0s and the fourth part a 1.
 * The row is not used in computation for better performance.
 */
struct _rkMat3 {
    float data[2][3];
};

struct _rkMat4 {
    float data[3][4];
};



rkMat3 rkMat3Multiply(rkMat3 A, rkMat3 B);
rkMat3 rkMat3Transform(rkVec2 pos, float t);

#define rkMat3GetRotation(M) \
    atan2((M).data[1][0], (M).data[0][0])

#define rkMat3GetTranslation(M) \
    ((rkVec2) {(M).data[0][2], (M).data[1][2]})



rkMat4 rkMat4Multiply(rkMat4 A, rkMat4 B);

/*
 * The rotation part is defined in terms of euler angles.
 * The rotation order is ZYX.
 * Z = yaw  Y = pitch  X = roll
 */
rkMat4 rkMat4Transform(rkVec3 pos, rkEuler rot);

rkEuler rkMat4GetRotation(rkMat4 M);

#define rkMat4GetTranslation(M) \
    ((rkVec3) {(M).data[0][3], (M).data[1][3], (M).data[2][3]})


#if defined __cplusplus
}
#endif

#endif
