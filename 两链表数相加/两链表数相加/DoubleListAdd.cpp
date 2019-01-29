#include"DoubleListAdd.h"

Node* test(Node* list)
{
	Node* ll = new Node(list->_element);
	Node* ret = ll;
	for (int i = 2; i < 5; ++i)
	{
		ll->_next = new Node(i);
		ll = ll->_next;
	}
	return ret;
}

int main()
{
	Node list(1);
	Node* ll=test(&list);
	while (ll)
	{
		cout << ll->_element << " ";
		ll = ll->_next;
	}
	cout << endl;
	system("pause");
	return 0;
}