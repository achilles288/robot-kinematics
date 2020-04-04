#include <rk/vector.h>
#include <gtest/gtest.h>


TEST(Vec2NormalizeTest, works) {
    rkVec2 v = (rkVec2) {18.7618f, -24.5395f};
    rkVec2 n = rkVec2Normalize(v);
    EXPECT_NEAR( 0.6074f, n.x, 0.0001f);
    EXPECT_NEAR(-0.7944f, n.y, 0.0001f);
}

TEST(Vec2DotTest, works) {
    rkVec2 a = (rkVec2) {15.774f,  6.092f};
    rkVec2 b = (rkVec2) { 8.081f, -9.442f};
    EXPECT_NEAR(69.949f, rkVec2Dot(a, b), 0.0001f);
}

TEST(Vec2CrossTest, works) {
    rkVec2 a = (rkVec2) {15.774f,  6.092f};
    rkVec2 b = (rkVec2) { 8.081f, -9.442f};
    EXPECT_NEAR(-198.1676f, rkVec2Cross(a, b), 0.0001f);
}
