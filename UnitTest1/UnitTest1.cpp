#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\seeke\source\repos\cyrsach_Macovcov_Maksim\cyrsach_Macovcov_Maksim\cyrsach_Macovcov_Maksim.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(getMaxFlow)
		{
			EdmondsKarp_algorithm graph;
			graph.input("set.txt");
			int ph = graph.maxflow();
			Assert::IsTrue(graph.maxflow() == 5);
		}

		TEST_METHOD(getSize)
		{
			EdmondsKarp_algorithm graph;
			graph.input("set.txt");
			
			Assert::IsTrue(graph.listofvertexes.get_size() == 6);
		}

		TEST_METHOD(isEmpty)
		{
			EdmondsKarp_algorithm graph;
			graph.input("set.txt");

			Assert::IsTrue(graph.listofvertexes.isEmpty() == true);
		}
	};
}
