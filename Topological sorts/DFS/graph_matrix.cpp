#include <iostream>
#include <list>
#include <stack>
using namespace std;
stack<int>wynik;
const int MAXN=10000;
bool odwiedzony[MAXN+1];

void DFS_visit(int i, int tab[][MAXN+4], int n)
{
    odwiedzony[i]=1;
    int pom=tab[i][1];
    if (pom==0) wynik.push(i);
    else
    {
        while (pom!=tab[i][pom+3])
        {
            if(!odwiedzony[pom])
                DFS_visit(pom, tab, n);
            pom=tab[i][pom+3];
        }
        if (pom==tab[i][pom+3])
        {
            if(!odwiedzony[pom])
                DFS_visit(pom, tab, n);
        }
    }

    if (tab[i][1]!=0) wynik.push(i);
}

void DFS(int n, int tab[][MAXN+4])
{
   for(int i=1; i<n+1; i++) odwiedzony[i]=0;
   for(int i=1; i<n+1; i++) if(!odwiedzony[i])
    {
       DFS_visit(i, tab, n);
    }
}

int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    list <int> nast[n+1];
    list <int> pop[n+1];
    int tab[n+1][MAXN+4];
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        nast[a].push_back(b);
        pop[b].push_back(a);
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

    DFS(n, tab);
    while(!wynik.empty())
    {
        cout<<wynik.top()<<" ";
        wynik.pop();
    }

return 0;
}
