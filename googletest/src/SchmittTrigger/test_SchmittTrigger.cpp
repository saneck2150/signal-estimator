#include <gtest/gtest.h>
#include "SchmittTrigger.hpp"

//Verifying that Schmitt Trigger is correctly tracked when adding values
TEST(SchmittTriggerTest, Triggering) {
    signal_estimator::SchmittTrigger<double> schmitt_trigger(0.9);

    EXPECT_FALSE(schmitt_trigger(0.0001));
    EXPECT_FALSE(schmitt_trigger(0.9));
    EXPECT_TRUE(schmitt_trigger(1000000));
}

