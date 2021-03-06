#include "stdafx.h"
#include "CppUnitTest.h"
#include "\Users\sebastiandv\Documents\GitHub\Programacion2\PreExam\PreExam\DoublyList.h"
#include "\Users\sebastiandv\Documents\GitHub\Programacion2\PreExam\PreExam\DynamicArray.h"
#include "\Users\sebastiandv\Documents\GitHub\Programacion2\PreExam\PreExam\Point2d.h"
#include "\Users\sebastiandv\Documents\GitHub\Programacion2\PreExam\PreExam\String.h"
#include "\Users\sebastiandv\Documents\GitHub\Programacion2\PreExam\PreExam\Projectile.h"
#include <assert.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
	
		TEST_METHOD(TestMethod1)
		{
			// TODO: Agregar aqu� el c�digo de la prueba
		}
		
			// Projectile ----------------------------------------
			TEST_METHOD(Projectile_test)
		{
				Projectile p;

				p.pos_x = 10.0f;
				p.pos_y = 10.0f;

				p.vel_x = 2.0f;
				p.vel_y = 0.0f;

				Point2d<float> current = p.GetCurrentPosition(3.0f);

				Assert::AreEqual((float)16.0f, current.x, 0.00001f);
				Assert::AreEqual((float)10.0f, current.y, 0.00001f);
			}
		
		
		// ArrDyn remove wasted memory ----------------------------------------
		TEST_METHOD(ArrDyn_optimizeMem)
		{
			DynamicArray<int> array(10);

			array.PushBack(1);
			array.PushBack(2);
			array.PushBack(3);

			Assert::AreEqual((unsigned int)10, array.GetCapacity());

			unsigned int wasted = array.RemoveWastedMemory();

			Assert::AreEqual((unsigned int)3, array.GetCapacity());
			Assert::AreEqual((unsigned int)7, wasted);
			Assert::AreEqual((int)1, array[0]);
			Assert::AreEqual((int)2, array[1]);
			Assert::AreEqual((int)3, array[2]);
		}

		/*
		// P2List delete few nodes ----------------------------------------
		TEST_METHOD(p2List_delNodes_mid)
		{
			DoublyList<int> l;

			l.Add(1);
			l.Add(2);
			l.Add(3);
			l.Add(4);

			l.delNodes(1, 2);

			Assert::AreEqual((int)1, l.start->data);
			Assert::AreEqual((int)4, l.end->data);
			Assert::AreEqual((unsigned int)2, l.Count());
		}

		// P2List delete few nodes ----------------------------------------
		TEST_METHOD(p2List_delNodes_begin)
		{
			DoublyList<int> l;

			l.Add(1);
			l.Add(2);
			l.Add(3);
			l.Add(4);

			l.delNodes(0, 3);

			Assert::AreEqual((int)4, l.start->data);
			Assert::AreEqual((int)4, l.end->data);
			Assert::AreEqual((unsigned int)1, l.Count());
		}

		// P2List delete few nodes ----------------------------------------
		TEST_METHOD(p2List_delNodes_end)
		{
			DoublyList<int> l;

			l.Add(1);
			l.Add(2);
			l.Add(3);
			l.Add(4);

			l.delNodes(2, 100);

			Assert::AreEqual((int)1, l.start->data);
			Assert::AreEqual((int)2, l.end->data);
			Assert::AreEqual((unsigned int)2, l.Count());
		}
		
		// String prefix ----------------------------------------
		TEST_METHOD(String_prefix)
		{
			String a("1234567890");
			String b(50);
			b = "hola";

			a.prefix(b);
			b.prefix("1234567890");

			Assert::AreEqual(strcmp(a.GetString(), "hola1234567890"), 0);
			Assert::AreEqual(strcmp(b.GetString(), "1234567890hola"), 0);
		}
		*/
	};
}