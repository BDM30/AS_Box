#pragma once

namespace list
{
	struct Node {
		int valueNode;
		Node *next;
	};
	Node *first(int d);
	void addSort(Node **beginNode, Node **endNode, int number);
	Node *find(Node * const beginNode, int number);
	void del(Node **beginNode, Node **endNode, int key);
	bool exist(Node *beginNode, int key);
}