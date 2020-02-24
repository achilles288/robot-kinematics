#include "robotkinematics.h"
#include <stdio.h>
#include <time.h>


clock_t start[10],end[10];
double time_taken[10];
double dt1 = 0;
double dt2 = 0;
double dt3 = 0;
double dt4 = 0;
double dt5 = 0;
rkMat3 m[10],t[10];
rkMat4 b[10];

int main(){
     //Forward kinematics
     rkArm2D* base = rkCreateArm2D(3);
     
     for(int i = 0;i<10;i++){
       start[i] = clock();
       m[i] = rkForwardKinematics2D(base,90,90,90);
       end[i] = clock();
       time_taken[i] = ((double) (end[i] - start[i]))/CLOCKS_PER_SEC;
       dt1 += time_taken[i];
     }
     printf("Forwardkinematics takes %f milliseconds to execute \n", dt1/10 * 1000);
     
     //Matrix 3x3 multiplication
     rkMat3 A = (rkMat3){{
       {1,0,1},
       {1,0,1},
     }};
     
     rkMat3 B = (rkMat3){{
       {1,0,1},
       {1,0,1},
     }};
     
     for(int i = 0;i<10;i++){
       start[i] = clock();
       A = rkMat3Multiply(A,B);
       end[i] = clock();
       time_taken[i] = ((double) (end[i] - start[i]))/CLOCKS_PER_SEC;
       dt2 += time_taken[i];
     }
     printf("Matrix 3x3 multiplication takes %f milliseconds to execute \n", dt2/10 * 1000);
     
     //Matrix 4x4 multiplication
     rkMat4 C = (rkMat4){{
       {1,0,0,0},
       {1,0,0,0},
       {1,0,0,0},
     }};
     
     rkMat4 D = (rkMat4){{
       {1,0,0,0},
       {1,0,0,0},
       {1,0,0,0},
     }};
     
     for(int i = 0;i<10;i++){
       start[i] = clock();
       C = rkMat4Multiply(C,D);
       end[i] = clock();
       time_taken[i] = ((double) (end[i] - start[i]))/CLOCKS_PER_SEC;
       dt3 += time_taken[i];
     }
     printf("Matrix 4x4 multiplication takes %f milliseconds to execute \n", dt3/10 * 1000);
     
     
     //Transform matrix 2D
     rkVec2 v2 = (rkVec2){ 8,12 };
     for(int i = 0;i<10;i++){
       start[i] = clock();
       t[i] = rkMat3Transform(v2, 20);;
       end[i] = clock();
       time_taken[i] = ((double) (end[i] - start[i]))/CLOCKS_PER_SEC;
       dt4 += time_taken[i];
     }
     printf("Transfor2D takes %f milliseconds to execute \n", dt4/10 * 1000);
     
     //Transform matrix 3D
     rkVec3 v3 = (rkVec3){ 8,12,11 };
     rkEuler r = rkMat4GetRotation(C);
     for(int i = 0;i<10;i++){
       start[i] = clock();
       b[i] = rkMat4Transform(v3, r);;
       end[i] = clock();
       time_taken[i] = ((double) (end[i] - start[i]))/CLOCKS_PER_SEC;
       dt5 += time_taken[i];
     }
     printf("Transform3D takes %f milliseconds to execute \n", dt5/10 * 1000);
     
}
