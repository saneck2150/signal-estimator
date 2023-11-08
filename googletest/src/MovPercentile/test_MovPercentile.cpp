#include <gtest/gtest.h>
#include "MovPercentile.hpp"

//Test checks that the calculated percentile matches the expected value
TEST(MovPercentileTest, CalculatePercentile) {
    const size_t window_sz = 5;
    const double percentile = 0.5;

    signal_estimator::MovPercentile<double> movpercentile(window_sz, percentile);

    movpercentile.add(1.0);
    movpercentile.add(2.0);
    movpercentile.add(3.0);
    movpercentile.add(4.0);
    movpercentile.add(5.0);

    EXPECT_DOUBLE_EQ(movpercentile.get(), 3.0);
}

//Test checks how the class handles duplicate values
TEST(MovPercentileTest, CalculatePercentileWithRepetitions) {
    const size_t window_sz = 5;
    const double percentile = 0.75;

    signal_estimator::MovPercentile<double> movpercentile(window_sz, percentile);

    movpercentile.add(1.0);
    movpercentile.add(2.0);
    movpercentile.add(3.0);
    movpercentile.add(2.0); 
    movpercentile.add(4.0);


    EXPECT_DOUBLE_EQ(movpercentile.get(), 3.0);
}

//Tests the behavior of a class with a small window
TEST(MovPercentileTest, SmallWindowSize) {
    const size_t window_sz = 2;
    const double percentile = 0.5;

    signal_estimator::MovPercentile<double> movpercentile(window_sz, percentile);

    movpercentile.add(3.0);
    EXPECT_DOUBLE_EQ(movpercentile.get(), 3);
}

//Tests the behavior of a class with a large window
TEST(MovPercentileTest, LargeWindowSize) {
    const size_t window_sz = 10;
    const double percentile = 0.5;

    signal_estimator::MovPercentile<double> movpercentile(window_sz, percentile);

    movpercentile.add(1.0);
    movpercentile.add(2.0);
    movpercentile.add(3.0);

    EXPECT_DOUBLE_EQ(movpercentile.get(), 2);
}

//The test verifies that the class correctly calculates the different percentiles
TEST(MovPercentileTest, DifferentPercentiles) {
    const size_t window_sz = 5;

    signal_estimator::MovPercentile<double> movpercentile25(window_sz, 0.25);
    signal_estimator::MovPercentile<double> movpercentile75(window_sz, 0.75);

    movpercentile25.add(1.0);
    movpercentile25.add(2.0);
    movpercentile25.add(3.0);
    movpercentile25.add(4.0);
    movpercentile25.add(5.0);

    movpercentile75.add(1.0);
    movpercentile75.add(2.0);
    movpercentile75.add(3.0);
    movpercentile75.add(4.0);
    movpercentile75.add(5.0);

    EXPECT_DOUBLE_EQ(movpercentile25.get(), 2.0);
    EXPECT_DOUBLE_EQ(movpercentile75.get(), 4.0);
}