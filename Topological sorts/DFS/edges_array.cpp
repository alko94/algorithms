#include <iostream>
#include <list>
#include <stack>
using namespace std;
stack<int>wynik;
const int MAXN=100000000;
bool odwiedzony[MAXN+1];

void DFS_visit(int i, int tab[][2], int n, int m)
{
    odwiedzony[i]=1;
    for(int j=0; j<m; j++)
        if(tab[j][0]==i)
            if(odwiedzony[tab[j][1]]==0)
                DFS_visit(tab[j][1], tab, n, m);
    wynik.push(i);
}

void DFS(int tab[][2], int n, int m)
{
   for(int i=1; i<n+1; i++) odwiedzony[i]=0;
   for(int i=1; i<n+1; i++) if(!odwiedzony[i])
    {
       DFS_visit(i, tab, n, m);
    }
}

int main()
{
    int n, m;
    cin>>n>>m;
    int tab[m][2];
    int a,b;
    for(int i=0; i<m; i++)
    {
        cin>>a>>b;
        tab[i][0]=a;
        tab[i][1]=b;
    }
    DFS(tab, n, m);
    while(!wynik.empty())
    {
        cout<<wynik.top()<<" ";
        wynik.pop();
    }

return 0;
}
