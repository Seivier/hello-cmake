#include <gtest/gtest.h>
#include "ball.h"

TEST(Ball, Constructor)
{
    cc7515::Ball ball({0, 0}, 1, 1);
    EXPECT_EQ(ball.getPosition().x, 0);
    EXPECT_EQ(ball.getPosition().y, 0);
    EXPECT_EQ(ball.getRadius(), 1);
    EXPECT_EQ(ball.getMass(), 1);
}

TEST(Ball, Update)
{
    cc7515::Ball ball({0, 0}, 1, 1);
    ball += {1, 1};
    ball.update(1);
    EXPECT_EQ(ball.getPosition().x, 1);
    EXPECT_EQ(ball.getPosition().y, 1);
}
