//AVL structure by Konrad Krakowski and Aleksandra Kobus
#include <iostream>
#include <stdlib.h>

using namespace std;

int max(int a,int b){
	return a>b?a:b;
}

class node
{
public:
	int key;
	node* left;
	node* right;
	int height;

	node(int key): key(key),left(NULL),right(NULL){
		height = 1;
	}
};


class AVL
{
public:
	node* rt;
	node* x;
	AVL() : rt(NULL), x(NULL){}; //initializing x is unneeded but whatever
	~AVL(){
        rt = postOrder(rt);
	};
	int whatIsTheHeight();
	node* postOrder(node* root);
	void inOrder(node* root);
	int height(node* root);
	int balance(node* root);
	node* rotateLeft(node* root);
	node* rotateRight(node* root);
	node* balanced(node* root);
	node* _insert(node* root, int key);
	node* findMax(node* root);
	node* findMin(node* root);
	node* _find(node* root, int key);
	node* removeMax(node* root);
	node* removeMin(node* root);
	node* _remove(node* root, int key);
	void insert(int key);
	void remove(int key);
	node* find(int key);
	void printTree(node* root, int n);
};

void AVL::printTree(node* root, int n){
    if(root){
		printTree(root->left,n+1);
        cout<< '\n';
        for(int i=0; i<(30-n);++i) cout<<" .";
        cout<<root->key;
        printTree(root->right,n+1);
    }
}

int AVL::whatIsTheHeight(){
	return height(rt)-1;
}
node* AVL::postOrder(node* root){
    if(root){
        root -> left = postOrder(root -> left);
	    root -> right = postOrder(root -> right);
	    delete root;
	}
    return NULL;
}
void AVL::inOrder(node* root){
	if(root){
		root -> left = postOrder(root -> left);
		cout<<root->key<<" ";
		root -> right = postOrder(root -> right);
    }
}
int AVL::height(node* root){
	if (root == NULL)
		return 0;
	return root -> height;
}
int AVL::balance(node* root){
	if (root == NULL)
		return 0;
	return height(root -> right) - height(root -> left);
}
node* AVL::rotateLeft(node* root){
	node* rightAtFirst = root -> right;
	node* transfer = rightAtFirst -> left;

	root -> right = transfer;
	rightAtFirst -> left = root;

	root -> height = max(height(root -> left),height(root -> right)) +1;
	rightAtFirst -> height = max(height(rightAtFirst -> left),height(rightAtFirst -> right)) +1;

	return rightAtFirst;
}
node* AVL::rotateRight(node* root){
	node* leftAtFirst = root -> left;
	node* transfer = leftAtFirst -> right;

	root -> left = transfer;
	leftAtFirst -> right = root;

	root -> height = max(height(root -> left),height(root -> right)) +1;
	leftAtFirst -> height = max(height(leftAtFirst -> left),height(leftAtFirst -> right)) +1;

	return leftAtFirst;
}
node* AVL::balanced(node* root){
	int b = balance(root);
	if (b < -1){
		int b2 = balance(root -> left);
		if (b2 <=0) //LL case
			return rotateRight(root);
		if (b2 == 1){ //LR case
			root -> left = rotateLeft(root -> left);
			return rotateRight(root);
		}
	} if (b>1){
		int b2 = balance(root -> right);
		if (b>=0) //RR case
			return rotateLeft(root);
		if (b==-1){ //RL case
			root -> right = rotateRight(root -> right);
			return rotateLeft(root);
		}
	}
	return root;
}
node* AVL::_insert(node* root, int key){
	if (root == NULL)
		return new node(key);
	else if (key<root -> key)
		root -> left = _insert(root -> left,key);
	else //root -> key>=key
		root -> right = _insert(root -> right,key);
	root -> height = max(height(root -> left),height(root -> right)) +1;
	return balanced(root);
}
node* AVL::findMax(node* root){
	node* r = root;
	while (r -> right) r=r -> right;
	return r;
}
node* AVL::findMin(node* root){
	node* r = root;
	while (r -> left) r = r -> left;
	return r;
}
node* AVL::_find(node* root, int key){
	node* r = root;
	while (r && r -> key != key)
		if (key < r -> key)
			r = r -> left;
		else
			r = r -> right;
	return r;
}
//x - maksymalny element, y - drzewo z usunietym maksymalnym elementem
node* AVL::removeMax(node* root){
	if (!root -> right){
		x = root;
		return root -> left;
	}
	root -> right = removeMax(root -> right); //y
	root -> height = max(height(root -> left),height(root -> right)) +1;
	return balanced(root);
}
//x - minimalny element, y - drzewo z usunietym minimalnym elementem
node* AVL::removeMin(node* root){
	if (!root -> left){
		x = root;
		return root -> right;
	}
	root -> left = removeMax(root -> left); //y
	root -> height = max(height(root -> left),height(root -> right)) +1;
	return balanced(root);
}
node* AVL::_remove(node* root, int key){
	if (root == NULL)
		return NULL;
	if (key<root -> key){
		root -> left = _remove(root -> left,key);
		root -> height = max(height(root -> left),height(root -> right)) +1;
		return balanced(root);
	} else if(root -> key<key){
		root -> right = _remove(root -> right,key);
		root -> height = max(height(root -> left),height(root -> right)) +1;
		return balanced(root);
	} else {
		//root -> key == key
		if (root -> left){
			node* y = removeMax(root -> left);
			x -> left = y;
			x -> right = root -> right;
			delete root;
			x -> height = max(height(x -> left),height(x -> right)) +1;
			return balanced(x);
		} else if (root -> right){
			node* y = removeMin(root -> right);
			x -> left = root -> left;
			x -> right = y;
			delete root;
			x -> height = max(height(x -> left),height(x -> right)) +1;
			return balanced(x);
		} else {
			delete root;
			return NULL;
		}
	}
}
void AVL::insert(int key){
	rt = _insert(rt,key);
}
void AVL::remove(int key){
	rt = _remove(rt,key);
}
node* AVL::find(int key){
	return _find(rt,key);
}


int main(){
    AVL tree;
    tree.insert(14);
    tree.insert(10);
    tree.insert(15);
    tree.insert(3);
    tree.insert(5);
    tree.insert(6);
    tree.insert(12);
    tree.insert(4);
    tree.insert(7);
    tree.insert(9);
    tree.insert(13);
    tree.insert(2);
    tree.insert(1);
    tree.insert(8);
    tree.insert(11);
    tree.printTree(tree.rt,0);

    cout<<endl;

    tree.remove(6);
    tree.remove(4);
    tree.remove(8);
    tree.remove(1);
    tree.remove(3);
    tree.remove(2);
    tree.remove(7);
    tree.remove(9);
    tree.remove(5);
    tree.printTree(tree.rt,0);

    cout<<endl<<endl;

    node* f;
    f = tree.find(13);
    if(f) cout<<(f->key)<<", ";
    f = tree.find(14);
    if(f) cout<<(f->key)<<", ";
    f = tree.find(15);
    if(f) cout<<(f->key)<<", ";
    f = tree.find(16);
    if(f) cout<<(f->key)<<", ";
    f = tree.find(17);
    if(f) cout<<(f->key)<<", ";

	return 0;
}

