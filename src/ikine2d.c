#include <rk/kinematics.h>

#include <stdio.h>


#if defined __cplusplus
extern "C" {
#endif


void rkInverseKinematics2D(rkLink2D *root, rkLink2D *end,rkVec2 pos, float t) {
   rkLink2D *link = root;
   rkLink2D *ee   = end;
   float tar = rkVec2Normalize(pos);
   float cur = rkVec2Normalize(rkMat3GetTranslation(ee->transform));
   float err = tar - cur;
   int count = 0;
   int totalLength = 0;
         
    if(link->startOfChain)
        link++;
    
    do {
        count++;
        totalLength += rkVec2Normalize(rkMat3GetTranslation(link->transform));
    } while(!(link++)->endOfChain);
    
    
    rkVec2 P[count],PP[count],PPP[count],u[count],uu[count];
    float l[count];

    if(tar<totalLength){
      for(int i=0; i<count; i++){
         P[i] = rkMat3GetTranslation(link->transform);
      }
      while(err<5){
         //bwd iteration
         for(int i=count; i>2 ;i--){
           l[i]  = rkVec2Normalize(rkMat3GetTranslation(link->transform));
           u[i].x  = P[i].x-P[i-2].x; 
           u[i].y  = P[i].y-P[i-2].y;
           PP[i].x = l[i] * u[i].x;
           PP[i].y = l[i]  * u[i].y; 
         }

         //fwd iteration
         for(int i=1; i<count ;i++){
           uu[i].x  = PP[i].x-PP[i-1].x; 
           uu[i].y  = PP[i].y-PP[i-1].y;
           PPP[i].x = uu[i].x * l[i]; 
           PPP[i].y = uu[i].y * l[i]; 
         }
      }
   }
   else{
      printf("Target out of bounds\n");
   }

}

#if defined __cplusplus
}
#endif
