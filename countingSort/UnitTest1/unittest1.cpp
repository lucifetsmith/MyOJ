#include "stdafx.h"
#include "CppUnitTest.h"
#include "countingSort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
#define ARR_LEN		10
			int arr[ARR_LEN] = {23, 34, 43, 3, 4, 6, 12, 32, 8, 6};
			const int res[ARR_LEN] = {3, 4, 6, 6, 8, 12, 23, 32, 34, 43};
			int tmpArr[ARR_LEN] = {0};
			countingSort(arr, tmpArr, ARR_LEN);
			for (int i = 0; i < ARR_LEN; i++) {
				Assert::AreEqual(res[i], tmpArr[i]);
			}
		}

	};
}