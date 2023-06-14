#include <iostream>
#include <locale.h>
#include <Windows.h>
#include "CircleList.h"
#include "Node.h"
int main()
{
	system("chcp 65001");
	system("cls");

	CircleList cl;
	cl.AddHead(1);
	cl.AddHead(2);
	
	cl.ShowList();
	std::cout << std::endl;
	cl.DeleteElement(0);
	cl.ShowList();
	return 0;
}