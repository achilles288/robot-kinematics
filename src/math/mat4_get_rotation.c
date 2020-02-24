#include <rk/matrix.h>

#include <math.h>
#include <stdlib.h>


#if defined __cplusplus
extern "C" {
#endif


rkEuler rkMat4GetRotation(rkMat4 M) {
    float roll, pitch, yaw;
    pitch = -asin(M.data[2][0]);
    float c2 = cos(pitch);
    
    // cos(pitch) != 0
    if(fabs(c2) > 0.001f) {
        roll = atan2(M.data[2][1]/c2, M.data[2][2]/c2);
        yaw = atan2(M.data[1][0]/c2, M.data[0][0]/c2);
    }
    else {
        // Gimbal lock position
        if(pitch > 0) { // pitch = pi/2
            roll = atan2(M.data[0][1], M.data[0][2]);
            yaw = 0;
        }
        else { // pitch = -pi/2
            roll = atan2(-M.data[0][1], -M.data[0][2]);
            yaw = 0;
        }
    }
    return (rkEuler) {roll, pitch, yaw};
}


#if defined __cplusplus
}
#endif
