#include <gtest/gtest.h>
#include "MyFunctions.h"
#include "quarternion_functions.h"

class Aufgabe3Test : public ::testing::Test {
    protected:
        MyQuaternion Q {0, 1, 0, 0};
        double Q_angle = 180;

        MyQuaternion A {4, 3, 2, 1};
        MyQuaternion A_sorted {1, 2, 3, 4};
};

TEST_F(Aufgabe3Test, GetThetaCorrect) {
    EXPECT_DOUBLE_EQ(get_theta(Q), 180);
}

TEST_F(Aufgabe3Test, SortingCorrect) {
    EXPECT_EQ(A.sortAscending(), A_sorted);
}