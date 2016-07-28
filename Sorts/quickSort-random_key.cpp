#include <iostream>
#include <cstdlib>
using namespace std;

class stack
{
    public:
        stack(int n);
        ~stack();
        void push(int x);
        int  pop();
        bool isNotEmpty();

    private:
        int w, *s, limit;
};

stack::stack(int n)
{
    limit = n;
    s = new int[n];
    w = 0;
}

stack::~stack()
{
    delete [] s;
}

void stack::push(int x)
{
    if(w<limit) s[w++]=x;
}

int stack::pop()
{
    if(w) return s[--w];
    return -1;
}

bool stack::isNotEmpty()
{
   if (w>0) return true;
   else return false;
}

void quicksort(int n, int tab[])
{
    int lewy=0;
    int prawy=n-1;
    stack stos(n);
    int sr=0;
    while (lewy<prawy || stos.isNotEmpty())
    {
        int sr;
        if(lewy<prawy)
        {
            sr=rand()%(prawy-lewy)+lewy;
            swap(tab[sr], tab[prawy]);
            sr=prawy;
            for(int i=prawy-1; i>=lewy; i--)
                if(tab[prawy]<tab[i]) swap(tab[--sr], tab[i]);
            swap(tab[sr], tab[prawy]);
            if (sr-lewy<prawy-sr)
            {
                stos.push(sr+1);
                stos.push(prawy);
                prawy=sr-1;
            }
            else
            {
                stos.push(lewy);
                stos.push(sr-1);
                lewy=sr+1;
            }
        }
        else
        {
            prawy=stos.pop();
            lewy=stos.pop();
        }
    }
}

int main()
{
    int n;
    cin>>n;
    int tab[n];
    for (int i=0; i<n; i++) cin>>tab[i];
    quicksort(n, tab);
    for (int i=0; i<n; i++) cout<<tab[i]<<" ";
    cout<<endl;

return 0;
}
