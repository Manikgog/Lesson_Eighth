#ifndef _NODE_H_
#define _NODE_H_

class Node
{
private:
	int _data;
	
public:
	Node* _next;
	Node* _prev;

	Node(int data);
	int GetData();


};

#endif // !_NODE_H_

