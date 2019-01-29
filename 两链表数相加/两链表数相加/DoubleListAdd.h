#include<iostream>

using namespace std;

class Node
{
public:
	Node(int element=0,Node* next=nullptr):_element(element),_next(next){}
	int _element;
	Node* _next;
};