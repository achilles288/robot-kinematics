#ifndef __RK_MATH_MATRIX_H__
#define __RK_MATH_MATRIX_H__

#if defined __cplusplus
extern "C" {
#endif


typedef struct _rkMat2x3 rkMat2x3;
typedef struct _rkMat3x4 rkMat3x4;


struct _rkMat2x3 {
    float data[6];
};

struct _rkMat3x4 {
    float data[12];
};


/*
 * 2x3 actually is a 3x3 matrix of which the last row is 0, 0, 1.
 * Stored and computed as 2x3 for memory and performance.
 * 
 * Similar manner for 3x4 as 4x4 matrix.
 */
rkMat2x3 rkMat2x3Multiply(rkMat2x3 A, rkMat2x3 B);
rkMat3x4 rkMat3x4Multiply(rkMat3x4 A, rkMat3x4 B);


#if defined __cplusplus
}
#endif

#endif
