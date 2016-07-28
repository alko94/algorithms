#include <iostream>
using namespace std;

void bubblesort (int n, int tab[])
{
    int n2=n;
    while (n>1)
    {
        for (int i=0; i<n-1; i++)
        {
            if (tab[i]>tab[i+1])
            {
                swap(tab[i+1], tab[i]);
            }
        }
         for (int i=0; i<n2; i++)
        {
            cout<<tab[i]<<" ";

        }
        cout<<endl;
        n--;
    }
}

int main()
{
    int n;
    cin>>n;
    int tab[n];
    for (int i=0; i<n; i++) cin>>tab[i];
    bubblesort(n, tab);
    for (int i=0; i<n; i++) cout<<tab[i]<<" ";
    cout<<endl;

return 0;
}
