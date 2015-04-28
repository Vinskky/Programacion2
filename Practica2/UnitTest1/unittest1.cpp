#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\Practica2\Tree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TreeConstructor)
		{
			// TODO: Agregar aquí el código de la prueba
			Tree<int> a;

			Assert::IsTrue(a.IsEmpty());
		}

		TEST_METHOD(TreeAdd)
		{
			Tree<int> a;

			a.Add(3);
			a.Add(4);
			a.Add(6);
			a.Add(2);
			a.Add(3);

			Assert::IsFalse(a.IsEmpty());
			Assert::AreEqual(a.GetRoot()->data, 3);
			Assert::AreEqual(a.GetRoot()->data, 2);

		}

	};
}