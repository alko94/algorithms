//BST structure by Konrad Krakowski and Aleksandra Kobus

#include <iostream>
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
	int height; //h

	node(int key): key(key),left(NULL),right(NULL){
		height = 1; //h
	}
};


class BST
{
public:
	node* rt;
	node* x;	//used by removeMax/1 and removeMin/1 methods
	BST() : rt(NULL), x(NULL){}; //initializing x is unneeded but whatever
	~BST(){
		rt = postOrder(rt);
	}
	int whatIsTheHeight();
	node* postOrder(node* root);
	void inOrder(node* root);
	int height(node* root);
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
void BST::printTree(node* root, int n){
    if(root){
		printTree(root->left,n+1);
        cout<< '\n';
        for(int i=0; i<(30-n);++i) cout<<" .";
        cout<<root->key;
        printTree(root->right,n+1);
    }
}
int BST::whatIsTheHeight(){		//h
	return height(rt)-1;	//h
}							//h
node* BST::postOrder(node* root){
	if(root){
		root -> left = postOrder(root -> left);
		root -> right = postOrder(root -> right);
		delete root;
	}
	return NULL;
}
void BST::inOrder(node* root){
	if(root){
		root -> left = postOrder(root -> left);
		cout<<root->key<<" ";
		root -> right = postOrder(root -> right);
    }
}
int BST::height(node* root){		//h
	if (root == NULL)		//h
		return 0;			//h
	return root -> height;	//h
}							//h
node* BST::_insert(node* root, int key){
	if (root == NULL)
		return new node(key);
	else if (key<root -> key)
		root -> left = _insert(root -> left,key);
	else //root -> key>=key
		root -> right = _insert(root -> right,key);
	root -> height = max(height(root -> left),height(root -> right)) +1; //h
	return root;
}
node* BST::findMax(node* root){
	node* r = root;
	while (r -> right) r=r -> right;
	return r;
}
node* BST::findMin(node* root){
	node* r = root;
	while (r -> left) r = r -> left;
	return r;
}
node* BST::_find(node* root, int key){
	node* r = root;
	while (r && r -> key != key)
		if (key < r -> key)
			r = r -> left;
		else
			r = r -> right;
	return r;
}
//x - maksymalny element, y - drzewo z usunietym maksymalnym elementem
node* BST::removeMax(node* root){
	if (!root -> right){
		x = root;
		return root -> left;
	}
	root -> right = removeMax(root -> right); //y
	root -> height = max(height(root -> left),height(root -> right)) +1; //h
	return root;
}
//x - minimalny element, y - drzewo z usunietym minimalnym elementem
node* BST::removeMin(node* root){
	if (!root -> left){
		x = root;
		return root -> right;
	}
	root -> left = removeMax(root -> left); //y
	root -> height = max(height(root -> left),height(root -> right)) +1; //h
	return root;
}
node* BST::_remove(node* root, int key){
	if (root == NULL)
		return NULL;
	if (key<root -> key){
		root -> left = _remove(root -> left,key);
		root -> height = max(height(root -> left),height(root -> right)) +1;//h
		return root;
	} else if(root -> key<key){
		root -> right = _remove(root -> right,key);
		root -> height = max(height(root -> left),height(root -> right)) +1;//h
		return root;
	} else {
		//root -> key == key
		if (root -> left){
			node* y = removeMax(root -> left);
			x -> left = y;
			x -> right = root -> right;
			delete root;
			x -> height = max(height(x -> left),height(x -> right)) +1;//h
			return x;
		} else if (root -> right){
			node* y = removeMin(root -> right);
			x -> left = root -> left;
			x -> right = y;
			delete root;
			x -> height = max(height(x -> left),height(x -> right)) +1;//h
			return x;
		} else {
			delete root;
			return NULL;
		}
	}
}
void BST::remove(int key){
	rt = _remove(rt,key);
}
void BST::insert(int key){
	rt = _insert(rt,key);
}
node* BST::find(int key){
	return _find(rt,key);
}


int main(){
    BST tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(4);
    tree.insert(5);
    tree.insert(6);
    tree.insert(7);
    tree.insert(8);
    tree.insert(9);
    tree.insert(10);
    tree.insert(11);
    tree.insert(12);
    tree.insert(13);
    tree.insert(14);
    tree.insert(15);
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
