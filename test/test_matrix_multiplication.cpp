#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// ######################### Source code of multiplyMatrices in src/matrix_mult


//Test Case 1: This is normal case of  Non-square matrix multiplication
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

//Test Case 3: Single Element (Also Kind Of Square Matrix) Multiplication
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

//Test Case 4: With Matrix which has negative-value elements
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

//Test Case 5: With Matrix which has zero-value elements. 
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

// Test Case 6: With Matrix which has very large-value elements.
TEST(MatrixMultiplicationTest, TestVeryLargeElements) {
    std::vector<std::vector<int>> A = {
        {1000, 2000},
        {3000, 4000}
    };
    std::vector<std::vector<int>> B = {
        {5000, 6000},
        {7000, 8000}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 2, 2);

    std::vector<std::vector<int>> expected = {
        {19000000, 22000000},
        {43000000, 50000000}
    };

    EXPECT_EQ(C, expected) << "Matrix multiplication test case6 failed! :(((()";
}

// Test Case 7: With identity matrix (A*I=A).
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

    EXPECT_EQ(C, expected) << "Matrix multiplication test case7 failed! :(((()";
}

//Test Case 8: With Column Matrix Or Row Matrix. 
TEST(MatrixMultiplicationTest, TestMatrixWithColumnOrRowMatrix) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3}
    };
    std::vector<std::vector<int>> B = {
        {4},
        {5},
        {6}
    };
    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 1, 3, 1);

    std::vector<std::vector<int>> expected = {
        {32}
    };

    EXPECT_EQ(C, expected) << "Matrix multiplication test case8 failed! :(((()";
}                     

//Test Case 9: Matrix with very large size (1000x1000)
TEST(MatrixMultiplicationTest, TestMatrixWithLargeSize) {
    std::vector<std::vector<int>> A(1000, std::vector<int>(1000, 0));
    std::vector<std::vector<int>> B(1000, std::vector<int>(1000, 0));
    std::vector<std::vector<int>> C(1000, std::vector<int>(1000, 0));

    multiplyMatrices(A, B, C, 1000, 1000, 1000);

    std::vector<std::vector<int>> expected(1000, std::vector<int>(1000, 0));

    EXPECT_EQ(C, expected) << "Matrix multiplication test case9 failed! :(((()";
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
