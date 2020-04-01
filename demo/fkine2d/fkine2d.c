#include <rk/kinematics.h>
#include <stdio.h>
#include <string.h>


int main() {
    // A 3-DOF chain
    rkLink2D *chain = rkCreateChain2D(3);
    rkJoinLink2D(chain, 6.2f);
    rkJoinLink2D(chain, 5.0f);
    rkJoinLink2D(chain, 3.5f);
    
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
    rkMat3 Tend = rkForwardKinematics2D(chain, q0, q1, q2);
    rkVec2 Pend = rkMat3GetTranslation(Tend);
    float tend = rkMat3GetRotation(Tend) * 180/M_PI;
    
    // Print output
    for(int i=0; i<3; i++) {
        rkMat3 T = chain[i+1].transform;
        rkVec2 P = rkMat3GetTranslation(T);
        float t = rkMat3GetRotation(T) * 180/M_PI;;
        printf("Link%d - x: %.2f y: %.2f t: %.2f\n", i, P.x, P.y, t);
    }
    printf("End - x: %.2f y: %.2f t: %.2f\n", Pend.x, Pend.y, tend);
}
