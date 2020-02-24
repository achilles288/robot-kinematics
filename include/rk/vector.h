#ifndef __RK_MATH_VECTOR_H__
#define __RK_MATH_VECTOR_H__

#if defined __cplusplus
extern "C" {
#endif


typedef struct _rkVec2 rkVec2;
typedef struct _rkVec3 rkVec3;


struct _rkVec2 {
    float x;
    float y;
};

float rkVec2Normalize(rkVec2 v);
float rkVec2Dot(rkVec2 a, rkVec2 b);
float rkVec2Cross(rkVec2 a, rkVec2 b);


struct _rkVec3 {
    float x;
    float y;
    float z;
};

typedef rkVec3 rkEuler;

float rkVec3Normalize(rkVec3 v);
float rkVec3Dot(rkVec3 a, rkVec3 b);
rkVec3 rkVec3Cross(rkVec3 a, rkVec3 b);


#if defined __cplusplus
}
#endif

#endif
