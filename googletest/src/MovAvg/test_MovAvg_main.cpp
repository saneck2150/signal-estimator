// This is the main function that runs all tests related to MovAvg.hpp

#include <gtest/gtest.h>
#include "test_MovAvg.cpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}