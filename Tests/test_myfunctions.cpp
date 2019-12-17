#include <gtest/gtest.h>
#include "MyFunctions.h"

class MyFunctionsTest : public ::testing::Test {
    protected:
        MyQuaternion Q {0, 1, 0, 0};
        MyQuaternion X {2, 0, 0, 0};

        MyQuaternion XrotatedByQ {-2, 0, 0, 0}
};

TEST_F(MyFunctionsTest, Sample) {
    EXPECT_EQ(Q*X*Q.conj(), XrotatedByQ);
}