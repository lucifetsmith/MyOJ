#include "stdafx.h"
#include "CppUnitTest.h"
#include "radixSort.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			unsigned arr[10] = { 234, 456, 4512, 124123, 4572341, 12354, 2135765, 234, 785673, 3475326 };
			const unsigned res[10] = { 234, 234, 456, 4512, 12354, 124123, 785673, 2135765, 3475326, 4572341 };
			RadixSort(arr, 10);
			for (int i = 0; i < 10; i++) {
				Assert::AreEqual(arr[i], res[i]);
			}
		}

	};
}