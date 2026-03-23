#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include <thread>
#include <mutex>
#include "../include/thread_utils.h"

std::mutex mtx;

#define LOCK_MUTEX() std::lock_guard<std::mutex> lock(mtx)

void printRange(int start, int end) 
{
    LOCK_MUTEX();
    for (int i = start; i <= end; ++i)
    {
        std::cout << i << "\n";
    }
}

// Test 1: Verify printRange with positive numbers
TEST(ThreadTest, PrintRangePositive) {
    testing::internal::CaptureStdout();
    printRange(1, 5);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_NE(output.find("1"), std::string::npos);
    EXPECT_NE(output.find("5"), std::string::npos);
}

// Test 2: Verify correct number of outputs
TEST(ThreadTest, PrintRangeCount) {
    testing::internal::CaptureStdout();
    printRange(1, 3);
    std::string output = testing::internal::GetCapturedStdout();
    
    int newlines = std::count(output.begin(), output.end(), '\n');
    EXPECT_EQ(newlines, 3);
}

// Test 3: Verify single number range
TEST(ThreadTest, PrintRangeSingle) {
    testing::internal::CaptureStdout();
    printRange(5, 5);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_EQ(output, "5\n");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
