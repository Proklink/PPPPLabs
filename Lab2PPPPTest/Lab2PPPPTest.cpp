#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab2PPPP/Lab2PPPP.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab2PPPPTest
{
	TEST_CLASS(Lab2PPPPTest)
	{
	public:
		
		TEST_METHOD(TestMethod5)
		{
			int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
			struct Solution sol = input_handler(a, b, c, d, e, f);

			Assert::AreEqual(sol.ans, '5');
			Assert::IsNull(sol.x);
			Assert::IsNull(sol.y);
		}

		TEST_METHOD(TestMethod2)
		{
			int a = 1, b = 2, c = 1, d = 1, e = 1, f = 1;
			struct Solution sol = input_handler(a, b, c, d, e, f);

			Assert::AreEqual(sol.ans, '2');
			Assert::AreEqual(*sol.x, (double)1);
			Assert::AreEqual(*sol.y, (double)0);
		}

		TEST_METHOD(TestMethod0)
		{
	
			int a = 0, b = 1, c = 0, d = 1, e = 1, f = 2;
			struct Solution sol = input_handler(a, b, c, d, e, f);

			Assert::AreEqual(sol.ans, '0');
			Assert::IsNull(sol.x);
			Assert::IsNull(sol.y);
		}

		TEST_METHOD(TestMethod4_1)
		{

			int a = 0, b = 0, c = 0, d = 1, e = 0, f = 1;
			struct Solution sol = input_handler(a, b, c, d, e, f);

			Assert::AreEqual(sol.ans, '4');
			Assert::IsNull(sol.x);
			Assert::AreEqual(*sol.y, (double)1);
		}

		TEST_METHOD(TestMethod3_1)
		{

			int a = 1, b = 0, c = 0, d = 0, e = 1, f = 0;
			struct Solution sol = input_handler(a, b, c, d, e, f);

			Assert::AreEqual(sol.ans, '3');
			Assert::IsNull(sol.y);
			Assert::AreEqual(*sol.x, (double)1);
		}

		TEST_METHOD(TestMethod4_2)
		{

			int a = 0, b = 1, c = 0, d = 1, e = 1, f = 1;
			struct Solution sol = input_handler(a, b, c, d, e, f);

			Assert::AreEqual(sol.ans, '4');
			Assert::IsNull(sol.x);
			Assert::AreEqual(*sol.y, (double)1);
		}

		TEST_METHOD(TestMethod3_2)
		{

			int a = 1, b = 0, c = 1, d = 0, e = 1, f = 1;
			struct Solution sol = input_handler(a, b, c, d, e, f);

			Assert::AreEqual(sol.ans, '3');
			Assert::IsNull(sol.y);
			Assert::AreEqual(*sol.x, (double)1);
		}

		TEST_METHOD(TestMethod1_1)
		{

			int a = 0, b = 0, c = 1, d = 1, e = 0, f = 1;
			struct Solution sol = input_handler(a, b, c, d, e, f);

			Assert::AreEqual(sol.ans, '1');
			Assert::AreEqual(*sol.x, (double)-1);
			Assert::AreEqual(*sol.y, (double)1);
		}

		TEST_METHOD(TestMethod1_2)
		{

			int a = 1, b = 1, c = 0, d = 0, e = 1, f = 0;
			struct Solution sol = input_handler(a, b, c, d, e, f);

			Assert::AreEqual(sol.ans, '1');
			Assert::AreEqual(*sol.x, (double)-1);
			Assert::AreEqual(*sol.y, (double)1);
		}

		TEST_METHOD(TestMethod1_3)
		{

			int a = 0, b = 45, c = 45, d = 45, e = 0, f = 0;
			struct Solution sol = input_handler(a, b, c, d, e, f);

			Assert::AreEqual(sol.ans, '1');
			Assert::AreEqual(*sol.x, (double)-1);
			Assert::AreEqual(*sol.y, (double)0);
		}

		TEST_METHOD(TestMethod1_4)
		{

			int a = 45, b = 2, c = 0, d = 45, e = 0, f = 0;
			struct Solution sol = input_handler(a, b, c, d, e, f);

			Assert::AreEqual(sol.ans, '1');
			Assert::AreEqual(*sol.x, (double)-b/(double)a);
			Assert::AreEqual(*sol.y, (double)0);
		}

		TEST_METHOD(TestMethod1_5)
		{

			int a = 1, b = 1, c = 1, d = 1, e = 1, f = 1;
			struct Solution sol = input_handler(a, b, c, d, e, f);

			Assert::AreEqual(sol.ans, '1');
			Assert::AreEqual(*sol.x, (double)-1);
			Assert::AreEqual(*sol.y, (double)1);
		}
	};
}
