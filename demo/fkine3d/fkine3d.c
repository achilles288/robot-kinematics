#include <rk/kinematics.h>
#include <stdio.h>
#include <string.h>


int main() {
    // A 3-DOF chain
    rkLink3D *chain = rkCreateChain3D(3);
    rkJoinLink3D(chain, 2.0f, 0, 0, M_PI/2);
    rkJoinLink3D(chain, 0, 0, 6.0f, 0);
    rkJoinLink3D(chain, 0, 0, 4.5f, 0);
    
    // Enter joint variables
    char buff[16];
    printf("q0: ");
    fgets(buff, 16, stdin);
    float q0 = atof(buff) * M_PI/180;
    memset(buff, 0, sizeof(buff));
    printf("q1: ");
    fgets(buff, 16, stdin);
    float q1 = atof(buff) * M_PI/180;
    memset(buff, 0, sizeof(buff));
    printf("q2: ");
    fgets(buff, 16, stdin);
    float q2 = atof(buff) * M_PI/180;
    
    // Compute output
    rkMat4 Tend = rkForwardKinematics3D(chain, q0, q1, q2);
    rkVec3 Pend = rkMat4GetTranslation(Tend);
    rkEuler Rend = rkMat4GetRotation(Tend);
    Rend.x *= 180/M_PI;
    Rend.y *= 180/M_PI;
    Rend.z *= 180/M_PI;
    
    // Print output
    for(int i=0; i<3; i++) {
        rkMat4 T = chain[i+1].transform;
        rkVec3 P = rkMat4GetTranslation(T);
        rkEuler R = rkMat4GetRotation(T);
        R.x *= 180/M_PI;
        R.y *= 180/M_PI;
        R.z *= 180/M_PI;
        printf("Link%d - pos: %.2f %.2f %.2f  rot: %.2f %.2f %.2f\n",
                i, P.x, P.y, P.z, R.x, R.y, R.z);
    }
    printf("End - pos: %.2f %.2f %.2f  rot: %.2f %.2f %.2f\n",
            Pend.x, Pend.y, Pend.z, Rend.x, Rend.y, Rend.z);
}
