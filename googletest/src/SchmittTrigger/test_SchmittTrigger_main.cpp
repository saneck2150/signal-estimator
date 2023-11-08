// This is the main function that runs all tests related to SchmittTrigger.hpp
#include <gtest/gtest.h>
#include "test_SchmittTrigger.cpp"


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}