struct tnode {
	std::string field;
	struct tnode* left;
	struct tnode* right;
};
// Добавление узлов в дерево
struct tnode* addnode(std::string x, struct tnode* tree) {
	if (tree == nullptr) {
		tree = (struct tnode*)malloc(sizeof(struct tnode));;
		tree->field = x;
		tree->left = nullptr;
		tree->right = nullptr;
	}
	else if (x < tree->field)
		tree->left = addnode(x, tree->left);
	else
		tree->right = addnode(x, tree->right);
	
	return tree;
}

// Удаление поппедева
void freemem(tnode* tree) {
	if (tree != nullptr) {
		freemem(tree->left);
		freemem(tree->right);
		
		free(tree);
	}
}

#include <iostream>

// Обход дерева в префексной форме
void treeprint(tnode* tree) {
	if (tree != nullptr) {
		std::cout << tree->field;
		treeprint(tree->left);
		treeprint(tree->right);
	}
}

// Обход дерева в инфиксной форме
void treeprinti(tnode* tree) {
	if (tree != nullptr) {
		treeprinti(tree->left);
		std::cout << tree->field;
		treeprinti(tree->right);
	}
}

//Обход дерева в инфиксной форме
void treeprintp(tnode* tree) {
	if (tree != nullptr) {
		treeprintp(tree->left);
		treeprintp(tree->right);
		std::cout << tree->field;
	}
}