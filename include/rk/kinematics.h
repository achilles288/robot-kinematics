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
 * @file kinematics.h
 * @brief All the functions you need for kinematics of a robot arm
 *
 * They compute transformations of kinematic chain with rotary joints. 
 * The main applications are for robot arms, quadruped robots and humanoid 
 * robots. Using forward kinematics, the output of a mechanism obtained from 
 * joint variables can be computed and visualized (both translation and 
 * rotation). For inverse kinematics is used for obtaining joint variables for 
 * a specific coordinate of an end-effector.
 */


#ifndef __RK_KINEMATICS_H__
#define __RK_KINEMATICS_H__

#include "math.h"

#include <stdbool.h>
#include <stdlib.h>


#if defined __cplusplus
extern "C" {
#endif


typedef struct _rkLink2D rkLink2D;
typedef struct _rkLink3D rkLink3D;




/**
 * @brief 2-Dimension kinematic link or chain for revolute joints
 *
 * Kinematic link for 2D revolute joints. 
 * Only one link parameter, the link length. Other members are link position 
 * which is a transform matrix, joint variable and booleans that states the
 * link is start, end or else.
 */
struct _rkLink2D {
    float r; /**< Link length */
    
    rkMat3 transform;
    /**< The matrix representing rotation and translation */
    
    float q; /**< Joint variable */
    
    bool startOfChain;
    bool endOfChain;
};


/**
 * @brief Reserve memory for a number of links.
 *
 * @param count number of links
 * @return Array of links. Kinematic chain.
 */
rkLink2D *rkCreateChain2D(int count);


/**
 * @brief Free memory for kinematic chain.
 *
 * @param ROOT the root link or start of kinematic chain.
 */
#define rkDestroyChain2D(ROOT) \
    free(ROOT)


/**
 * @brief Append a link at the end of a kinematic chain.
 *
 * Constructs a 2D kinematic link of a specified link lengeth. 
 *
 * @param root the root link or start of kinematic chain.
 * @param r link length
 * @return Constructed link
 */
rkLink2D *rkJoinLink2D(rkLink2D *root, float r);


/**
 * @brief Computes 2D link positions from joint variables.
 *
 * Returns end effector transform matrix. Transform matricies of the rest of
 * links can be accessed through data structures. Iteratrative calculation of
 * link positions till the end of chain or the end of variadic parameters.
 * the ending of the variadic parameters is to be specified with a NAN.
 *
 * @param root the start link to begin calculation
 * @param ... joint variables
 * @return Transform matrix of end calculation
 *
 * @code
 * #include <rk/kinematics.h>
 * #include <stdio.h>
 * #include <string.h>
 * 
 * 
 * int main() {
 *     // A 3-DOF chain
 *     rkLink2D *chain = rkCreateChain2D(3);
 *     rkJoinLink2D(chain, 6.2f);
 *     rkJoinLink2D(chain, 5.0f);
 *     rkJoinLink2D(chain, 3.5f);
 *     
 *     // Enter joint variables
 *     char buff[16];
 *     printf("q0: ");
 *     fgets(buff, 16, stdin);
 *     float q0 = atof(buff) * M_PI/180;
 *     memset(buff, 0, sizeof(buff));
 *     printf("q1: ");
 *     fgets(buff, 16, stdin);
 *     float q1 = atof(buff) * M_PI/180;
 *     memset(buff, 0, sizeof(buff));
 *     printf("q2: ");
 *     fgets(buff, 16, stdin);
 *     float q2 = atof(buff) * M_PI/180;
 *     
 *     // Compute output
 *     rkMat3 Tend = rkForwardKinematics2D(chain, q0, q1, q2);
 *     rkVec2 Pend = rkMat3GetTranslation(Tend);
 *     float tend = rkMat3GetRotation(Tend) * 180/M_PI;
 *     
 *     // Print output
 *     for(int i=0; i<3; i++) {
 *         rkMat3 T = chain[i+1].transform;
 *         rkVec2 P = rkMat3GetTranslation(T);
 *         float t = rkMat3GetRotation(T) * 180/M_PI;;
 *         printf("Link%d - x: %.2f y: %.2f t: %.2f\n", i, P.x, P.y, t);
 *     }
 *     printf("End - x: %.2f y: %.2f t: %.2f\n", Pend.x, Pend.y, tend);
 * }
 * @endcode
 *
 * @see rkForwardKinematics2D
 * @see https://github.com/khantkyawkhaung/robot-kinematics/wiki/Forward-Kinematics
 */
rkMat3 _rkForwardKinematics2D(rkLink2D *root, ...);


/**
 * @brief Computes 2D link positions from joint variables.
 *
 * Calls the _rkForwardKinematics2D() function with a NAN at the last parameter
 * predefined.
 *
 * @param ROOT the start link to begin calculation
 * @param ... joint variables
 * @return Transform matrix of end calculation
 */
#define rkForwardKinematics2D(ROOT, ...) \
    _rkForwardKinematics2D((ROOT), __VA_ARGS__, NAN)


/**
 * @brief Computes joint variables from 2D target pose.
 *
 * Uses <b>FABRIK</b> algorithm. The answer joint variables are to be extracted
 * from the data structures after function calling.
 *
 * @param root the start link to begin calculation
 * @param end terminating link (set NULL to proceed to the end of chain)
 * @param pos position of end link
 * @param t orientation of end link (set RK_2D_ORIENTATION_ANY to neglet it)
 */
void rkInverseKinematics2D(rkLink2D *root, rkLink2D *end,
                           rkVec2 pos, float t);




/**
 * @brief 3-Dimension kinematic link or chain for revolute joints
 *
 * Kinematic link for 3D revolute joints. 
 * Defined by the DH parameters. Other members are link position which is a 
 * transform matrix, joint variable and booleans that states the link is 
 * start, end or else.
 */
struct _rkLink3D {
    float d;  /**< Translation along z-axis */
    float theta;  /**< Rotation about z-axis */
    float a;  /**< Translation along rotated x-axis */
    float alpha;  /**< Totation about the new x-axis */
    
    rkMat4 transform;
    /**< The matrix representing rotation and translation */
    
    float q; /**< Joint variable */
    
    bool startOfChain;
    bool endOfChain;
};


/**
 * @brief Reserve memory for a number of links.
 *
 * @param count number of links
 * @return Array of links. Kinematic chain.
 */
rkLink3D *rkCreateChain3D(int count);


/**
 * @brief Free memory for kinematic chain.
 *
 * @param ROOT the root link or start of kinematic chain.
 */
#define rkDestroyChain3D(ROOT) \
    free(ROOT)


/**
 * @brief Append a link at the end of a kinematic chain.
 *
 * Constructs a 3D kinematic link from DH parameters. 
 *
 * @param root the root link or start of kinematic chain.
 * @param d translation along z-axis
 * @param theta rotation about z-axis
 * @param a translation along rotated x-axis
 * @param alpha rotation about the new x-axis
 * @return Constructed link
 *
 * @see https://github.com/khantkyawkhaung/robot-kinematics/wiki/Forward-Kinematics
 */
rkLink3D *rkJoinLink3D(rkLink3D *root, float d, float theta,
                       float a, float alpha);


/**
 * @brief Computes 3D link positions from joint variables.
 *
 * Returns end effector transform matrix. Transform matricies of the rest of
 * links can be accessed through data structures. Iteratrative calculation of
 * link positions till the end of chain or the end of variadic parameters.
 * the ending of the variadic parameters is to be specified with a NAN.
 *
 * @param root the start link to begin calculation
 * @param ... joint variables
 * @return Transform matrix of end calculation
 *
 * @code
 * #include <rk/kinematics.h>
 * #include <stdio.h>
 * #include <string.h>
 * 
 * 
 * int main() {
 *     // A 3-DOF chain
 *     rkLink3D *chain = rkCreateChain3D(3);
 *     rkJoinLink3D(chain, 2.0f, 0, 0, M_PI/2);
 *     rkJoinLink3D(chain, 0, 0, 6.0f, 0);
 *     rkJoinLink3D(chain, 0, 0, 4.5f, 0);
 *     
 *     // Enter joint variables
 *     char buff[16];
 *     printf("q0: ");
 *     fgets(buff, 16, stdin);
 *     float q0 = atof(buff) * M_PI/180;
 *     memset(buff, 0, sizeof(buff));
 *     printf("q1: ");
 *     fgets(buff, 16, stdin);
 *     float q1 = atof(buff) * M_PI/180;
 *     memset(buff, 0, sizeof(buff));
 *     printf("q2: ");
 *     fgets(buff, 16, stdin);
 *     float q2 = atof(buff) * M_PI/180;
 *     
 *     // Compute output
 *     rkMat4 Tend = rkForwardKinematics3D(chain, q0, q1, q2);
 *     rkVec3 Pend = rkMat4GetTranslation(Tend);
 *     rkEuler Rend = rkMat4GetRotation(Tend);
 *     Rend.x *= 180/M_PI;
 *     Rend.y *= 180/M_PI;
 *     Rend.z *= 180/M_PI;
 *     
 *     // Print output
 *     for(int i=0; i<3; i++) {
 *         rkMat4 T = chain[i+1].transform;
 *         rkVec3 P = rkMat4GetTranslation(T);
 *         rkEuler R = rkMat4GetRotation(T);
 *         R.x *= 180/M_PI;
 *         R.y *= 180/M_PI;
 *         R.z *= 180/M_PI;
 *         printf("Link%d - pos: %.2f %.2f %.2f  rot: %.2f %.2f %.2f\n",
 *                 i, P.x, P.y, P.z, R.x, R.y, R.z);
 *     }
 *     printf("End - pos: %.2f %.2f %.2f  rot: %.2f %.2f %.2f\n",
 *             Pend.x, Pend.y, Pend.z, Rend.x, Rend.y, Rend.z);
 * }
 * @endcode
 *
 * @see rkForwardKinematics3D
 * @see _rkForwardKinematics2D
 * @see https://github.com/khantkyawkhaung/robot-kinematics/wiki/Forward-Kinematics
 */
rkMat4 _rkForwardKinematics3D(rkLink3D *root, ...);


/**
 * @brief Computes 3D link positions from joint variables.
 *
 * Calls the _rkForwardKinematics3D() function with a NAN at the last parameter
 * predefined.
 *
 * @param ROOT the start link to begin calculation
 * @param ... joint variables
 * @return Transform matrix of end calculation
 */
#define rkForwardKinematics3D(ROOT, ...) \
    _rkForwardKinematics3D((ROOT), __VA_ARGS__, NAN)


/**
 * @brief Computes joint variables from 3D target pose.
 *
 * Uses <b>FABRIK</b> algorithm. The answer joint variables are to be extracted
 * from the data structures after function calling.
 *
 * @param root the start link to begin calculation
 * @param end terminating link (set NULL to proceed to the end of chain)
 * @param pos position of end link
 * @param rot orientation of end link (set RK_3D_ORIENTATION_ANY to neglet it)
 */
void rkInverseKinematics3D(rkLink3D *root, rkLink3D *end,
                           rkVec3 pos, rkEuler rot);




#define RK_2D_ORIENTATION_ANY NAN
#define RK_3D_ORIENTATION_ANY ((rkEuler) {NAN, NAN, NAN})


#if defined __cplusplus
}
#endif

#endif
