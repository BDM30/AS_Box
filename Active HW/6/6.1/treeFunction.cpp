#include <cstdlib>
#include <iostream>
#include <string.h>
#include "treeFunction.h"

using namespace std;
using treeName::tree;

tree *treeName::addTree(tree *root, tree *newNode, int value) {
	if (!newNode) {
		tree* newNode = new tree;
		newNode->left = nullptr;
		newNode->right = nullptr;
		newNode->value = value;
		if (!root)
			return newNode;
		if (value < root->value)
			root->left = newNode;
		else
			root->right = newNode;
		return newNode;
	}
	if (value < newNode->value)
		addTree(newNode, newNode->left, value);
	else
		addTree(newNode, newNode->right, value);
	return root;
}

//Increase//
void treeName::printInc(tree *root) {
	if (!root)
		return;
	printInc(root->left);
	cout << root->value << " ";
	printInc(root->right);
}

//Free//

tree* treeName::freeMemory(tree *root) {
	if (!root)
		return root;
	if (root->left == root->right)
	{
		delete root;
		return nullptr;
	}
	root->left = freeMemory(root->left);
	root->right = freeMemory(root->right);
	delete root;
	return nullptr;
}

void treeName::printDec(tree *root) {
	if (!root)
		return;
	printDec(root->right);
	cout << root->value << " ";
	printDec(root->left);
}

// удаление //

tree *treeName::delTree(struct tree *root, int key) {
	if (!root)
		return root;
	if (root->value == key) {
		tree *nextNode = nullptr;
		tree *helper = nullptr;
		if (root->right == root->left) {
			delete root;
			return nextNode;
		}
		else
			if (!root->left) {
				nextNode = root->right;
				delete root;
				return nextNode;
			}
		else
			if (!root->right) {
				nextNode = root->left;
				delete root;
				return nextNode;
			}
		else {
			helper = root->right;
			nextNode = root->right;
			while (helper->left) helper = helper->left;
			helper->left = root->left;
			delete root;
			return nextNode;
			}
	}

	if (key > root->value)
		root->right = delTree(root->right, key);
	else
		root->left = delTree(root->left, key);
	return root;
}

// существует ли??
bool treeName::exists(tree *node, int key){
	if (node == nullptr)
		return 0;

	while (node) {
		if (node->value == key)
			return true;
		if (key > node->value)
			node = node->right;
		else
			node = node->left;
	}
	return false;
}

tree *treeName::printAbc(tree *root)
{
	if (!root) {
		cout << " null";
		return root;
	}
	else
		cout << "(" << root->value;
	printAbc(root->left);
	printAbc(root->right);
	cout << ")";
	return root;
}