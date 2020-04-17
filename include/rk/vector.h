/**
 * @file vector.h
 * @brief 2D and 3D vector structures and functions
 *
 * Vecotr dot product, cross product and normalization functions.
 * 
 * @copyright Copyright (c) 2020 Khant Kyaw Khaung
 * 
 * @license{This project is released under the MIT License.}
 */


#ifndef __RK_MATH_VECTOR_H__
#define __RK_MATH_VECTOR_H__

#include <math.h>


#if defined __cplusplus
extern "C" {
#endif


typedef struct _rkVec2 rkVec2;
typedef struct _rkVec3 rkVec3;


/**
 * @brief A set of floats representing xy coordinates
 */
struct _rkVec2 {
    float x;
    float y;
};


/**
 * @brief Normalize a 2D vector.
 *
 * @param v Vector to normalize
 * @return Unit vector having the same direction as the input vector
 */
rkVec2 rkVec2Normalize(rkVec2 v);


/**
 * @brief 2D vector dot product operation.
 *
 * @param A Vector a
 * @param B Vector b
 * @return Dot product
 */
#define rkVec2Dot(A, B) \
    ((A).x*(B).x + (A).y*(B).y)


/**
 * @brief 2D vector cross product operation.
 *
 * @param A Vector a
 * @param B Vector b
 * @return Cross product
 */
#define rkVec2Cross(A, B) \
    ((A).x*(B).y - (A).y*(B).x)




/**
 * @brief A set of floats representing xyz coordinates
 */
struct _rkVec3 {
    float x;
    float y;
    float z;
};

typedef rkVec3 rkEuler;


/**
 * @brief Normalize a 3D vector.
 *
 * @param v Vector to normalize
 * @return Unit vector having the same direction as the input vector
 */
rkVec3 rkVec3Normalize(rkVec3 v);


/**
 * @brief 3D vector dot product operation.
 *
 * @param a Vector a
 * @param b Vector b
 * @return Dot product
 */
float rkVec3Dot(rkVec3 a, rkVec3 b);


/**
 * @brief 3D vector cross product operation.
 *
 * @param a Vector a
 * @param b Vector b
 * @return Cross product
 */
rkVec3 rkVec3Cross(rkVec3 a, rkVec3 b);


#if defined __cplusplus
}
#endif

#endif
