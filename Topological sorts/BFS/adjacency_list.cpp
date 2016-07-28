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
    list <int> nast[n+1];
    list <int> pop[n+1];
    int czy[n+1];
    for (int i=1; i<=n; i++) czy[i]=0;
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        nast[a].push_back(b);
        czy[b]++;
        pop[b].push_back(a);
    }
    list <int> brak;
    for (int i=1; i<=n; i++)
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
        int p=*tmp;
        for (list <int> ::iterator it=nast[p].begin(); it!=nast[p].end(); it++)
        {
            int i=*it;
                czy[i]--;
                if (czy[i]==0)
                {
                    brak.push_back(i);
                    czy[i]=-1;
                }

        }
    }

return 0;
}
