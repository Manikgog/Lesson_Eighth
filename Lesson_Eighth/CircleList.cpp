#include "CircleList.h"

CircleList::CircleList() 
	: _head(nullptr), _tail(nullptr), _size(0) {}

CircleList::~CircleList()
{
	this->ClearList();
}

void CircleList::AddTail(int data)
{
	Node* newTail = new Node(data);
	_size++;
	if (_head == nullptr)
	{
		_head = newTail;
		_tail = newTail;
		return;
	}
	_tail->_prev = newTail;
	newTail->_next = _tail;
	_head->_next = newTail;
	_tail = newTail;
	_tail->_prev = _head;
}

void CircleList::AddHead(int data)
{
	Node* newHead = new Node(data);
	_size++;
	if (_head == nullptr)
	{
		_head = newHead;
		_tail = newHead;
		return;
	}
	_head->_next = newHead;
	newHead->_prev = _head;
	_head = newHead;
	_head->_next = _tail;
	_tail->_prev = _head;
}

int CircleList::GetSize()
{
	return _size;
}

void CircleList::ShowList()
{
	if (_size == 0)
		return;
	int i = 0;
	for (auto cur = _tail; i != GetSize()  ; cur = cur->_next, ++i)
	{
		std::cout << "Data: " << cur->GetData() << std::endl;
	}
}

Node* CircleList::FindElement(int index)
{
	if (index < 0 || index > _size - 1)
		return nullptr;
	
	Node* nodePtr = _tail;
	while (index != 0)
	{
		nodePtr = nodePtr->_next;
		--index;
	}
	return nodePtr;
}


void CircleList::DeleteElement(int index)
{
	if (_size < 3)
	{
		if (_size == 1)
		{
			if(_head)
				delete _head;
			--_size;
			return;
		}
		Node* ToDeleteElement = FindElement(index);
		if (ToDeleteElement == _head)
		{
			_head = nullptr;
			_head = _tail;
			_tail->_next = nullptr;
			_tail->_prev = nullptr;
			--_size;
			return;
		}
		if (ToDeleteElement == _tail)
		{
			_tail = nullptr;
			_tail = _head;
			_head->_next = nullptr;
			_head->_prev = nullptr;
			--_size;
			return;
		}

		
	}

	if (index == 0)
	{
		Node* cur = _tail;
		cur = cur->_next;
		delete _tail;
		_tail = cur;
		_tail->_prev = _head;
		_head->_next = _tail;
		--_size;
		return;
	}
	else if (index == _size - 1)
	{
		Node* cur = _head;
		cur = cur->_prev;
		delete _head;
		_head = cur;
		_head->_next = _tail;
		_tail->_prev = _head;
		--_size;
		return;
	}
	Node* PrevNode = FindElement(index - 1);
	Node* ToDelete = FindElement(index);
	Node* AfterNode = FindElement(index + 1);
	delete ToDelete;
	PrevNode->_next = AfterNode;
	AfterNode->_prev = PrevNode;
	--_size;
	return;
}

void CircleList::ClearList()
{
	if (_tail)
	{
		auto cur = _tail;
		while (_size > 0)
		{
			cur = cur->_next;
			_tail = cur;
			--_size;
		}
		return;
	}
	return;
}

void CircleList::BubleSort()
{
	int i = 0;
	for (Node* i_tmp = _head; i < _size-1; ++i, i_tmp = i_tmp->_prev)
	{
		int j = 0;
		for (Node* j_tmp = _head->_prev; j < _size; ++j, j_tmp = j_tmp->_prev)
		{
			if (i_tmp->GetData() < j_tmp->GetData())
			{
				i_tmp->operator = (j_tmp);
			}
		}
	}

}