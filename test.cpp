#define _CRT_SECURE_NO_WARNINGS 1

#include"AMGraph.h"
#include"ATGraph.h"

int main()
{
	/*AMGraph G(5, 6);
	G.DFSearch('E')*/;
	/*int TD = G.TDnum('A');
	int TD2 = G.TDnum('B');
	int TD3 = G.TDnum('C');*/
	ATGraph G(5, 6);
	G.BFSearch('A');
	return 0;
}