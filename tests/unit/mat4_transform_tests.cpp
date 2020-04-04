#include <rk/matrix.h>
#include <gtest/gtest.h>


TEST(Mat4TransformTest, normal) { 
    rkVec3 T = (rkVec3) {-9.31f, 10.572f, 4.2f};
    rkEuler R = (rkEuler) {0.312f, -0.443f, 0.856f};
    rkMat4 M = rkMat4Transform(T, R);
    ASSERT_NEAR( 0.5922f, M.data[0][0], 0.0001f);
    ASSERT_NEAR(-0.8050f, M.data[0][1], 0.0001f);
    ASSERT_NEAR(-0.0356f, M.data[0][2], 0.0001f);
    ASSERT_NEAR(-9.3100f, M.data[0][3], 0.0001f);
    ASSERT_NEAR( 0.6823f, M.data[1][0], 0.0001f);
    ASSERT_NEAR( 0.5244f, M.data[1][1], 0.0001f);
    ASSERT_NEAR(-0.5093f, M.data[1][2], 0.0001f);
    ASSERT_NEAR(10.5720f, M.data[1][3], 0.0001f);
    ASSERT_NEAR( 0.4287f, M.data[2][0], 0.0001f);
    ASSERT_NEAR( 0.2773f, M.data[2][1], 0.0001f);
    ASSERT_NEAR( 0.8599f, M.data[2][2], 0.0001f);
    ASSERT_NEAR( 4.2000f, M.data[2][3], 0.0001f);
}

TEST(Mat4TransformTest, pitchPos90) { 
    rkVec3 T = (rkVec3) {21.053f, -0.945f, -5.46f};
    rkEuler R = (rkEuler) {-1.028f, M_PI/2, 0.335f};
    rkMat4 M = rkMat4Transform(T, R);
    ASSERT_NEAR( 0.0000f, M.data[0][0], 0.0001f);
    ASSERT_NEAR(-0.9785f, M.data[0][1], 0.0001f);
    ASSERT_NEAR( 0.2063f, M.data[0][2], 0.0001f);
    ASSERT_NEAR(21.0530f, M.data[0][3], 0.0001f);
    ASSERT_NEAR( 0.0000f, M.data[1][0], 0.0001f);
    ASSERT_NEAR( 0.2063f, M.data[1][1], 0.0001f);
    ASSERT_NEAR( 0.9785f, M.data[1][2], 0.0001f);
    ASSERT_NEAR(-0.9450f, M.data[1][3], 0.0001f);
    ASSERT_NEAR(-1.0000f, M.data[2][0], 0.0001f);
    ASSERT_NEAR( 0.0000f, M.data[2][1], 0.0001f);
    ASSERT_NEAR( 0.0000f, M.data[2][2], 0.0001f);
    ASSERT_NEAR(-5.4600f, M.data[2][3], 0.0001f);
}
