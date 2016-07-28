#include <iostream>
using namespace std;


template <class T> class list
{
    public:

        struct element
        {
            element * next;
            T number;
        };

        list();
        ~list();
        unsigned size();
        void push_front(T a);
        void push_back(T a);
        T pop_front();
        T pop_back();
        bool erase(T p);
        bool find(T a);

    private:

        element * front, * back;
        unsigned counter;
};

template <class T> list<T>::list()
{
    front = back = NULL;
    counter  = 0;
}

template <class T> list<T>::~list()
{
    element * p;

    while(front)
    {
        p = front->next;
        delete front;
        front = p;
    }
}

template <class T> unsigned list<T>::size()
{
    return counter;
}

template <class T> void list<T>::push_front(T a)
{
    element * p = new element;
    p->number=a;
    p->next = front;
    front = p;
    if(!back) back = front;
    counter++;
}

template <class T> void list<T>::push_back(T a)
{
    element * p = new element;
    p->number=a;
    if(back) back->next = p;
    p->next = NULL;
    back = p;
    if(!front) front = back;
    counter++;
}

template <class T> T list<T>::pop_front()
{
    element * p;

    if(front)
    {
        p = front;
        front = front->next;
        if(!front) back = NULL;
        counter--;
        return p->number;
    }
    else return NULL;
}

template <class T> T list<T>::pop_back()
{
    element * p;

    if(back)
    {
        p = back;
        if(p == front) front = back = NULL;
        else
        {
            back = front;
            while(back->next != p) back = back->next;
            back->next = NULL;
        }
        counter--;
        return p->number;
    }
    else return NULL;
}

template <class T> bool list<T>::find(T a)
{
    element * p = new element;
    p->number=a;
    element * p1 = new element;

    if (p->number == front->number) return front->number;
    else
    {
        p1=front;
        while(p1->number != p->number)
        {
            if (!(p1->next)) return NULL;
            p1 = p1->next;
        }
        if(p1!=NULL) return true;
        else return false;
    }
}

template <class T> bool list<T>::erase(T p)
{
    element * p1 = new element;
    element * p2 = new element;
    if(p == front->number) return pop_front();
    else
    {
        p1 = p2 = front;
        bool ok=true;
        while(p1->number != p)
        {
            if (!(p1->next)) {ok=false; break;}
            p1 = p1->next;
            if(p1->number != p) p2 = p2->next;
        }
        if (ok)
        {
            p2->next = p1->next;
            if(!(p1->next)) back = p1;
            counter--;
            return true;
        }
        return false;
    }
}

int main()
{
    int n;
    cin>>n;
    list <int> lista;

    for (int i=0; i<n; i++)
    {
        int p;
        cin>>p;
        lista.push_back(p);
    }

    for (int i=0; i<0.1*n; i++)
    {
        int p;
        cin>>p;
        p=lista.find(p);
        cout<<p<<endl;
    }

    for (int i=0; i<0.1*n; i++)
    {
        int p;
        cin>>p;
        lista.push_back(p);
    }

    for (int i=0; i<0.1*n; i++)
    {
        int l;
        cin>>l;
        l=lista.erase(l);
    }

    unsigned int m = lista.size();
    for (int i=0; i<m; i++)
    {
        int p = lista.pop_front();
        cout<<p<<" ";
    }

    cout<<endl;

return 0;
}
