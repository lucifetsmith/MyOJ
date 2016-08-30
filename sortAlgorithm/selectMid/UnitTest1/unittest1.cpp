#include "stdafx.h"
#include "CppUnitTest.h"
#include "selectMid.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int arr[20];
			int i, tmp;
			for (i = 0; i < 20; i++) {
				arr[i] = i * 3;
			}
			for (i = 0; i < 20; i++) {
				if (i < 5) {
					tmp = arr[i + 2];
					arr[i + 2] = arr[5 - i];
					arr[5 - i] = tmp;
				}
				else {
					tmp = arr[i - 5];
					arr[i - 5] = arr[i];
					arr[i] = tmp;
				}
			}
			i = SelectMid(arr, 20, 9);
			Assert::AreEqual(i, 27);
		}

	};
}