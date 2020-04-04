#include <rk/matrix.h>
#include <gtest/gtest.h>


TEST(Mat4GetRotationTest, normal) {
    rkMat4 M = (rkMat4) {{
      {0.5922f, -0.8050f, -0.0356f, -9.3100f},
      {0.6823f,  0.5244f, -0.5093f, 10.5720f},
      {0.4287f,  0.2773f,  0.8599f,  4.2000f}
    }};
    rkEuler R = rkMat4GetRotation(M);
    EXPECT_NEAR( 0.312f, R.x, 0.001f);
    EXPECT_NEAR(-0.443f, R.y, 0.001f);
    EXPECT_NEAR( 0.856f, R.z, 0.001f);
}

TEST(Mat4GetRotationTest, pitchPos90) {
    rkMat4 M = (rkMat4) {{
      { 0.0000f, -0.9785f,  0.2063f, 21.0530f},
      { 0.0000f,  0.2063f,  0.9785f, -0.9450f},
      {-1.0000f,  0.0000f,  0.0000f, -5.4600f}
    }};
    rkEuler R = rkMat4GetRotation(M);
    EXPECT_NEAR(0.000f, R.x, 0.001f);
    EXPECT_NEAR(M_PI/2, R.y, 0.001f);
    EXPECT_NEAR(1.363f, R.z, 0.001f);
}

TEST(Mat4GetRotationTest, pitchNeg90) {
    rkMat4 M = (rkMat4) {{
      {0.0000f, -0.9014f, -0.4330f,   7.1660f},
      {0.0000f,  0.4330f, -0.9014f, -18.6450f},
      {1.0000f,  0.0000f,  0.0000f, -42.7103f}
    }};
    rkEuler R = rkMat4GetRotation(M);
    EXPECT_NEAR( 0.000f, R.x, 0.001f);
    EXPECT_NEAR(-M_PI/2, R.y, 0.001f);
    EXPECT_NEAR( 1.123f, R.z, 0.001f);
}

TEST(Mat4GetTranslationTest, works) {
    rkMat4 M = (rkMat4) {{
      {0.5922f, -0.8050f, -0.0356f, -9.3100f},
      {0.6823f,  0.5244f, -0.5093f, 10.5720f},
      {0.4287f,  0.2773f,  0.8599f,  4.2000f}
    }};
    rkVec3 v = rkMat4GetTranslation(M);
    EXPECT_FLOAT_EQ(-9.3100f, v.x);
    EXPECT_FLOAT_EQ(10.5720f, v.y);
    EXPECT_FLOAT_EQ( 4.2000f, v.z);
}
