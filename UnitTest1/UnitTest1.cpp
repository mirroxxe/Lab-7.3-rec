#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include "../Lab №7.3 rec/Lab №7.3 rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestColSumFunction)
        {
            const int k = 3;
            int column[k] = { 1, -2, 3 };

            int result = colSum(column, k);

            Assert::AreEqual(2, result); 
        }
    };
}
