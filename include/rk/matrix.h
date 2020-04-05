/****************************************************************************
 * Copyright (C) 2020 by Khant Kyaw Khaung                                  *
 *                                                                          *
 * This file is part of Robot Kinematics.                                   *
 *                                                                          *
 *   Robot Kinematics is free software: you can redistribute it and/or      *
 *   modify it under the terms of the GNU General Public License as         *
 *   published by the Free Software Foundation, either version 3 of the     *
 *   License, or (at your option) any later version.                        *
 *                                                                          *
 *   Robot Kinematics is distributed in the hope that it will be useful,    *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the           *
 *   GNU General Public License for more details.                           *
 *                                                                          *
 *   You should have received a copy of the GNU General Public License      *
 *   along with Robot Kinematics. If not, see                               *
 *   <http://www.gnu.org/licenses/>.                                        *
 ****************************************************************************/


/**
 * @file matrix.h
 * @brief The header declaring 3x3 and 4x4 matrix structures and functions
 *
 * 3x3 and 4x4 matrices. However, they have an exceptional having one row 
 * removed. The third block is always 0s and the fourth part a 1.
 * The row is not used in computation for better performance. 
 * These matrix structures and functions are only for rotation and translation 
 * applications.
 */


#ifndef __RK_MATH_MATRIX_H__
#define __RK_MATH_MATRIX_H__

#include "vector.h"

#if defined __cplusplus
extern "C" {
#endif


typedef struct _rkMat3 rkMat3;
typedef struct _rkMat4 rkMat4;


/**
 * @brief 3x3 matrix
 *
 * 3x3 matrix with just an array of single precision floats. 
 * The bottom row does not exist and is always assumed 0, 0, 1.
 * Use them for rotation and translation applications.
 */
struct _rkMat3 {
    float data[2][3];
};

/**
 * @brief 4x4 matrix
 *
 * 4x4 matrix with just an array of single precision floats.
 * The bottom row does not exist and is always assumed 0, 0, 0, 1.
 * Use them for rotation and translation applications.
 */
struct _rkMat4 {
    float data[3][4];
};




/**
 * @brief Multiply 2 3x3 matrices.
 *
 * @param A Matrix A
 * @param B Matrix B
 * @return Resultant matrix
 */
rkMat3 rkMat3Multiply(rkMat3 A, rkMat3 B);


/**
 * @brief Generates a 3x3 matrix from position and rotation.
 *
 * @param pos A vector with xy coordinates
 * @param t rotation
 * @return Transform matrix
 */
rkMat3 rkMat3Transform(rkVec2 pos, float t);


/**
 * @brief Calculate rotation angle from some members of the matrix
 *
 * @param M Transform matrix
 * @return Rotation angle
 */
#define rkMat3GetRotation(M) \
    (atan2((M).data[1][0], (M).data[0][0]))


/**
 * @brief Extracts the position vector from the matrix
 *
 * @param M Transform matrix
 * @return Position vector
 */
#define rkMat3GetTranslation(M) \
    ((rkVec2) {(M).data[0][2], (M).data[1][2]})




/**
 * @brief Multiply 2 4x4 matrices.
 *
 * @param A Matrix A
 * @param B Matrix B
 * @return Resultant matrix
 */
rkMat4 rkMat4Multiply(rkMat4 A, rkMat4 B);


/**
 * @brief Generates a 4x4 matrix from position and rotation.
 *
 * @param pos A vector with xyz coordinates
 * @param rot Euler angles representing yaw, pitch, roll
 * @return Transform matrix
 */
rkMat4 rkMat4Transform(rkVec3 pos, rkEuler rot);


/**
 * @brief Calculate the euler angles from the members of the matrix
 *
 * Calculation is done by applying functions to certain cells of the matrix.
 * According to the formula derivation, there are 3 branches for the code.
 * In case of Gimbal Lock, since cos(theta) is 0 and the default division
 * by cos(theta) functions don't work, there use alternative approach.
 *
 * @param M Transform matrix
 * @return Euler angles
 *
 * @see https://github.com/khantkyawkhaung/robot-kinematics/wiki/Euler-And-Matrix
 */
rkEuler rkMat4GetRotation(rkMat4 M);


/**
 * @brief Extracts the position vector from the matrix
 *
 * @param M Transform matrix
 * @return Position vector
 */
#define rkMat4GetTranslation(M) \
    ((rkVec3) {(M).data[0][3], (M).data[1][3], (M).data[2][3]})




/**
 * @brief Prints all the cells of the matrix on the console
 * 
 * @param M The matrix
 *
 * @par Output
 * Function ouput on the console looks like
 * @code
 * ┌─                        ─┐
 * │ 0.8068, -0.5908, 34.7200 │
 * │ 0.5908,  0.8068, 44.3000 │
 * └─                        ─┘
 * @endcode
 */
#define rkMat3Print(M) ({ \
    rkMat3 *__p = &(M); \
    rkMatPrint(__p, RK_MAT3); })

/**
 * @brief Prints all the cells of the matrix on the console
 * 
 * @param M The matrix
 * 
 * @par Output
 * Function ouput on the console looks like
 * @code
 * ┌─                                   ─┐
 * │ -0.0000, -0.9014,  0.4330, 124.6600 │
 * │ -0.0000,  0.4330,  0.9014, -54.3000 │
 * │ -1.0000, -0.0000, -0.0000,   6.3450 │
 * └─                                   ─┘
 * @endcode
 */
#define rkMat4Print(M)  ({ \
    rkMat4 *__p = &(M); \
    rkMatPrint(__p, RK_MAT4); })


#define RK_MAT3 0
#define RK_MAT4 1

void rkMatPrint(void *ptr, int type);


#if defined __cplusplus
}
#endif

#endif
