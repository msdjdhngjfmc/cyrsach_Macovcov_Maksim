#include <iostream>
#include "EdKarp.h"

int main()
{


	
		EdmondsKarp_algorithm graph;
		graph.input("set.txt");
		cout << "For this graph maximum flow is: ";
		int ph = graph.maxflow();
		cout << graph.maxflow() << endl;
		return 0;
	
}


