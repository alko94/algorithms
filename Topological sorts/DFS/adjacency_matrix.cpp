#include <iostream>
#include <list>
#include <stack>
using namespace std;
stack<int>wynik;
const int MAXN=10000;
bool odwiedzony[MAXN+1];
bool tab[MAXN+1][MAXN+1];

void DFS_visit(int i, int n)
{
    odwiedzony[i]=1;
    int suma=0;
    for(int j=1; j<=n; j++)
        if(tab[i][j]==1 & odwiedzony[j]==0)
            DFS_visit(j, n);
    wynik.push(i);
}

void DFS(int n)
{
   for(int i=1; i<n+1; i++) odwiedzony[i]=0;
   for(int i=1; i<n+1; i++) if(!odwiedzony[i])
    {
       DFS_visit(i, n);
    }
}

int main()
{
    int n, m;
    cin>>n>>m;

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            tab[i][j]=0;
        }
    }

    for(int i=0; i<m; i++)
    {
        int a, b;
        cin>>a>>b;
        tab[a][b]=1;
    }

    DFS(n);
    while(!wynik.empty())
    {
        cout<<wynik.top()<<" ";
        wynik.pop();
    }

return 0;
}
