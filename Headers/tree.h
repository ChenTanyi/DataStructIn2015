#pragma once

void rotate_left(node* x, node*& root){
	node* y = x->right;
	x->right = y->left;
	if (y->left) y->left->parent = x;
	y->parent = x->parent;
	if (x == root)
		root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else x->parent->right = y;
	y->left = x;
	x->parent = y;
}

void rotate_right(node* x, node*& root){
	node* y = x->left;
	x->left = y->right;
	if (y->right) y->right->parent = x;
	y->parent = x->parent;
	if (x == root)
		root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else x->parent->right = y;
	y->right = x;
	x->parent = y;
}

int height(node* p){return p ? p->height : 0;}

