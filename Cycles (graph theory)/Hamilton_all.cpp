#include <iostream>
#include <list>
#include <vector>
#include <time.h>
using namespace std;

const int MAXV = 1000;

int n;
list <int> nast[MAXV+1]; //graf w postaci listy nastepnikow, wierzcholki etykietowane 1..N
vector <list<int> > q; //wynik
list <int> save; //lista pomocnicza
vector<bool> visited;

void Hamilton(int v)
{
	visited[v] = true;
	save.push_back(v);
	
	if(save.size() < n){
		for(list<int>::iterator it = nast[v].begin(); it!=nast[v].end(); ++it){
			if(!visited[*it]){
				Hamilton(*it);
			}
		}
	}
	else{
		for(list<int>::iterator it = nast[v].begin(); it!=nast[v].end(); ++it){
			if((*it) == save.front()){
				q.push_back(save);
				break;
			}
		}
	}
	save.pop_back();
	visited[v] = false;
}

clock_t timer;

int main()
{
    int m, a, b; //n declared global
    cin>>n>>m;

    for(int i=1; i<=m; i++)
    {
        cin>>a>>b;
        nast[a].push_back(b);
        nast[b].push_back(a);
    }
    
    //start timing
    timer = clock();
    
    visited.clear();
    visited.resize(n+1,false);
    save.clear();
    q.clear();
    Hamilton(1);
    
    //stop timing
    timer = clock()-timer;
    
    //for(vector <list<int> >::iterator solution = q.begin(); solution!=q.end(); ++solution){
    //	cout<<endl;
    //	for(list<int>::iterator it = (*solution).begin(); it != (*solution).end(); it++)
    //	    cout<<*it<<" ";}
	
    cout<<endl<<n<<":time:"<< float(timer)/CLOCKS_PER_SEC << '\t'<<endl;
return 0;
}
