#pragma once

namespace list{
	// объ€вили структуру //
	struct Node {
		int value;
		Node *next;
	};
	Node *first(int number);
	void add(Node **endNode, int number);
	Node *find(Node * const beginNode, int number);
	bool remove(Node **beginNode, Node **endNode, int key);

}