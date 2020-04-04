#include <rk/vector.h>
#include <gtest/gtest.h>


TEST(Vec3NormalizeTest, works) {
    rkVec3 v = (rkVec3) {-43.764f, 30.401f, 17.664f};
    rkVec3 n = rkVec3Normalize(v);
    EXPECT_NEAR(-0.7796f, n.x, 0.0001f);
    EXPECT_NEAR( 0.5415f, n.y, 0.0001f);
    EXPECT_NEAR( 0.3147f, n.z, 0.0001f);
}

TEST(Vec3DotTest, works) {
    rkVec3 a = (rkVec3) {  4.567f, 7.536f, -10.230f};
    rkVec3 b = (rkVec3) {-12.090f, 8.446f,  -8.112f};
    EXPECT_NEAR(91.4198f, rkVec3Dot(a, b), 0.0001f);
}

TEST(Vec3CrossTest, works) {
    rkVec3 a = (rkVec3) {  4.567f, 7.536f, -10.230f};
    rkVec3 b = (rkVec3) {-12.090f, 8.446f,  -8.112f};
    rkVec3 c = rkVec3Cross(a, b);
    EXPECT_NEAR( 25.2705f, c.x, 0.0001f);
    EXPECT_NEAR(160.7282f, c.y, 0.0001f);
    EXPECT_NEAR(129.6831f, c.z, 0.0001f);
}
