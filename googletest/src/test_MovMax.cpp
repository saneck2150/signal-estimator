#include <gtest/gtest.h>
#include "MovMax.hpp"

TEST(MovMaxTest, InitialValue) {
    
    signal_estimator::MovMax<double> movMax(3);

    EXPECT_DOUBLE_EQ(movMax.get(), 0.0);
}
