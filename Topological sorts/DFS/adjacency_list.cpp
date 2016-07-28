#include <iostream>
#include <list>
#include <stack>
using namespace std;
stack<int>wynik;
const int MAXN=100000000;
bool odwiedzony[MAXN+1];

void DFS_visit(int i, list<int>nast[], int n)
{
    odwiedzony[i]=1;
    for(list<int>::iterator iter=nast[i].begin(); iter != nast[i].end(); iter++)
        if(!odwiedzony[*iter])
            DFS_visit(*iter, nast, n);
    wynik.push(i);
}

void DFS(list<int>nast[], int n)
{
   for(int i=1; i<n+1; i++) odwiedzony[i]=0;
   for(int i=1; i<n+1; i++) if(!odwiedzony[i])
    {
       DFS_visit(i, nast, n);
    }
}

int main()
{
    int n, m;
    cin>>n>>m;
    list<int>nast[n+1];
    int a,b;
    for(int i=0; i<m; i++)
    {
        cin>>a>>b;
        nast[a].push_back(b);
    }
    DFS(nast, n);
    while(!wynik.empty())
    {
        cout<<wynik.top()<<" ";
        wynik.pop();
    }

return 0;
}
