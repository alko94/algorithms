#include <iostream>
#include <list>
using namespace std;

const int MAXV = 1000;

list <int> nast[MAXV+1], q;

void Euler(int v)
{
  while(!nast[v].empty())
  {
    int i = nast[v].front();
    nast[v].pop_front();
    for(list<int>::iterator it=nast[i].begin(); it!=nast[i].end(); it++)
      if(*it == v)
      {
        nast[i].erase(it);
        break;
      }
    Euler(i);
  }
  q.push_front(v);
}

int main()
{
    int n, m, a, b;
    cin>>n>>m;

    for(int i=1; i<=m; i++)
    {
        cin>>a>>b;
        nast[a].push_back(b);
        nast[b].push_back(a);
    }

    q.clear();
    Euler(1);
    for(list<int>::iterator it = q.begin(); it != q.end(); it++)
        cout<<*it<<" ";

return 0;
}
