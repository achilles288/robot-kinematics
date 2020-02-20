#include "robotkinematics.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>


#if defined __cplusplus
extern "C" {
#endif

//dont know how to do with translation part

rkMat3 rkForwardKinematics2D(rkArm2D *base, ...) {
   va_list args;
   va_start(args, base);
   rkMat3 Tn = {{
       {1,0,0},
       {0,1,0}
   }};
   
   for(int i=0; i<base->count; i++) {
      float t = va_arg(args, double);
      rkMat3 T = (rkMat3) {{
          {cos(t), -sin(t), 0},
          {sin(t),  cos(t), 0}
          
      }};
      Tn = rkMat3Multiply(Tn,T);
   }
   va_end(args);
   return Tn;
   
}

#if defined __cplusplus
}
#endif
