#include <iostream>
#include <list>
#include <vector>
#include <time.h>

using namespace std;

const int MAXV = 1000;

int n;
list <int> nast[MAXV+1];
list <int> q;
list <int> save;
vector<bool> visited;
bool keep_going;

void Hamilton(int v)
{
	visited[v] = true;
	save.push_back(v);

	if(save.size() < n){
		for(list<int>::iterator it = nast[v].begin(); it!=nast[v].end(); ++it){
			if(keep_going & !visited[*it]){
				Hamilton(*it);
			} //else if (!keep_going) break;
		}
	}
	else{
		for(list<int>::iterator it = nast[v].begin(); it!=nast[v].end(); ++it){
			if((*it) == save.front()){
				q = save;
				keep_going = false;
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

    keep_going = true;
    visited.clear();
    visited.resize(n+1,false);
    save.clear();
    q.clear();
    Hamilton(1);

    //stop timing
    timer = clock() - timer;


    for(list<int>::iterator it = q.begin(); it != q.end(); it++)
        cout<<*it<<" ";

	cout<<endl<<n<<":time:"<< float(timer)/CLOCKS_PER_SEC << '\t';
return 0;
}
