#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    node * p, * left, * right;
    int number;
};

class BST
{
public:
    BST();
    ~BST();
    bool insert(node * n);
    bool erase(int number);
    void postorder(node * r);
    void inorder(node * r);
    int BSThigh();
    node * BSTrt();
    node * find(int number);
    node * succ(node * x);
    node * pred(node * x);
    node * max(node * r);
    node * min(node * r);

private:
    node * root;
    int h;
};

BST::BST()
{
    root = new node;
    root=NULL;
    h=0;
}

BST::~BST()
{
    BST::postorder(root);
    delete root;
}

void BST::postorder(node * r)
{
    if (r == NULL) return;
    postorder(r->left);
    postorder(r->right);
    if (r==root) return;
    (r->p)->left=NULL;
    (r->p)->right=NULL;
    free(r);
}

void BST::inorder(node * r)
{
    if (r->left!=NULL) inorder(r->left);
    cout<<r->number<<" ";
    if (r->right!=NULL) inorder(r->right);
}

int BST::BSThigh()
{
    return h;
}

bool BST::insert(node * n)
{
    node * y = NULL, * x = root;

    n->left = n->right = NULL;

    int count=0;

    while(x)
    {
        if(n->number == x->number)
        {
            delete n;
            return false;
        }
        y = x;
        x = (n->number < x->number) ? x->left : x->right;
        count++;
    }

    if (count>h) h=count;

    n->p = y;

    if(!y) root = n;
    else if(n->number < y->number) y->left  = n;
    else y->right = n;

    return true;
}

node * BST::BSTrt()
{
    return root;
}


node * BST::find(int number)
{
    node * x = root;

    while((x) && (x->number != number))
    {
        if (number < x->number) x=x->left;
        else x=x->right;
    }
    return x;
}
node * BST::min(node * r)
{
  node * x = r;

  while(x->left) x = x->left;

  return x;
}

node * BST::max(node * r)
{
  node * x = r;

  while(x->right) x = x->right;

  return x;
}

node * BST::pred(node * x)
{
  if(x->left) return max(x->left);

  node * y;

  do
  {
    y = x;
    x = x->p;
  } while(x && (x->right != y));

  return x;
}

node * BST::succ(node * x)
{
  if(x->right) return min(x->right);

  node * y;

  do
  {
    y = x;
    x = x->p;
  } while(x && (x->left != y));

  return x;
}

bool BST::erase(int number)
{
    node * x = BST::find(number);
    node * y;
    if (x==NULL) return false;

    // (1)
    if (x->left == NULL && x->right == NULL)
    {
        if (x->number > (x->p)->number)
            (x->p)->right=NULL;
        else
            (x->p)->left=NULL;

        delete x;
    }

    // (2)
    else if ( x->left == NULL && x->right != NULL )
    {
        if (x->number > (x->p)->number)
            (x->p)->right=x->right;
        else
            (x->p)->left=x->right;

        delete x;
    }

    else if (x->left != NULL && x->right == NULL)
    {
        if (x->number > x->p->number)
            (x->p)->right=x->left;
        else
           (x->p)->left=x->left;

        delete x;
    }

    // (3)
    else if ( x->left != NULL && x->right != NULL)
    {
        node * sub = BST::pred(x);
        if (sub == NULL)
            sub = BST::succ(x);

        if (sub->p->number <= sub->number)(sub->p)->right=sub->right;
        else (sub->p)->left=sub->left;

        x->number=sub->number;
        delete sub;
    }

    return true;
}

int main()
{
    int n;
    cin>>n;

    BST tree;

    //tworzenie BST
    for (int i=0; i<n; i++)
    {
        node * k;
        k = new node;
        cin>>k->number;
        tree.insert(k);
    }

    tree.inorder(tree.BSTrt());
    cout<<endl<<"Wysokosc: "<<tree.BSThigh()<<endl;

    //wyszukiwanie 0.1n elementów
    for (int i=0; i<0.1*n; i++)
    {
        int k;
        cin>>k;
        node * w=tree.find(k);
        if (w!=NULL) cout<<w->number<<endl;
    }

    //wstawianie 0.1n dodatkowych elementów
    for (int i=0; i<0.1*n; i++)
    {
        node * k;
        k = new node;
        cin>>k->number;
        tree.insert(k);
    }

    tree.inorder(tree.BSTrt());
    cout<<endl;

    //usuwanie 0.1n elementów
    for (int i=0; i<0.1*n; i++)
    {
        int k;
        cin>>k;
        tree.erase(k);
    }

    tree.inorder(tree.BSTrt());
    cout<<endl;


return 0;
}
