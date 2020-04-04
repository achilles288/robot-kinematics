#include <rk/matrix.h>
#include <gtest/gtest.h>

 
TEST(Mat3MultiplyTest, works) { 
    rkMat3 A = (rkMat3) {{
      { 0.56f, -0.78f,  11.00f},
      { 0.78f,  0.56f,  21.50f}
    }};
    rkMat3 B = (rkMat3) {{
      {-0.46f, -0.20f, -14.34f},
      { 0.20f, -0.46f,   5.70f}
    }};
    rkMat3 C = rkMat3Multiply(A, B);
    ASSERT_NEAR(-0.4136f, C.data[0][0], 0.0001f);
    ASSERT_NEAR( 0.2468f, C.data[0][1], 0.0001f);
    ASSERT_NEAR(-1.4764f, C.data[0][2], 0.0001f);
    ASSERT_NEAR(-0.2468f, C.data[1][0], 0.0001f);
    ASSERT_NEAR(-0.4136f, C.data[1][1], 0.0001f);
    ASSERT_NEAR(13.5068f, C.data[1][2], 0.0001f);
}
