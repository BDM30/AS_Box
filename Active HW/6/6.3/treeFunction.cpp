#include <cstdlib>
#include <iostream>
#include "treeFunction.h"

using namespace std;
using treeName::tree;

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

tree *treeName::printAbc(tree *root) {
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

char treeName::height(tree *node) {
	return node ? node->height : 0;
}

int treeName::balanceFactor(tree *node) {
	return height(node->right) - height(node->left);
}

void treeName::updateHeight(tree *node) {
	char heightLeft = height(node->left);
	char heightRight = height(node->right);
	node->height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
}

tree *treeName::turnRight(tree *node) {
	tree* slot = node->left;
	node->left = slot->right;
	slot->right = node;
	updateHeight(node);
	updateHeight(slot);
	return slot;
}

tree *treeName::turnLeft(tree *node) {
	tree* slot = node->right;
	node->right = slot->left;
	slot->left = node;
	updateHeight(node);
	updateHeight(slot);
	return slot;
}

tree *treeName::balance(tree *node) {
	updateHeight(node);
	if (balanceFactor(node) == 2) {
		if (balanceFactor(node->right) < 0)
			node->right = turnRight(node->right);
		return turnLeft(node);
	}
	if (balanceFactor(node) == -2) {
		if (balanceFactor(node->left) > 0)
			node->left = turnLeft(node->left);
		return turnRight(node);
	}
	return node;
}

tree *treeName::insert(tree *node, int key)  {
	if (!node)
		return new tree(key);
	if (key < node->value)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);
	return balance(node);
}

tree *treeName::findMin(tree *node) {
	return node->left ? findMin(node->left) : node;
}

tree *treeName::removeMin(tree *node) {
	if (node->left == nullptr)
		return node->right;
	node->left = removeMin(node->left);
	return balance(node);
}

tree *treeName::remove(tree *node, int key) {
	if (!node)
		return 0;
	if (key < node->value)
		node->left = remove(node->left, key);
	else
		if (key > node->value)
			node->right = remove(node->right, key);
		else {
			tree* slot1 = node->left;
			tree* slot2 = node->right;
			delete node;
			if (!slot2)
				return slot1;
			tree* min = findMin(slot2);
			min->right = removeMin(slot2);
			min->left = slot1;
			return balance(min);
	}
	return balance(node);
}
