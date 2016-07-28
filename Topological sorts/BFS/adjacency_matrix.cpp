#include <iostream>
#include <queue>
#include <list>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    int tab[n+1][n+1];
    bool odwiedzony[n+1];
    int czy[n+1];
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            tab[i][j]=0;
        }
        odwiedzony[i]=0;
        czy[i]=0;
    }
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        tab[a][b]=1;
        czy[b]++;
    }
    list <int> brak;
    for (int i=1; i<=n; i++)
    {
        if (czy[i]==0)
        {
            brak.push_back(i);
            odwiedzony[i]=1;
            czy[i]=-1;
        }
    }

    while(!brak.empty())
    {
        list <int>::iterator tmp=brak.begin();
        cout<<*tmp<<" ";
        brak.pop_front();
        int p=*tmp;
        for (int i=1; i<=n; i++)
        {
            if(tab[p][i]==1)
            {
                czy[i]--;
            }
            if(czy[i]==0)
            {
                brak.push_back(i);
                czy[i]=-1;
            }
        }
    }

return 0;
}
