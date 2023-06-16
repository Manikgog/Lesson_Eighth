#include "Node.h"


Node::Node(int data) 
	: _data(data), _next(nullptr), _prev(nullptr) {}

int Node::GetData()
{
	return _data;
}

void Node::operator=(Node* node) 
{
	int tmp = _data;
	_data = node->_data;
	node->_data = tmp;
}
