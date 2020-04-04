#include <rk/matrix.h>
#include <gtest/gtest.h>

 
TEST(Mat3TransformTest, works) { 
    rkMat3 M = rkMat3Transform({24.24f, -7.83f}, 0.64f);
    ASSERT_NEAR( 0.8021f, M.data[0][0], 0.0001f);
    ASSERT_NEAR(-0.5972f, M.data[0][1], 0.0001f);
    ASSERT_NEAR(24.2400f, M.data[0][2], 0.0001f);
    ASSERT_NEAR( 0.5972f, M.data[1][0], 0.0001f);
    ASSERT_NEAR( 0.8021f, M.data[1][1], 0.0001f);
    ASSERT_NEAR(-7.8300f, M.data[1][2], 0.0001f);
}
