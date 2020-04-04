#include <rk/matrix.h>
#include <gtest/gtest.h>


static rkMat3 M = (rkMat3) {{
  {0.9407f, -0.3391f, 23.005f},
  {0.3391f,  0.9407f, 17.340f}
}};


TEST(Mat3GetTranslationTest, works) {
    rkVec2 v = rkMat3GetTranslation(M);
    EXPECT_FLOAT_EQ(23.005f, v.x);
    EXPECT_FLOAT_EQ(17.340f, v.y);
}

TEST(Mat3GetRotationTest, works) {
    EXPECT_NEAR(0.346f, rkMat3GetRotation(M), 0.001f);
}
