#include "stdafx.h"
#include "CppUnitTest.h"
#include "qsort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int arr[10] = {1, 34, 346, 23, 54, 34, 879, 678, 2, 3235};
			const int res[10] = {1, 2, 23, 34, 34, 54, 346, 678, 879, 3235};
			qsort(arr, 0, 9);
			for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
				Assert::AreEqual(arr[i], res[i]);
			}
		}

	};
}