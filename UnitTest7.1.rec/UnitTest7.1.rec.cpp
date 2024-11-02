#include "pch.h"
#include "CppUnitTest.h"
#include "../LabAP7.1.rec/LabAP7.1.rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestExample
{
    TEST_CLASS(UnitTestExample)
    {
    public:

        TEST_METHOD(TestMethodCalcRecursive)
        {
            const int rowCount = 3;
            const int colCount = 3;
            int S = 0, k = 0;
            int** matrix = new int* [rowCount];

            // ��������� ������� �������
            for (int i = 0; i < rowCount; i++) {
                matrix[i] = new int[colCount];
            }

            // ���������� ������� ����������
            matrix[0][0] = 6;  matrix[0][1] = -3; matrix[0][2] = 4;
            matrix[1][0] = 11; matrix[1][1] = 0;  matrix[1][2] = 9;
            matrix[2][0] = 10; matrix[2][1] = 3;  matrix[2][2] = -2;

            // ��������� ���������� �������
            CalcRecursive(matrix, rowCount, colCount, S, k);

            // �������� ����������
            Assert::AreEqual(33, S); // ��������� ����: 6 + 4 + 11 + 9 + 3 = 33
            Assert::AreEqual(5, k);  // ��������� ������� ��������: 5

            // ��������� ���'��
            for (int i = 0; i < rowCount; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
        }
    };
}
