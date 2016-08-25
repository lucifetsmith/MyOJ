#include "stdafx.h"
#include "CppUnitTest.h"
#include "inssort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int arr[10] = {345, 21, 2346, 54, 56, 21, 35, 9875, -2135, 324};
			const int res[10] = {-2135, 21, 21, 35, 54, 56, 324, 345, 2346, 9875};
			int arrSize = sizeof(arr) / sizeof(arr[0]);
			inssort(arr, arrSize);
			for (int i = 0; i < arrSize; i++) {
				Assert::AreEqual(arr[i], res[i]);
			}
		}

	};
}