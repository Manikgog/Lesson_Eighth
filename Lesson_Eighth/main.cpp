#include <iostream>
#include <locale.h>
#include <Windows.h>
#include "CircleList.h"
#include "Node.h"
#include <vector>

char* Foo(char* s)
{
	/*int count = 0;
	for (int i = 0; i < strlen(s)+1; ++i)
	{
		if (s[i] == ' ')
		{
			count++;
		}
	}
	char* str = new char[strlen(s) + 1 - count] {};
	int j = 0;
	for (int i = 0; i < strlen(s); ++i)
	{
		if (s[i] != ' ')
		{
			char c = s[i];
			str[j] = c;
			j++;
		}
	}
	return str;*/

	for (int i = 0; i < strlen(s) + 1; ++i)
	{
		if (s[i] == ' ')
		{
			for (int j = i+1; j < strlen(s) + 1; ++j)
			{
				if (s[j] != ' ')
				{
					static char c_tmp = s[i];
					s[i] = s[j];
					s[j] = c_tmp;
					break;
				}
			}
		}
	}

	for (int i = 0; i < strlen(s) + 1; ++i)
	{
		if (s[i] == ' ')
			s[i] = '\0';
	}
	return s;
}

std::vector<int> foo(std::vector<int>* v, int x)
{
	std::vector<int> res_v;
	int i = 0; 
	int j = v->size() - 1;
	while (i != j)
	{
		if ((*v)[i] + (*v)[j] < x)
		{
			++i;
		}
		if ((*v)[i] + (*v)[j] > x)
		{
			--j;
		}
		if ((*v)[i] + (*v)[j] == x)
		{
			res_v.push_back((*v)[i]);
			res_v.push_back((*v)[j]);
			return res_v;
		}
	}
	return res_v;
}

void foo_(std::vector<int>* v)
{
	std::vector<int> elemToDelete;
	for (int i = 0; i < v->size()-1; ++i)
	{
		for (int j = i+1; j < v->size(); ++j)
		{
			if ((*v)[i] == (*v)[j])
			{
				elemToDelete.push_back(j);
			}

		}
	}
	std::vector<int> tmp;
	for (int i = 0; i < v->size()-1; ++i)
	{
		for (int j = 0; j < v->size(); ++j)
		{
			if ((*v)[i] != elemToDelete[j])
				tmp.push_back((*v)[i]);
		}
	}
	(*v) = tmp;
}

int main()
{
	system("chcp 65001");
	system("cls");

	/*CircleList cl;
	cl.AddHead(2);
	cl.AddHead(1);
	cl.AddHead(9);
	cl.AddHead(6);
	cl.AddHead(7);
	cl.AddHead(8);
	cl.AddHead(10);
	cl.ShowList();
	cl.BubleSort();
	cl.ShowList();*/

	/*char s[] = "          H  e  l  l o                     ";
	std::cout << Foo(s);*/

	std::vector<int> v{ 1,2,1,4,1,6,7,8,9 };
	//std::vector<int> res = foo(&v, 5);
	foo_(&v);
	for (auto& it : v)
	{
		std::cout << it << ' ';
	}

	return 0;
}