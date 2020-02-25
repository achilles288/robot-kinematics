#include <rk/matrix.h>

#include <stdio.h>


#if defined __cplusplus
extern "C" {
#endif


void rkMat4Print(rkMat4 M) {
    printf("{{%.2f %.2f %.2f %.2f}\n"
           " {%.2f %.2f %.2f %.2f}\n"
           " {%.2f %.2f %.2f %.2f}\n"
           " {0 0 0 1}}\n",
           M.data[0][0], M.data[0][1], M.data[0][2], M.data[0][3],
           M.data[1][0], M.data[1][1], M.data[1][2], M.data[1][3],
           M.data[2][0], M.data[2][1], M.data[2][2], M.data[2][3]);
}


#if defined __cplusplus
}
#endif
