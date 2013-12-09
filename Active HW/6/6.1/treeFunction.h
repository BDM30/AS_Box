#pragma once

namespace treeName {

	struct tree{
		int value;
		tree *left;
		tree *right;
	};
	tree *addTree(tree *root, tree *r, int value);
	void printInc(tree *root);
	void printDec(tree *root);
	bool exists(tree *r, int key);
	tree *printAbc(tree *root);
	tree *delTree(tree *root, int key);
	tree* freeMemory(tree *root);
}