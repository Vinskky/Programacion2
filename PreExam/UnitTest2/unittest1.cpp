#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\PreExam\String.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			String chain("Hola");
			String chain2("  Hola");
			String chain3("  Hola  ");

			
			chain2.Trim();
			chain3.Trim();

			Assert::AreEqual(chain.Trim(), 0);
			Assert::AreEqual(chain.Trim(), 2);
			Assert::AreEqual(chain.Trim(), 4);
		}

	};
}