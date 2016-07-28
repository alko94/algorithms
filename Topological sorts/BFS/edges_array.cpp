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
    int tab[m][2];
    int czy[n+1];
    for(int i=1; i<=n; i++) czy[i]=0;
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        tab[i][0]=a;
        tab[i][1]=b;
        czy[b]++;
    }
    list <int> brak;
    for(int i=1; i<=n; i++)
    {
        if(czy[i]==0)
        {
            brak.push_back(i);
            czy[i]=-1;
        }
    }
    while(!brak.empty())
    {
        list <int>::iterator tmp=brak.begin();
        cout<<*tmp<<" ";
        brak.pop_front();
        int i=*tmp;
        for (int j=0; j<m; j++)
        {
            if(tab[j][0]==i)
            {
                czy[tab[j][1]]--;
            }
            if(czy[tab[j][1]]==0)
            {
                brak.push_back(tab[j][1]);
                czy[tab[j][1]]=-1;
            }
        }
    }

return 0;
}
