#include <gtest/gtest.h>
#include "MovGradient.hpp"

// Testong an initial state
TEST(MovGradientTest, InitialState) {
    signal_estimator::MovGradient<double> movgrad;

    EXPECT_DOUBLE_EQ(movgrad.get(), 0);
}

//The test checks that the MovGradient object does not calculate a gradient when adding just one value.
TEST(MovGradientTest, AddSingleValue) {
    signal_estimator::MovGradient<double> movgrad;
    movgrad.add(5.0);

    EXPECT_DOUBLE_EQ(movgrad.get(), 0); // No gradient after adding one value.
}

//Check that the gradient is calculated correctly
TEST(MovGradientTest, CalculateGradient) {
    signal_estimator::MovGradient<double> movgrad;

    movgrad.add(3.0);
    movgrad.add(5.0);

    EXPECT_DOUBLE_EQ(movgrad.get(), 0);
}

//Test checks that movgrad only stores the last two values to calculate the gradient
TEST(MovGradientTest, AddMoreValuesThanNeeded) {
    signal_estimator::MovGradient<double> movgrad;

    movgrad.add(1.0);
    movgrad.add(3.0);
    movgrad.add(5.0);
    movgrad.add(8.0);

    EXPECT_DOUBLE_EQ(movgrad.get(), 2.5);
}
