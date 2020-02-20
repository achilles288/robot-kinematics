#include "robotkinematics.h"

#include <stdlib.h>


#if defined __cplusplus
extern "C" {
#endif


void rkDestroyArm2D(rkArm2D *arm) {
    free(arm->links);
    free(arm);
}


#if defined __cplusplus
}
#endif
