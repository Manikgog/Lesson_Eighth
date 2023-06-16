#ifndef _CIRCLELIST_H_
#define _CIRCLELIST_H_
#include "Node.h"
#include <iostream>

class CircleList
{
private:
	Node* _head;
	Node* _tail;
	int _size;

public:
	CircleList();
	~CircleList();
	void AddTail(int data);
	void AddHead(int data);
	void ShowList();
	int GetSize();
	void DeleteElement(int index);
	void ClearList();
	Node* FindElement(int index);
	void BubleSort();
	
};

#endif // !_CIRCLELIST_H_

