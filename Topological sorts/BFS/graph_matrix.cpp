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
    int tab[n+1][n+4];
    int ile[n+1];
    for (int i=1; i<=n; i++)
    {
        ile[i]=0;
    }
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        nast[a].push_back(b);
        pop[b].push_back(a);
        ile[b]++;
    }
    list <int> brak;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n+3; j++)
            tab[i][j]=0;
    }
    for (int i=1; i<=n; i++)
    {
        if (!nast[i].empty())
        {
            list<int>::iterator it=nast[i].begin();
            tab[i][1]=*it;
            int prev=tab[i][1];
            it++;
            for (list <int> :: iterator iter=it; iter!=nast[i].end(); iter++)
            {
                tab[i][prev+3]=*iter;
                prev=*iter;
            }
            tab[i][prev+3]=prev;
        }
        if (!pop[i].empty())
        {
            list<int>::iterator it=pop[i].begin();
            tab[i][2]=*it;
            int prev=tab[i][2];
            it++;
            for (list <int> :: iterator iter=it; iter!=pop[i].end(); iter++)
            {
                int pom=*iter;
                tab[i][prev+3]=-pom;
                prev=*iter;
            }
            tab[i][prev+3]=-prev;
        }
        int pierwszy=0;
        int prev;
        for (int j=4; j<n+4; j++)
        {
            if(tab[i][j]==0 && pierwszy==0)
            {
                pierwszy=j-3;
                prev=j-3;
            }
            else if(tab[i][j]==0)
            {
                tab[i][prev+3]=(j-3)+n;
                prev=j-3;
            }
        }
        tab[i][3]=pierwszy;
        tab[i][prev+3]=prev+n;
    }

    for (int i=1; i<=n; i++)
    {
        if (tab[i][2]==0)
        {
            brak.push_back(i);
        }
    }

    while(!brak.empty())
    {
        list <int>::iterator tmp=brak.begin();
        cout<<*tmp<<" ";
        brak.pop_front();
        for (int i=1; i<=n; i++)
        {
            if (tab[i][*tmp+3]<0)
            {
                tab[i][*tmp+3]=0;
                ile[i]--;
                if (ile[i]==0) brak.push_back(i);
            }
        }
    }




return 0;
}
