#include <iostream>
using namespace std;

void selectionsort (int n, int tab[])
{
    for (int i=0; i<n; i++)
    {
        int k=i;
        for (int j=i+1; j<n; j++)
        {
            if (tab[j]<tab[k]) k=j;
        }
        swap (tab[k], tab[i]);
        for (int i=0; i<n; i++)
        {
            cout<<tab[i]<<" ";
        }
        cout<<endl;
    }

}

int main()
{
    int n;
    cin>>n;
    int tab[n];
    for (int i=0; i<n; i++) cin>>tab[i];
    selectionsort(n, tab);
    for (int i=0; i<n; i++) cout<<tab[i]<<" ";
    cout<<endl;

return 0;
}
