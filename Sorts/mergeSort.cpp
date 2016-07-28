#include <iostream>
using namespace std;

void merge(int tab[], int t[], int pocz, int sr, int kon)
{
    for (int i=pocz; i<=kon; i++) t[i]=tab[i];
    int i=pocz;
    int j=sr+1;
    int pom=pocz;
    while (i<=sr && j<=kon)
    {
        if (t[i]<t[j]) tab[pom++]=t[i++];
        else tab[pom++]=t[j++];
    }
    while (i<=sr) tab[pom++]=t[i++];
}


void mergesort(int tab[], int t[], int pocz, int kon)
{
    if (pocz<kon)
    {
        int sr=(pocz+kon)/2;
        mergesort(tab, t, pocz, sr);
        mergesort(tab, t, sr+1, kon);
        merge(tab, t, pocz, sr, kon);
    }
}

int main()
{
    int n;
    cin>>n;
    int tab[n];
    int t[n];
    for (int i=0; i<n; i++) cin>>tab[i];
    mergesort(tab, t, 0, n-1);
    for (int i=0; i<n; i++) cout<<tab[i]<<" ";
    cout<<endl;

return 0;
}
