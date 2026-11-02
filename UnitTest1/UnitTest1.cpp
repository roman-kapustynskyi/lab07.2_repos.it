#include "pch.h"
#include "CppUnitTest.h"
#include"../PR07.2 it/FileName.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
                TEST_METHOD(TestMethod_FindMinInColumn)
                {
                    int k = 3;
                    int n = 4;

                    int** test_mat = new int* [k];
                    for (int i = 0; i < k; i++) {
                        test_mat[i] = new int[n];
                    }

                    test_mat[0][0] = 1; test_mat[0][1] = 5; test_mat[0][2] = 9; test_mat[0][3] = 4;
                    test_mat[1][0] = 4; test_mat[1][1] = 2; test_mat[1][2] = 6; test_mat[1][3] = 1;
                    test_mat[2][0] = 7; test_mat[2][1] = 8; test_mat[2][2] = 3; test_mat[2][3] = 0;

                    int min1 = FindMinInColumn(test_mat, k, 1);
                    Assert::AreEqual(2, min1);

                    int min3 = FindMinInColumn(test_mat, k, 3);
                    Assert::AreEqual(0, min3);

                    for (int i = 0; i < k; i++) delete[] test_mat[i];
                    delete[] test_mat;
                }

                TEST_METHOD(TestMethod_CalcSumMinEvenCols)
                {
                    int k = 3;
                    int n = 4;

                    int** test_mat = new int* [k];
                    for (int i = 0; i < k; i++) {
                        test_mat[i] = new int[n];
                    }

                    test_mat[0][0] = 1; test_mat[0][1] = 5; test_mat[0][2] = 9; test_mat[0][3] = 4;
                    test_mat[1][0] = 4; test_mat[1][1] = 2; test_mat[1][2] = 6; test_mat[1][3] = 1;
                    test_mat[2][0] = 7; test_mat[2][1] = 8; test_mat[2][2] = 3; test_mat[2][3] = 0;

                    int result = CalcSumMinEvenCols(test_mat, k, n);
                    Assert::AreEqual(2, result);

                    for (int i = 0; i < k; i++) delete[] test_mat[i];
                    delete[] test_mat;
                }
            };
        }