#include <iostream>

struct Node {
	int val;
  struct Node* left;
  struct Node* right;
};

void peek(struct Node* node);
struct Node* create(int val);
struct Node* insert(struct Node* node, int val);
void insert_ptr(struct Node** node, int val); 	// void insertion with double pointer


int main() {
  std::cout << "binary tree\n";

  const struct Node* node = nullptr;
  node = create(10);
  insert_ptr(&node, 2);
  insert_ptr(&node, 5);
  insert_ptr(&node, 22);
  insert_ptr(&node, 31);
  peek(node);

  return 1;
}



struct Node* create(int val) {
  struct Node* node = new struct Node;
  node->val   = val;
  node->left  = nullptr;
  node->right = nullptr;
  return node;
}

struct Node* insert(struct Node* node, int val) {
  if (node == nullptr) {
    return create(val);
  }

	if (node->val > val) {
	  insert(node->left, val);
	} else {
	  insert(node->right, val);
	}

	return node;
}

void insert_ptr(struct Node** node, int val) {
  if (*node == nullptr) {
  	*node = create(val);
    return;
  }

	if ((*node)->val > val) {
	  insert_ptr(&((*node)->left), val);
	} else {
	  insert_ptr(&((*node)->right), val);
	}
}

void innerPeek(struct Node* node) {
	if (node == nullptr) {
		return;
	}

	innerPeek(node->left);
	std::cout << node->val << " ";
	innerPeek(node->right);
}

void peek(struct Node* node) {
	innerPeek(node);
	std::cout << "\n";
}
