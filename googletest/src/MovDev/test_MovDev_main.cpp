// This is the main function that runs all tests related to MovDev.hpp

#include <gtest/gtest.h>
#include "test_MovDev.cpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}