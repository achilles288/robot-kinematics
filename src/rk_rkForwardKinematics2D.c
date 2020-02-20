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
   rkMat3 Tn;
   int i = 0;
   base->links[0].transform2D  = base->transform2D;

   while(1) {
      float t = va_arg(args, double);
      rkMat3 T = (rkMat3) {{
          {cos(t), -sin(t), 0},
          {sin(t),  cos(t), 0}
          
      }};
      Tn = rkMat3Multiply(base->links[i].transform2D,T);
      if(i+1 > base->count)
          break;
      base->links[i+1].transform2D = Tn;
      i++;
   }
   va_end(args);
   return Tn;
}

#if defined __cplusplus
}
#endif
