#include <rk/matrix.h>
#include <gtest/gtest.h>

 
TEST(Mat4MultiplyTest, works) { 
    rkMat4 A = (rkMat4) {{
      { 0.1284f, 0.8589f, -0.4958f,  34.6600f},
      {-0.6090f, 0.4629f,  0.6441f, -54.3000f},
      { 0.7827f, 0.2193f,  0.5825f,   6.3450f}
    }};
    rkMat4 B = (rkMat4) {{
      { 0.7376, -0.6311, 0.2403,  -4.0900},
      { 0.2559,  0.5906, 0.7653, 100.8500},
      {-0.6249, -0.5029, 0.5971,   7.5800}
    }};
    rkMat4 C = rkMat4Multiply(A, B);
    ASSERT_NEAR(  0.6243f, C.data[0][0], 0.0001f);
    ASSERT_NEAR(  0.6756f, C.data[0][1], 0.0001f);
    ASSERT_NEAR(  0.3921f, C.data[0][2], 0.0001f);
    ASSERT_NEAR(116.9967f, C.data[0][3], 0.0001f);
    ASSERT_NEAR( -0.7332f, C.data[1][0], 0.0001f);
    ASSERT_NEAR(  0.3338f, C.data[1][1], 0.0001f);
    ASSERT_NEAR(  0.5925f, C.data[1][2], 0.0001f);
    ASSERT_NEAR( -0.2434f, C.data[1][3], 0.0001f);
    ASSERT_NEAR(  0.2694f, C.data[2][0], 0.0001f);
    ASSERT_NEAR( -0.6574f, C.data[2][1], 0.0001f);
    ASSERT_NEAR(  0.7037f, C.data[2][2], 0.0001f);
    ASSERT_NEAR( 29.6755f, C.data[2][3], 0.0001f);
}
