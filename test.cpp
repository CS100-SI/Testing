#include "Arithmetic.h"
#include "LinkedList.h"

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

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}