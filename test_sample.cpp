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
    EXPECT_EQ(list.Pop(), 4);
    EXPECT_EQ(list.GetList(), "5\n");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}