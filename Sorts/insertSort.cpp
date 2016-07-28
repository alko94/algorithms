#include <iostream>
using namespace std;

void insertsort (int n, int tab[])
{
    for (int i=1; i<n; i++)
    {
        int pom=tab[i];
        int j=i-1;
        while (j>=0 && tab[j]>pom)
        {
            tab[j+1]=tab[j];
            j--;
        }
        tab[j+1]=pom;
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
    insertsort(n, tab);
    for (int i=0; i<n; i++) cout<<tab[i]<<" ";
    cout<<endl;

return 0;
}
