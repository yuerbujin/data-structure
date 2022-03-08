#include <iostream>
#include "minspanningtree.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
//	const string filePath("test1.txt");
	const string filePath("test2.txt");
	Graph graph(filePath);
	
	Prim(graph);//PrimÀ„∑® 
	Kruskal(graph);//KruskalÀ„∑® 
	
	return 0;
}
