#include "ArithmeticSol.h"
#include "LinkedListSol.h"

#include "gtest/gtest.h"

// Sample Test
TEST(LinkedList, LinkedListSample) {
    LinkedList list;
    list.Append(4);
    EXPECT_EQ(list.GetList(), "4\n");
    list.Append(5);
    EXPECT_EQ(list.GetList(), "4\n5\n");
}

// Place ALL your tests below here

// Arithmetic.h
TEST(Arithmetic, AddPos) {
    EXPECT_EQ(Add(3, 5), 8);
}
TEST(Arithmetic, AddNeg) {
    EXPECT_EQ(Add(3, -5), -2);
}
TEST(Arithmetic, SubPos) {
    EXPECT_EQ(Sub(10, 3), 7);
}
TEST(Arithmetic, SubNeg) {
    EXPECT_EQ(Sub(5, -3), 8);
}
TEST(Arithmetic, MultPos) {
    EXPECT_EQ(Mult(5.5, 3), 16.5);
}
TEST(Arithmetic, MultNeg) {
    EXPECT_EQ(Mult(-5, 3), -15);
}
TEST(Arithmetic, MultNegZero) {
    EXPECT_EQ(Mult(-10, 0), 0);
}
TEST(Arithmetic, DivPos) {
    EXPECT_EQ(Div(25, 4), 6.25);
}
TEST(Arithmetic, DivLessOne) {
    EXPECT_EQ(Div(3, 5), 0.6);
}
TEST(Arithmetic, DivZeroByPos) {
    EXPECT_EQ(Mult(0, -2), 0);
}

// LinkedList.h
TEST(LinkedList, EmptyList) {
    LinkedList list;
    EXPECT_EQ(list.GetList(), "Empty\n");
}
TEST(LinkedList, DeleteEmpty) {
    LinkedList list;
    EXPECT_EQ(list.Pop(), -1);
}
TEST(LinkedList, NormalList) {
    LinkedList list;
    EXPECT_EQ(list.GetList(), "Empty\n");
    list.Append(4);
    EXPECT_EQ(list.GetList(), "4\n");
    list.Append(5);
    EXPECT_EQ(list.GetList(), "4\n5\n");
}
TEST(LinkedList, PopNormalList) {
    LinkedList list;
    EXPECT_EQ(list.GetList(), "Empty\n");
    list.Append(4);
    EXPECT_EQ(list.GetList(), "4\n");
    list.Append(5);
    EXPECT_EQ(list.GetList(), "4\n5\n");
    EXPECT_EQ(list.Pop(), 4);
    EXPECT_EQ(list.GetList(), "5\n");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}