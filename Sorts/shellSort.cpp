#include <iostream>
using namespace std;

int k[8];

void shellsort (int n, int tab[], int ile)
{
    for (int z=ile; z>0; z--)
    {
        for (int i=k[8-z]; i<n; i++)
        {
            int pom=tab[i];
            int j;
            for (j=i; j>=k[8-z] && tab[j-k[8-z]]>pom; j-=k[8-z])
            {
                tab[j] = tab[j-k[8-z]];
            }
            tab[j] = pom;
        }
    }
}

int main()
{
    int n;
    cin>>n;

    k[0]=701;
    k[1]=301;
    k[2]=132;
    k[3]=57;
    k[4]=23;
    k[5]=10;
    k[6]=4;
    k[7]=1;

    int ile;
    if (n<4) ile=1;
    else if (n<10) ile=2;
    else if (n<23) ile=3;
    else if (n<57) ile=4;
    else if (n<132) ile=5;
    else if (n<301) ile=6;
    else if (n<701) ile=7;
    else ile=8;

    int tab[n];
    for (int i=0; i<n; i++) cin>>tab[i];

    shellsort(n, tab, ile);
    for (int i=0; i<n; i++) cout<<tab[i]<<" ";
    cout<<endl;
return 0;
}
