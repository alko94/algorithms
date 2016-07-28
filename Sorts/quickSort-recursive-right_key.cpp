#include <iostream>
using namespace std;

void quicksort(int tab[], int lewy, int prawy)
{
    int sr;
    if(lewy<prawy)
    {
        sr=prawy;
        for(int i=prawy-1; i>=lewy; i--)
            if(tab[prawy]<tab[i]) swap(tab[--sr], tab[i]);
        swap(tab[sr], tab[prawy]);
        quicksort(tab, lewy, sr-1);
        quicksort(tab, sr+1, prawy);
    }
}

int main()
{
    int n;
    cin>>n;
    int tab[n];
    for (int i=0; i<n; i++) cin>>tab[i];
    quicksort(tab, 0, n-1);
    for (int i=0; i<n; i++) cout<<tab[i]<<" ";
    cout<<endl;

return 0;
}
