#include "MyQuaternion.h"
#include <gtest/gtest.h>

class QuaternionTest : public ::testing::Test {

protected:
    MyQuaternion A {1, 1, 1, 1};
    MyQuaternion B {1, 2, 3, 4};

    MyQuaternion AplusB {2, 3, 4, 5};
    MyQuaternion AtimesB {4, 8, 6, -2};
    MyQuaternion Ascale2 {2, 2, 2, 2};
    MyQuaternion Aconj {-1, -1, -1, 1};
    MyQuaternion AminusB {0, -1, -2, -3};
};

TEST_F(QuaternionTest, BoundsChecking) {
    EXPECT_ANY_THROW(A[5]);
}

TEST_F(QuaternionTest, CorrectAddition) {
    MyQuaternion C = A + B;
    EXPECT_EQ(C, AplusB);
}

TEST_F(QuaternionTest, CorrectSubstraction) {
    MyQuaternion C = A - B;
    EXPECT_EQ(C, AminusB);
}

TEST_F(QuaternionTest, CorrectMultiplication) {
    MyQuaternion C = A*B;
    EXPECT_EQ(C, AtimesB);
}

TEST_F(QuaternionTest, CorrectConj) {
    MyQuaternion C = A.conj();
    EXPECT_EQ(C, Aconj);
}

TEST_F(QuaternionTest, CorrectScale) {
    MyQuaternion C = A*2;
    EXPECT_EQ(C, Ascale2);
}

TEST_F(QuaternionTest, CorrectAssignment) {
    MyQuaternion C = A;
    EXPECT_EQ(C, A);
}

TEST_F(QuaternionTest, AssignmentOperatorInfiniteLoopFix) {
    MyQuaternion C;
    C = A + A.conj();
    SUCCEED();
}

TEST_F(QuaternionTest, Aufgabe2Test) {
    MyQuaternion X = {2, 0, 0, 0}; 
    MyQuaternion Q = {0, 1, 0, 0};
    MyQuaternion solution = {-2, 0, 0, 0};

}