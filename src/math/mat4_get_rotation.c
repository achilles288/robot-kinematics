#include "../robotkinematics/matrix.h"

#include <math.h>


#if defined __cplusplus
extern "C" {
#endif


rkEuler rkMat4GetRotation(rkMat4 M) {
    return (rkEuler) {0, 0, 0};
}


#if defined __cplusplus
}
#endif
