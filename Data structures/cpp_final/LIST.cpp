//LIST sturcture by Konrad Krakowski and Aleksandra Kobus
#include <iostream>
using namespace std;
class node{
public:
	int key;
	node* next;
	node(int key) : key(key), next(NULL){};
};

class LIST{
public:
	node* head;
	LIST() : head(NULL) {};
	~LIST(){
        while (head){
			node* toDel = head;
			head = head -> next;
			delete toDel;
		}
	}
	void insert(int key);
	node* findMax();
	node* findMin();
	node* find(int key);
	void remove(int key);
	void printList();
};
void LIST::printList(){
	node* p = head;
	while(p){
		cout<<p->key<<',';
		p = p->next;
	}
}
void LIST::insert(int key){
	node* cur = new node(key);
	if(!head || key < head -> key){
		cur -> next = head;
		head = cur;
	} else {
		node* prev = head;
		while (prev -> next && prev -> next -> key<key) prev = prev -> next;
		if (!prev -> next) prev -> next = cur;
		else {
			cur -> next = prev -> next;
			prev -> next = cur;
		}
	}
}
node* LIST::findMax(){
	node* p = head;
	if (p)
		while (p -> next)
			p = p -> next;
	return p;
}
node* LIST::findMin(){
	return head;
}
node* LIST::find(int key){
	node* p = head;
	while (p && p -> key < key)
		p = p -> next;
	if (p and p -> key == key)
		return p;
	return NULL;
}
void LIST::remove(int key){
	if (head)
		if (head -> key == key){
			node* toDel = head;
			head = head -> next;
			delete toDel;
		} else {
			node* prev = head;
			while (prev -> next && prev -> next -> key<key)
				prev = prev -> next;
			if (prev -> next && prev -> next -> key==key){
				node* toDel = prev -> next;
				prev -> next = prev -> next -> next;
				delete toDel;
			}
		}
}


int main(){
    LIST list;
    list.insert(14);
    list.insert(10);
    list.insert(15);
    list.insert(3);
    list.insert(5);
    list.insert(6);
    list.insert(12);
    list.insert(4);
    list.insert(7);
    list.insert(9);
    list.insert(13);
    list.insert(2);
    list.insert(1);
    list.insert(8);
    list.insert(11);
    list.printList();

    cout<<endl;

    list.remove(6);
    list.remove(4);
    list.remove(8);
    list.remove(1);
    list.remove(3);
    list.remove(2);
    list.remove(7);
    list.remove(9);
    list.remove(5);
    list.printList();

    cout<<endl;

        node* f;
    f = list.find(13);
    if(f) cout<<(f->key)<<", ";
    f = list.find(14);
    if(f) cout<<(f->key)<<", ";
    f = list.find(15);
    if(f) cout<<(f->key)<<", ";
    f = list.find(16);
    if(f) cout<<(f->key)<<", ";
    f = list.find(17);
    if(f) cout<<(f->key)<<", ";
	return 0;
}
