#include "stdafx.h"
#include "CppUnitTest.h"
#include "heapSort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int arr[10] = { 235, 23462, 4564, 43, 43, 467, 43, -0x7fffffff, 0, 4564 };
			const int res[10] = { 23462, 4564, 4564, 467, 235, 43, 43, 43, 0, -0x7fffffff };
			//heapSort(arr, 10);
			HeapSort(arr, 10);
			for (int i = 0; i < 10; i++) {
				Assert::AreEqual(arr[i], res[i]);
			}
		}
	};
}