#include "stdafx.h"
#include "CppUnitTest.h"
#include "bucketSort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int arr[10] = {132, 3451, 1436, 12454, 3, 3, 32465, 5787, 0, -12};
			const int res[10] = {-12, 0, 3, 3, 132, 1436, 3451, 5787, 12454, 32465};
			BucketSort(arr, 10);
			for (int i = 0; i < 10; i++) {
				Assert::AreEqual(arr[i], res[i]);
			}
		}

	};
}