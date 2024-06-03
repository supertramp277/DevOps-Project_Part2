#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// ######################### Source code of multiplyMatrices in src/matrix_mult


//Test Case 1: This is normal case of matrix multiplication
TEST(MatrixMultiplicationTest, TestMultiplyMatrices) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };
    std::vector<std::vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {58, 64},
        {139, 154}
    };

    EXPECT_EQ(C, expected) << "Matrix multiplication test case1 failed! :(((()";
}


//Test Case 2: Empty(Null Element) Matrices
TEST(MatrixMultiplicationTest, TestEmptyMatrices) {
    std::vector<std::vector<int>> A;
    std::vector<std::vector<int>> B;
    std::vector<std::vector<int>> C;

    multiplyMatrices(A, B, C, 0, 0, 0);

    std::vector<std::vector<int>> expected;
    EXPECT_EQ(C, expected) << "Matrix multiplication test case2 failed! :(((()";
}

//Test Case 3: Single Element Matrix
TEST(MatrixMultiplicationTest, TestSingleElementMatrix) {
    std::vector<std::vector<int>> A = {
        {3}
    };
    std::vector<std::vector<int>> B = {
        {5}
    };
    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 1, 1, 1);

    std::vector<std::vector<int>> expected = {
        {15}
    };

    EXPECT_EQ(C, expected) << "Matrix multiplication test case3 failed! :(((()";
}

//Test Case 4: Matrix with negative elements
TEST(MatrixMultiplicationTest, TestMatrixWithNegativeNumbers) {
    std::vector<std::vector<int>> A = {
        {1, -2, 3},
        {4, 5, -6}
    };
    std::vector<std::vector<int>> B = {
        {1, -2},
        {3, 4},
        {5, -6}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {  
        {10, -28},            
        {-11, 48}
    };

    EXPECT_EQ(C, expected) << "Matrix multiplication test case4 failed! :(((()";
}

//Test Case 5: With Matrix which is comprised of zero-value elements.
TEST(MatrixMultiplicationTest, TestMatrixWithZeroMatrix) {    
    std::vector<std::vector<int>> A = {
        {1, 2, 3},            
        {4, 5, 6},
        {7, 8, 9}        
    };                        
    std::vector<std::vector<int>> B = {
        {0, 0, 0},            
        {0, 0, 0},                        
        {0, 0, 0}                
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 3, 3);

    std::vector<std::vector<int>> expected = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    EXPECT_EQ(C, expected) << "Matrix multiplication test case5 failed! :(((()";
}  

// Test Case 6: With identity matrix.
TEST(MatrixMultiplicationTest, TestMatrixWithIdentityMatrix) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6},            
        {7, 8, 9}
    };                        
    std::vector<std::vector<int>> B = {            
        {1, 0, 0},                        
        {0, 1, 0},                        
        {0, 0, 1}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));

    multiplyMatrices(A, B, C, 3, 3, 3);

    std::vector<std::vector<int>> expected = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    EXPECT_EQ(C, expected) << "Matrix multiplication test case6 failed! :(((()";
}

//Test Case 7: Matrix with large size
TEST(MatrixMultiplicationTest, TestMatrixWithLargeSize) {
    std::vector<std::vector<int>> A(1000, std::vector<int>(1000, 0));
    std::vector<std::vector<int>> B(1000, std::vector<int>(1000, 0));
    std::vector<std::vector<int>> C(1000, std::vector<int>(1000, 0));

    multiplyMatrices(A, B, C, 1000, 1000, 1000);

    std::vector<std::vector<int>> expected(1000, std::vector<int>(1000, 0));

    EXPECT_EQ(C, expected) << "Matrix multiplication test case7 failed! :(((()";
}

//Test Case 8: Incompatible matrix sizes (Not conforming with definition, should throw exception!) 
/*TEST(MatrixMultiplicationTest, TestIncompatibleMatrixSizes) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };
    std::vector<std::vector<int>> B = {
        {7, 8, 9},
        {10, 11, 12}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(3, 0));

    EXPECT_THROW(multiplyMatrices(A, B, C, 2, 3, 3), std::invalid_argument);
}*/

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
