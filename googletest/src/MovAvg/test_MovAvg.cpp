#include <gtest/gtest.h>
#include "MovAvg.hpp"


// Moving average calculation test.
TEST(MovAvgTest, MovingAverage) {
    
    signal_estimator::MovAvg<double> mov_avg(4);
    mov_avg.add(10.0);
    mov_avg.add(20.0);
    mov_avg.add(30.0);
    mov_avg.add(40.0);
    // Expected moving average for window 4: (10.0 + 20.0 + 30.0 + 40.0) / 4 = 25.0
    EXPECT_DOUBLE_EQ(mov_avg.get(), 25.0);
    
    mov_avg.add(50.0);
    // Expected moving average after adding 50.0: (20.0 + 30.0 + 40.0 + 50.0) / 4 = 35.0
    EXPECT_DOUBLE_EQ(mov_avg.get(), 35.0);
}


// The test initializes an object of the MovAvg class and checks that the object is not full.
TEST(MovAvgTest, Initialization) {
    signal_estimator::MovAvg<double> mov_avg(5);
    EXPECT_FALSE(mov_avg.is_full());
}


// Test for adding values and checking is_full().
TEST(MovAvgTest, AddAndIsFull) {

    signal_estimator::MovAvg<double> mov_avg(3);
    mov_avg.add(10.0);
    mov_avg.add(20.0);
    EXPECT_FALSE(mov_avg.is_full());  // The object IS NOT full after 2 additions.
    mov_avg.add(30.0);
    EXPECT_TRUE(mov_avg.is_full());  // The object IS full after 3 additions.
}


// Test for initialization of a MovAvg object with a window size equal to 0. The application is expected to exit with a return value 1.
TEST(MovAvgTest, InitializationWithZeroWindow) {
    signal_estimator::MovAvg<double> mov_avg(0);
    EXPECT_EXIT({ exit(1); }, ::testing::ExitedWithCode(1), ".*");
}
