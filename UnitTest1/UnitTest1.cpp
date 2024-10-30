#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_8.2/Lab_8.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char str[] = "a*b+000000.1973-1.0100";
			FormatString(str);
			Assert::AreEqual("a*b+0.19-1.01", str);
		}
	};
}
