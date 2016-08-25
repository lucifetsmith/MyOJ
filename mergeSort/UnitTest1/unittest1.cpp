#include "stdafx.h"
#include "CppUnitTest.h"
#include "mergeSort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int arr[10] = {3246, 236, 68, -1245, 0, 32, 32, 236, 32, 573657};
			const int res[10] = { -1245, 0, 32, 32, 32, 68, 236, 236, 3246, 573657 };
			const int arrSize = 10;
			int* buf = nullptr;
			mergeSort(arr, 0, 9, &buf);
			Assert::IsNotNull(buf);
			free(buf);
			for (int i = 0; i < arrSize; i++) {
				Assert::AreEqual(arr[i], res[i]);
			}
		}

	};
}