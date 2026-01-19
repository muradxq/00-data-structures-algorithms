/**
 * Problem: Search a 2D Matrix
 * LeetCode #74
 * Difficulty: Medium
 * Pattern: Standard (treat as 1D)
 *
 * Search in row-wise and column-wise sorted matrix.
 *
 * Example:
 *   Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 *   Output: true
 */

#include <gtest/gtest.h>
#include <vector>

using namespace std;

// ============================================================================
// TODO: Implement your solution here
// ============================================================================
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // Your implementation here
    // Key: Treat as 1D sorted array
    
    return false;
}

// ============================================================================
// Tests - DO NOT MODIFY
// ============================================================================
TEST(Search2DMatrix, Example1) {
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    EXPECT_TRUE(searchMatrix(matrix, 3));
}

TEST(Search2DMatrix, Example2) {
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    EXPECT_FALSE(searchMatrix(matrix, 13));
}

TEST(Search2DMatrix, SingleElement) {
    vector<vector<int>> matrix = {{1}};
    EXPECT_TRUE(searchMatrix(matrix, 1));
}

TEST(Search2DMatrix, FirstElement) {
    vector<vector<int>> matrix = {{1,3,5},{10,11,16},{23,30,34}};
    EXPECT_TRUE(searchMatrix(matrix, 1));
}

TEST(Search2DMatrix, LastElement) {
    vector<vector<int>> matrix = {{1,3,5},{10,11,16},{23,30,34}};
    EXPECT_TRUE(searchMatrix(matrix, 34));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
